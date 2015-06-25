#include "myTicSystem.h"


	int main(int argc, char* argv[]){

		//Command line args check
		string dataInFile;
		string stationsDataInFile;
		string outFile;

		if (argc != 4){
			cout << "\n Insufficient command line arguments provided.....Exiting." << endl;
			return 0;
		}
		else{
			dataInFile = argv[2];
			stationsDataInFile = argv[1];
			outFile = argv[3];
		}

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		map<string, TravelPass*> travelPassTypes; // To hold the different kinds of travel passes that can be purchased
		map<string, Station*> myTicStations; 
		map<string, User*> users;

		string userInput = ""; //For Option 3
		bool found = false; // For Option 3

		int userSelection = 0;
		
		//Load Files
		try{
			loadUsersAndTravelPasses(dataInFile, travelPassTypes, users);
			loadStations(stationsDataInFile, myTicStations);
		}
		catch (FileException e){
			cout << "\nAn Error has occured whilst attempting to open " << e.getMessage() << ". The program will now exit." << endl;
			return 0;
		}
		catch (InvalidFormatException){
			cout << "\nAn Error has occured whilst attempting to parse data in a file. The program will now exit." << endl;
			return 0;
		}


		// Main Menu Loop
		do{
			
			printMenu();
			cin >> userSelection;

			if (cin.fail()){
				userSelection = 0;
				cin.clear();
			}

			switch (userSelection)
			{
			case 1:
				purchaseTravelPass(users, travelPassTypes, myTicStations);
				break;
			case 2: 
				rechargeMyTic(users);
				break;
			case 3:	
				found = false;
				while (!found){
					cout << "\nWhich user: ";
					cin >> userInput;

					if (users.count(userInput) == 1){
						found = true;
					}
					else{
						cout << "\nInvalid user ID entered." << endl;
						found = false;
					}
				}
				cout << "\nRemaining Credit for user " << userInput << " is $" << users[userInput]->usersMyTic->getCredit() << endl;
				break;
			case 4:
				printUserReports(users);
				break;
			case 5: 
				updateTravelPassPricing(travelPassTypes);
				break;
			case 6:
				printStationStats(myTicStations);
				break;
			case 7: 
				addNewUser(users);
				break;
			case 8: 
				try{
					saveUserData(outFile, travelPassTypes, users);
				}
				catch (FileException e){
					cout << "\nAn error has occured whilst attempting to save data to file " << e.getMessage() << ". Program exiting....." << endl;
					return 0;
				}
				break;
			default:
				cout << "\nInvalid menu option entered. Please try again.\n";
				break;
			}
			clearInputBuffer();
		} while (userSelection != 8);


		//releasing resources

		for (user_itr i = users.begin(); i != users.end(); i++){
			User* item = i->second;
			delete item;
		}

		for (pass_itr i = travelPassTypes.begin(); i != travelPassTypes.end(); i++){
			TravelPass* item = i->second;
			delete item;
		}

		for (station_itr i = myTicStations.begin(); i != myTicStations.end(); i++){
			Station* item = i->second;
			delete item;
		}

		return 0;
	}


	
	void loadUsersAndTravelPasses(string filePath, map<string, TravelPass*> &passes, map<string, User*> &Users)throw (FileException, InvalidFormatException){

		string delimiter = ":", dataItem1, dataItem2, dataItem3, dataItem4, dataItem5, currentLine, currentInType = "";
		ifstream infile;

		int endPosition = 0;
		float moneyVal = 0;

		infile.open(filePath.c_str());

		if (infile.fail()){
			throw FileException(filePath);
		}
		else{
			while (getline(infile, currentLine)){
				if (currentLine[0] == '#' && currentLine[1] == 'u'){
					// currentLine is the #user heading
					currentInType = "users";
					continue;
				}
				else if (currentLine[0] == '#' && currentLine[1] == 'p'){
					// currentLine is the #prices heading
					currentInType = "prices";
					continue;
				}
				else if (currentLine == ""){
					//Blank Line - move to next line (if it exists)
					continue;
				}
				else if (currentInType == "users"){
					//Read a User

					endPosition = currentLine.find(delimiter);
					dataItem1 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem2 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem3 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem4 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem5 = currentLine.substr(0, endPosition);

					//Converting credit string to float
					try{
						moneyVal = StringNumberParse<float>(dataItem5);
					}
					catch (InvalidCastException){
						infile.close();
						throw InvalidFormatException();
					}

					User *newUser;

					//Deciding which object to create
					if (dataItem2 == "adult") {
						newUser = new AdultUser(dataItem1, dataItem3, dataItem4);
						newUser->usersMyTic->addCredit(moneyVal);
						Users[dataItem1] = newUser;
					}
					else if (dataItem2 == "junior"){
						newUser = new JuniorUser(dataItem1, dataItem3, dataItem4);
						newUser->usersMyTic->addCredit(moneyVal);
						Users[dataItem1] = newUser;
					}
					else if (dataItem2 == "senior") {
						newUser = new SeniorUser(dataItem1, dataItem3, dataItem4);
						newUser->usersMyTic->addCredit(moneyVal);
						Users[dataItem1] = newUser;
					}
					else {
						infile.close();
						throw InvalidFormatException();
					}
				}
				else if (currentInType == "prices"){
					//Read a TravelPass 

					endPosition = currentLine.find(delimiter);
					dataItem1 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem2 = currentLine.substr(0, endPosition);

					currentLine.erase(0, endPosition + delimiter.length());
					endPosition = currentLine.find(delimiter);
					dataItem3 = currentLine.substr(0, endPosition);

					// Converting pass cost to a float
					try{
						moneyVal = StringNumberParse<float>(dataItem3);
					}
					catch (InvalidCastException){
						infile.close();
						throw InvalidFormatException();
					}

					TravelPass *newPassType;

					//Deciding which object to create
					if (dataItem1 == "2Hour"){
						if (dataItem2 == "Zone1") newPassType = new TwoHoursZone1(dataItem1, dataItem2, moneyVal);
						else newPassType = new TwoHoursZone1And2(dataItem1, dataItem2, moneyVal);
						passes[dataItem1 + ":" + dataItem2] = newPassType;
					}
					else if (dataItem1 == "AllDay"){
						if (dataItem2 == "Zone1") newPassType = new AllDayZone1(dataItem1, dataItem2, moneyVal);
						else newPassType = new AllDayZone1And2(dataItem1, dataItem2, moneyVal);
						passes[dataItem1 + ":" + dataItem2] = newPassType;
					}
					else if (dataItem1 == "Weekly"){
						if (dataItem2 == "Zone1") newPassType = new WeeklyZone1(dataItem1, dataItem2, moneyVal);
						else newPassType = new WeeklyZone1And2(dataItem1, dataItem2, moneyVal);
						passes[dataItem1 + ":" + dataItem2] = newPassType;
					}
					else{
						infile.close();
						throw InvalidFormatException();
					}
				}
				else if (currentInType == ""){
					continue;
					//Unknown Type in 'currentLine' - Error
					infile.close();
					throw InvalidFormatException();
				}
			}
		}

		if (infile.bad()){
			infile.close();
			throw FileException(filePath);
		}

		infile.close();
	}

	
	void loadStations(string filePath, map<string, Station*> &stations)throw (FileException, InvalidFormatException){

		string delimiter = ":", dataItem1, dataItem2, currentLine;
		ifstream infile;

		int endPosition = 0;
		int zoneInt = 0;

		infile.open(filePath.c_str());

		if (infile.fail()){
			throw FileException(filePath);
		}
		else{
			while (getline(infile, currentLine)){
				endPosition = currentLine.find(delimiter);
				dataItem1 = currentLine.substr(0, endPosition);

				currentLine.erase(0, endPosition + delimiter.length());
				endPosition = currentLine.find(delimiter);
				dataItem2 = currentLine.substr(0, endPosition);

				try{
					zoneInt = StringNumberParse<float>(dataItem2);
				}
				catch (InvalidCastException){
					infile.close();
					throw InvalidFormatException();
				}

				Station *newStation = new Station(dataItem1, zoneInt);

				stations[dataItem1] = newStation;
			}
		}

		infile.close();
	}

	void printMenu(){

		cout << "\nOptions:" << endl;
		cout << "1. Buy a Journey for a User" << endl;
		cout << "2. Recharge a MyTic card for a User" << endl;
		cout << "3. Show remaining credit for a User" << endl;
		cout << "4. Print User Reports" << endl;
		cout << "5. Update Pricing" << endl;
		cout << "6. Show Station statistics" << endl;
		cout << "7. Add a new User" << endl;
		cout << "8. Save/Quit\n" << endl;
		cout << "What is your selection: ";
	}

	void saveUserData(string outFileName, map<string, TravelPass*> &passes, map<string, User*> &Users) throw (FileException){
		
		ofstream of;
		of.open(outFileName.c_str(), ios::trunc);

		if (of.fail()){
			throw FileException(outFileName);
		}

		of << "#users\t(last field is initial credit)" << endl;

		for (user_itr i = Users.begin(); i != Users.end(); i++){
			of << *i->second << endl;
		}

		of << "#prices" << endl;

		for (pass_itr i = passes.begin(); i != passes.end(); i++){
			of << *i->second << endl;
		}

		of.close();
	}
	
	template<typename T>
	T StringNumberParse(const string& numberString) throw (InvalidCastException)
	{
		T numVersion;

		stringstream stream(numberString);
		stream >> numVersion;
		if (stream.fail()) {
			throw InvalidCastException(numberString);
		}
		return numVersion;
	}

	void purchaseTravelPass(map<string, User*> &Users, map<string, TravelPass*> &passes, map<string, Station*> &stations){

		string selectedUser = "", beginStation, endStation, toFrom = "from";
		string dateDayStr, dateMonthStr, startTimeStr, endTimeStr;
		time_t depTime, arvlTime;
		bool found = false;
		

		while (!found){
			cout << "\nWhich user: ";
			cin >> selectedUser;

			if (Users.count(selectedUser) == 1){
				found = true;
			}
			else{
				cout << "\nInvalid user ID entered." << endl;
			}
		}

		found = false;

		while (!found){
			if (toFrom == "from"){
				cout << "\nFrom what station: ";
				cin >> beginStation;
				if (stations.count(beginStation) == 1){
					toFrom = "to";
				}
				else{
					cout << "\nInvalid station name entered." << endl;
				}
			}
			else{
				cout << "\nTo what station: ";
				cin >> endStation;
				if (stations.count(endStation) == 1){
					found = true;
				}
				else{
					cout << "\nInvalid station name entered." << endl;
				}
			}
		}
			

		toFrom = "from";
		found = false;

		while (!found){
			if (toFrom == "from"){
					
				cout << "\nDeparture - What month day(enter the day of month): ";
				cin >> dateDayStr;
				cout << "\nDeparture - What month number (1-12): ";
				cin >> dateMonthStr;
				cout << "\nDeparture Time (hhmm): ";
				cin >> startTimeStr;	

				try{
					depTime = getTime(dateDayStr, dateMonthStr, startTimeStr);
				}
				catch (InvalidCastException){
					cout << "\nInvalid date or time value entered" << endl;
					continue;
				}
				toFrom = "to";
			}
			else{
				cout << "\nArrival - What month day(enter the day of month): ";
				cin >> dateDayStr;
				cout << "\nArrival - What month number (1-12): ";
				cin >> dateMonthStr;
				cout << "\nArrival Time (hhmm): ";
				cin >> startTimeStr;

				try{
					arvlTime = getTime(dateDayStr, dateMonthStr, startTimeStr);
				}
				catch (InvalidCastException){
					cout << "\nInvalid date or time value entered" << endl;
					continue;
				}
				found = true;
			}
		}

		try{
			Users[selectedUser]->usersMyTic->addPurchase(passes, depTime, arvlTime, *stations[beginStation], *stations[endStation]);
			cout << "\nCredit remaining for " << Users[selectedUser]->getName() << ": $" << Users[selectedUser]->usersMyTic->getCredit() << endl;
		}
		catch (InsufficientFundsException){
			cout << "\nYou have insufficient funds to purchase a Travel Pass. Please recharge your MyTic." << endl;
		}
	}


	void rechargeMyTic(map<string, User*> &Users){
		
		bool found = false, allowableAmount = true;
		string userInput, user;
		float addAmount;

		while (!found){	
			cout << "\nWhich user: ";
			cin >> userInput;

			if (Users.count(userInput) == 1){
				found = true;
			}
			else{
				cout << "\nInvalid user ID entered." << endl;
			}
		}

		user = userInput;

		do{
			cout << "How much do you want to add to " << user << "'s card: ";
			cin >> userInput;

			try{
				addAmount = StringNumberParse<float>(userInput);
			}
			catch (InvalidCastException){
				allowableAmount = false;
				continue;
			}

			try{
				Users[user]->usersMyTic->addCredit(addAmount);
			}
			catch (CreditLimitExceededException){
				cout << "\nAdding this much credit will exceed the MyTic limit. Please try another amount." << endl;
				allowableAmount = false;
				continue;
			}

			cout << "Added $" << addAmount << " to " << user << "'s card" << endl;
			cout << "Credit remaining for " << user << ": $" << Users[user]->usersMyTic->getCredit() << endl;
			allowableAmount = true;
			
		}while (!allowableAmount);
	}

	void printUserReports(map<string, User*> &Users){
		
		bool found = false;
		string selectedUser;

		while (!found){
			cout << "\nWhich user: ";
			cin >> selectedUser;

			if (Users.count(selectedUser) == 1){
				found = true;
			}
			else{
				cout << "\nInvalid user ID entered." << endl;
			}
		}

		cout << "\nUser Reports:" << endl;
		cout << "Purchases by " << Users[selectedUser]->getName() << endl;
		Users[selectedUser]->usersMyTic->printPurchases();
		cout << endl;
		cout << "Journeys on this Pass:" << endl;
		Users[selectedUser]->usersMyTic->printJourneys();
		
	}

	void updateTravelPassPricing(map<string, TravelPass*> &passes){
		
		string duration, zone, ticketKey, newPriceString;
		bool ticketFound = true, priceValid = true;
		float newPrice;

		do{
			cout << "\nWhich Duration Pass do you want to update: (2)Hour or (A)ll Day: ";
			cin >> duration;
			clearInputBuffer();
			cout << "\nWhich Zone Pass do you want to update: Zone (1) or Zone 1-(2): ";
			cin >> zone;
			clearInputBuffer();

			if (duration[0] == '2' && zone[0] == '1'){
				ticketKey = "2Hour:Zone1";
				ticketFound = true;
			}
			else if (duration[0] == '2' && zone[0] == '2'){
				ticketKey = "2Hour:Zone12";
				ticketFound = true;
			}
			else if (duration[0] == 'A' && zone[0] == '1'){
				ticketKey = "AllDay:Zone1";
				ticketFound = true;
			}
			else if (duration[0] == 'A' && zone[0] == '2'){
				ticketKey = "AllDay:Zone12";
				ticketFound = true;
			}
			else{
				ticketFound = false;
				cout << "\nInvalid ticket options selected. Please try again." << endl;
			}
		} while (!ticketFound);

		
		do{
			cout << "What is the new price: ";
			cin >> newPriceString;

			try{
				newPrice = StringNumberParse<float>(newPriceString);
			}
			catch (InvalidCastException){
				priceValid = false;
				cout << "\nYou have entered an invalid price." << endl;
				continue;
			}
			priceValid = true;
			
		} while (!priceValid);

		passes[ticketKey]->setCost(newPrice);

		cout << "New price of " << passes[ticketKey]->getLength() << " " 
			<< passes[ticketKey]->getZones() << " is $" << passes[ticketKey]->getCost() 
			<< endl;

	}

	void printStationStats(map<string, Station*> &stations){
		
		cout << "\nStation travel statistics:" << endl;

		for (station_itr i = stations.begin(); i != stations.end(); i++){
			i->second->print();
		}

	}

	void addNewUser(map<string, User*> &Users){
		
		string userInputId, userInputType, userInputName, userInputEmail, userTypeName;
		bool clashId = true, validType = true;

		while (clashId){
			cout << "\nChoose an id: ";
			cin >> userInputId;

			if (Users.count(userInputId) == 1){
				clashId = true;
				cout << "Sorry, that id is already in use." << endl;
			}
			else{
				clashId = false;
			}
		}

		cout << "\nUser name: ";
		clearInputBuffer();
		getline(cin, userInputName);

		cout << "\nUser email address: ";
		cin >> userInputEmail;

		User* newUser;

		do{
			cout << "\nWhat type is user: (a)dult, (j)unior, (s)enior? ";
			cin >> userInputType;
			
			if (userInputType[0] == 'a'){
				newUser = new AdultUser(userInputId, userInputName, userInputEmail);
				validType = true;
				userTypeName = "Adult";
				Users[userInputId] = newUser;
			}
			else if (userInputType[0] == 'j'){
				newUser = new JuniorUser(userInputId, userInputName, userInputEmail);
				validType = true;
				userTypeName = "Junior";
				Users[userInputId] = newUser;
			}
			else if (userInputType[0] == 's'){
				newUser = new SeniorUser(userInputId, userInputName, userInputEmail);
				validType = true;
				userTypeName = "Senior";
				Users[userInputId] = newUser;
			}
			else{
				cout << "\nThat is an invalid type of user." << endl;
				validType = false;
			}
		} while (!validType);

		

		cout << "\nCreated a new " << userTypeName << " user with id " << userInputId << endl;
	}
