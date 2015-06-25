//
// allDayZone1And2.h
//
// derived class
//

#ifndef __ALLDAYZONE1AND2_H__
#define __ALLDAYZONE1AND2_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{

	class AllDayZone1And2 : public TravelPass
	{

	public:
		AllDayZone1And2();
		AllDayZone1And2(string theLength, string theZones, float theCost);
		AllDayZone1And2(TravelPass &objToCopy);
		virtual ~AllDayZone1And2();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}
#endif
