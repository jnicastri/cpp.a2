#ifndef __WEEKLYZONE1_H__
#define __WEEKLYZONE1_H__

#include <ostream>
#include "travelPass.h"

namespace MyTicTravelPass{
	class WeeklyZone1 : public TravelPass
	{

	public:
		WeeklyZone1();
		WeeklyZone1(string theLength, string theZones, float theCost);
		WeeklyZone1(TravelPass &objToCopy);
		virtual ~WeeklyZone1();
		virtual void input();
		ostream& print(ostream& os) const;

	};
}
#endif
