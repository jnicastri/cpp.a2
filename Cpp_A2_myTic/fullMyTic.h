#ifndef __FULLMYTIC_H_
#define __FULLMYTIC_H_

#include <iostream>
#include <string>
#include "myTic.h"

using namespace std;

namespace MyTicBase{

	class FullMyTic : public MyTic{
	public:
		FullMyTic();
		FullMyTic(float theCredit, float theLimit);
		~FullMyTic();
		virtual void printPurchases() const;
		virtual void addPurchase(map<string, TravelPass*> &passes, time_t &journeyStartTime, time_t &journeyEndTime, Station &startStation, Station &endStation) throw (InsufficientFundsException);
	};

}

#endif
