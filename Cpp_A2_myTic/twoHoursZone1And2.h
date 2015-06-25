//
// twoHoursZone1And2.h
//
// derived class
//

#ifndef __TWOHOURSZONE1AND2_H__
#define __TWOHOURSZONE1AND2_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{
	class TwoHoursZone1And2 : public TravelPass
	{

	public:
		TwoHoursZone1And2();
		TwoHoursZone1And2(string theLength, string theZones, float theCost);
		TwoHoursZone1And2(TravelPass &objToCopy);
		virtual ~TwoHoursZone1And2();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}
#endif
