//
// twoHoursZone1.h
//
// derived class
//

#ifndef __TWOHOURSZONE1_H__
#define __TWOHOURSZONE1_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{

	class TwoHoursZone1 : public TravelPass
	{

	public:
		TwoHoursZone1();
		TwoHoursZone1(string theLength, string theZones, float theCost);
		TwoHoursZone1(TravelPass &objToCopy);
		virtual ~TwoHoursZone1();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}
#endif
