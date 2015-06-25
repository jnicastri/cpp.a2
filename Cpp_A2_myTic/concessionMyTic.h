#ifndef __CONCSMYTIC_H_
#define __CONCSMYTIC_H_

#include <iostream>
#include <string>
#include "myTic.h"

using namespace std;

namespace MyTicBase{

	static const float DISCOUNT_PERCENT = 0.5;

	class ConcessionMyTic : public MyTic{

	public:
		ConcessionMyTic();
		ConcessionMyTic(float theCredit, float theLimit);
		~ConcessionMyTic();
		virtual float getDiscountRate() = 0;
	};

}

#endif
