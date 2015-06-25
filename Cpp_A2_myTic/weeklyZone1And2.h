#ifndef __WEEKLYZONE1AND2_H__
#define __WEEKLYZONE1AND2_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{

	class WeeklyZone1And2 : public TravelPass
	{

	public:
		WeeklyZone1And2();
		WeeklyZone1And2(string theLength, string theZones, float theCost);
		WeeklyZone1And2(TravelPass &objToCopy);
		virtual ~WeeklyZone1And2();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}
#endif
