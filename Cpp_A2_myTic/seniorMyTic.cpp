#include "seniorMyTic.h"

namespace MyTicBase{

	SeniorMyTic::SeniorMyTic() : ConcessionMyTic(0, 0){ }

	SeniorMyTic::SeniorMyTic(float theCredit, float theLimit) : ConcessionMyTic(theCredit, theLimit){ }

	SeniorMyTic::~SeniorMyTic(){
	
		int passSize = travelPasses.size();
		int journeySize = journeys.size();

		for (int i = 0; i < passSize; i++){
			delete travelPasses[i];
		}

		for (int i = 0; i < journeySize; i++){
			delete journeys[i];
		}
	}

	float SeniorMyTic::getDiscountRate(){

		return DISCOUNT_PERCENT;
	}

	void SeniorMyTic::printPurchases() const{

		int count = 1, vSize = travelPasses.size();

		if (vSize != 0){
			for (int i = 0; i < vSize; i++){
				cout << count << ". "
					<< travelPasses[i]->getLength()
					<< " " << travelPasses[i]->getZones()
					<< " Senior Travel Pass purchased for $" << travelPasses[i]->getCost()
					<< endl;
				count++;
			}
		}
		else{
			cout << "No purchases yet" << endl;
		}

	}

	void SeniorMyTic::addPurchase(map<string, TravelPass*> &passes, time_t &journeyStartTime, time_t &journeyEndTime, Station &startStation, Station &endStation) throw (InsufficientFundsException){

		TravelPass* newTravelPass = 0;

		bool needNewTicket = true;
		bool upgrade = false;

		if (journeys.size() == 0){
			if ((difftime(journeyEndTime, journeyStartTime) > TWO_HOURS_TIME) && (endStation.getZone() == 1)){
				newTravelPass = new AllDayZone1(*passes["AllDay:Zone1"]);
			}
			else if ((difftime(journeyEndTime, journeyStartTime) > TWO_HOURS_TIME) && (endStation.getZone() == 2)){
				newTravelPass = new AllDayZone1And2(*passes["AllDay:Zone12"]);
			}
			else if ((difftime(journeyEndTime, journeyStartTime) <= TWO_HOURS_TIME) && (endStation.getZone() == 1)){
				newTravelPass = new TwoHoursZone1(*passes["2Hour:Zone1"]);
			}
			else{
				newTravelPass = new TwoHoursZone1And2(*passes["2Hour:Zone12"]);
			}
		}
		else{
			int tpSize = travelPasses.size();
			TravelPass* lastPurchase = travelPasses[tpSize - 1];

			int jSize = journeys.size();
			MyTicJourney* lastJourney = journeys[jSize - 1];

			TwoHoursZone1* thz1 = dynamic_cast<TwoHoursZone1*>(lastPurchase);
			TwoHoursZone1And2* thz1a2 = dynamic_cast<TwoHoursZone1And2*>(lastPurchase);
			AllDayZone1* adz1 = dynamic_cast<AllDayZone1*>(lastPurchase);

			struct tm* temp;
			temp = localtime(&journeyStartTime);
			struct tm jStartInfo = *temp;
			temp = localtime(&lastJourney->getJourneyStartTime());
			struct tm pTStartInfo = *temp;


			if (thz1 && startStation.getZone() == 1 && endStation.getZone() == 1){
				if (difftime(journeyEndTime, (lastJourney->getJourneyStartTime() + TWO_HOURS_TIME)) < 0){
					needNewTicket = false;
				}
				else{
					if ((passes["2Hour:Zone1"]->getCost() + lastPurchase->getCost()) < passes["AllDay:Zone1"]->getCost()){
						newTravelPass = new TwoHoursZone1(*passes["2Hour:Zone1"]);
					}
					else{
						//upgrade previous ticket to AllDay Zone1
						float alreadyPaid = lastPurchase->getCost();
						float diff = passes["AllDay:Zone1"]->getCost() - alreadyPaid;
						newTravelPass = new AllDayZone1(*passes["AllDay:Zone1"]);
						newTravelPass->setCost(diff);
						upgrade = true;
					}
				}
			}
			else if (thz1a2){
				if (difftime(journeyEndTime, (lastJourney->getJourneyStartTime() + TWO_HOURS_TIME)) < 0){
					needNewTicket = false;
				}
				else{
					if ((passes["2Hour:Zone12"]->getCost() + lastPurchase->getCost()) < passes["AllDay:Zone12"]->getCost()){
						newTravelPass = new TwoHoursZone1(*passes["2Hour:Zone12"]);
					}
					else{
						//upgrade previous ticket to AllDay Zone1ANd2
						float alreadyPaid = lastPurchase->getCost();
						float diff = passes["AllDay:Zone12"]->getCost() - alreadyPaid;
						newTravelPass = new AllDayZone1And2(*passes["AllDay:Zone12"]);
						newTravelPass->setCost(diff);
						upgrade = true;
					}
				}
			}
			else if (adz1 && startStation.getZone() == 1 && endStation.getZone() == 1){
				if (pTStartInfo.tm_mday == jStartInfo.tm_mday){
					needNewTicket = false;
				}
				else{
					if (difftime(journeyEndTime, journeyStartTime) < TWO_HOURS_TIME){
						newTravelPass = new TwoHoursZone1(*passes["2Hour:Zone1"]);
					}
					else{
						newTravelPass = new AllDayZone1(*passes["AllDay:Zone1"]);
					}
				}
			}
			else{
				if ((pTStartInfo.tm_mday == jStartInfo.tm_mday) && (pTStartInfo.tm_mon == jStartInfo.tm_mon)){
					needNewTicket = false;
				}
				else{
					if (difftime(journeyEndTime, journeyStartTime) < TWO_HOURS_TIME){
						newTravelPass = new TwoHoursZone1And2(*passes["2Hour:Zone12"]);
					}
					else{
						newTravelPass = new AllDayZone1And2(*passes["AllDay:Zone12"]);
					}
				}
			}
		}

		TravelPass* lastPassRef = getLastPass();

		if (!needNewTicket){
			cout << "\nCurrent "
				<< lastPassRef->getLength()
				<< " " << lastPassRef->getZones()
				<< " pass is still valid."
				<< endl;
		}
		else{

			if (newTravelPass->getCost() > credit){
				delete newTravelPass;
				throw InsufficientFundsException();
			}

			float discountAmount = (newTravelPass->getCost() * DISCOUNT_PERCENT);
			newTravelPass->setCost(newTravelPass->getCost() - discountAmount);

			struct tm* journeyDay;
			journeyDay = localtime(&journeyStartTime);
			if (journeyDay->tm_wday == SUNDAY){
				newTravelPass->setCost(0);
			}

			credit -= newTravelPass->getCost();
			travelPasses.push_back(newTravelPass);

			if (upgrade){
				cout << "\n" << lastPassRef->getLength()
					<< " Travel Pass upgraded to "
					<< newTravelPass->getLength()
					<< " pass for $"
					<< newTravelPass->getCost()
					<< endl;
			}
			else{
				cout << "\n" << newTravelPass->getLength()
					<< " " << newTravelPass->getZones()
					<< " Travel Pass purchased for $"
					<< newTravelPass->getCost()
					<< endl;
			}
		}

		MyTicJourney *journey = new MyTicJourney(startStation, endStation, journeyStartTime, journeyEndTime);
		startStation.registerJourneyStart();
		endStation.registerJourneyEnd();
		journeys.push_back(journey);

	}
}
