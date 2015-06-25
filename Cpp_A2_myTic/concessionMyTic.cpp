#include "concessionMyTic.h"

namespace MyTicBase{
	
	ConcessionMyTic::ConcessionMyTic() : MyTic(0, 0){ }

	ConcessionMyTic::ConcessionMyTic(float theCredit, float theLimit) : MyTic(theCredit, theLimit) { }

	ConcessionMyTic::~ConcessionMyTic(){ }

}
