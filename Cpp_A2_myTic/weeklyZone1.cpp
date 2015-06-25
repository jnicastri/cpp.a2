#include "weeklyZone1.h"

namespace MyTicTravelPass{

	WeeklyZone1::WeeklyZone1() : TravelPass("Weekly", "Zone 1", 0){ }

	WeeklyZone1::WeeklyZone1(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost){ }

	WeeklyZone1::WeeklyZone1(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	WeeklyZone1::~WeeklyZone1(){ }

	// This function allows you to set the instance variables manually,
	// or override the existing values
	void WeeklyZone1::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& WeeklyZone1::print(ostream& os) const{

		os << "Weekly:Zone1:" << cost;

		return os;

	}
}