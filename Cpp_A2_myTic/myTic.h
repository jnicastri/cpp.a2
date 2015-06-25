//
//myTic.h
//
// MyTic class
//

#ifndef __MYTIC_H__
#define __MYTIC_H__

#include <vector>
#include <string>
#include <typeinfo>
#include <map>
#include "myTicJourney.h"
#include "travelPass.h"
#include "travelPass.h"
#include "allDayZone1.h"
#include "allDayZone1And2.h"
#include "twoHoursZone1.h"
#include "twoHoursZone1And2.h"
#include "weeklyZone1.h"
#include "weeklyZone1And2.h"
#include "exceptions.h"


using namespace MyTicTravelPass;
using namespace Journeys;


namespace MyTicBase{
	class MyTic
	{
	protected:
	  float credit; 
	  float limit;
	  vector<TravelPass*> travelPasses;
	  vector<MyTicJourney*> journeys;
  
	public:
	  MyTic();
	  MyTic(float theCredit, float theLimit);
	  virtual ~MyTic(); 

	  static const int TWO_HOURS_TIME = 7200;
	  static const long ONE_WEEK_TIME = 604800;
	  void input();
	  void print();
	  virtual void printPurchases() const = 0;
	  void printJourneys() const;

	  float getCredit() const;
	  float getLimit() const;
	  TravelPass* getLastPass() const;
		
	  void addCredit(float addAmount) throw (CreditLimitExceededException);
	  virtual void addPurchase(map<string, TravelPass*> &passes, time_t &journeyStartTime, time_t &journeyEndTime, Station &startStation, Station &endStation) throw (InsufficientFundsException) = 0;

	};
}
#endif
