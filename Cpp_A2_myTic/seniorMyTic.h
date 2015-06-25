#ifndef __SENIORMYTIC_H_
#define __SENIORMYTIC_H_

#include <iostream>
#include <string>
#include "concessionMyTic.h"

using namespace std;

namespace MyTicBase{

	class SeniorMyTic : public ConcessionMyTic{

	public:
		SeniorMyTic();
		SeniorMyTic(float theCredit, float theLimit);
		~SeniorMyTic();
		static const int SUNDAY = 0;
		virtual float getDiscountRate();
		virtual void printPurchases() const;
		virtual void addPurchase(map<string, TravelPass*> &passes, time_t &journeyStartTime, time_t &journeyEndTime, Station &startStation, Station &endStation) throw (InsufficientFundsException);
	};
}

#endif
