#include "myTic.h"

namespace MyTicBase{

	MyTic::MyTic() : credit(0), limit(100) { }

	MyTic::MyTic(float theCredit, float theLimit)
	: credit(theCredit), limit(theLimit) { }

	MyTic::~MyTic(){

	}


	void MyTic::input(){
	
		float newLimit, newCredit;

		cout << "\nEnter a new credit amount: $";
		cin >> newCredit;
		clearInputBuffer();
		cout << "\n";

		cout << "\nEnter a new limit amount: $";
		cin >> newLimit;
		clearInputBuffer();
		cout << "\n";

		credit = newCredit;
		limit = newLimit;

	}


	void MyTic::print(){
	
		cout << "Credit = $" << getCredit() << ", Limit = $" << getLimit() << endl;

	}

	void MyTic::printJourneys() const{
		
		int vSize = journeys.size();
		char bullet = 'a';

		if (vSize != 0){
			for (int i = 0; i < vSize; i++){
				cout << bullet << ". ";
				journeys[i]->printJourney();
				bullet++;
			}
		}
		else{
			cout << "No Journeys yet" << endl;
		}

	}

	float MyTic::getCredit() const{

		return credit;

	}

	float MyTic::getLimit() const{

		return limit;

	}

	TravelPass* MyTic::getLastPass() const{

		int vSize = travelPasses.size();

		if (vSize == 0){
			return 0;
		}
		else{
			return travelPasses[vSize - 1];
		}
	}

	void MyTic::addCredit(float addAmount) throw (CreditLimitExceededException){

		if (addAmount + credit > limit){
			throw CreditLimitExceededException();
		}

		credit += addAmount;

	}

}
