#ifndef __MYTICJOURNEY_H_
#define __MYTICJOURNEY_H_

#include <iostream>
#include <string>
#include <ctime>
#include "myTicStation.h"

using namespace std;
using namespace MyTicStation;

namespace Journeys{

	class MyTicJourney{
	private:
		Station* journeyStart;
		Station* journeyEnd;
		time_t journeyStartTime;
		time_t journeyEndTime;

	public:
		MyTicJourney();
		MyTicJourney(Station& start, Station& end, time_t &startTime, time_t &endTime);
		~MyTicJourney();
		void printJourney();
		void setStartDestination(Station& start);
		void setEndDestination(Station& end);
		void setStartTime(time_t& startTime);
		void setEndTime(time_t& endTime);
		time_t& getJourneyStartTime();
		time_t& getJourneyEndTime();

	};

}

#endif
