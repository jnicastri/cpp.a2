#include "myTicJourney.h"

namespace Journeys{

	MyTicJourney::MyTicJourney() { }

	MyTicJourney::MyTicJourney(Station& start, Station& end, time_t& startTime, time_t& endTime)
		: journeyStart(&start), journeyEnd(&end), journeyStartTime(startTime), journeyEndTime(endTime){ }

	MyTicJourney::~MyTicJourney(){

		//delete journeyStartTime;
		//delete journeyEndTime;
	
	}

	void MyTicJourney::printJourney(){
		
		time_t* time = &journeyStartTime;
		struct tm *_tm = localtime(time);

		cout << journeyStart->getName() << " to " << journeyEnd->getName() << " at "
			<< _tm->tm_hour;
		
		if (_tm->tm_min == 0){
			cout << "00" << endl;
		}
		else{
			cout << _tm->tm_min << endl;
		}
		
	}

	void MyTicJourney::setStartDestination(Station& start){
		journeyStart = &start;
	}

	void MyTicJourney::setEndDestination(Station& end){
		journeyEnd = &end;
	}

	void MyTicJourney::setStartTime(time_t& startTime){
		journeyStartTime = startTime;
	}

	void MyTicJourney::setEndTime(time_t& endTime){
		journeyEndTime = endTime;
	}

	time_t& MyTicJourney::getJourneyStartTime(){
		return journeyStartTime;
	}

	time_t& MyTicJourney::getJourneyEndTime(){
		return journeyEndTime;
	}



}
