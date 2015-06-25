#ifndef __JUNIORMYTIC_H_
#define __JUNIORMYTIC_H_

#include <iostream>
#include <string>
#include "concessionMyTic.h"

using namespace std;

namespace MyTicBase{

	class JuniorMyTic : public ConcessionMyTic{

	public:
		JuniorMyTic();
		JuniorMyTic(float theCredit, float theLimit);
		~JuniorMyTic();
		virtual float getDiscountRate();
		virtual void printPurchases() const;
		virtual void addPurchase(map<string, TravelPass*> &passes, time_t &journeyStartTime, time_t &journeyEndTime, Station &startStation, Station &endStation) throw (InsufficientFundsException);
	};
}

#endif
