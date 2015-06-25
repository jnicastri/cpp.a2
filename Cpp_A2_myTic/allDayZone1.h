//
// allDayZone1.h
//
// derived class
//

#ifndef __ALLDAYZONE1_H__
#define __ALLDAYZONE1_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{
	class AllDayZone1 : public TravelPass
	{

	public:
		AllDayZone1();
		AllDayZone1(string theLength, string theZones, float theCost);
		AllDayZone1(TravelPass &objToCopy);
		virtual ~AllDayZone1();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}

#endif
