#include "weeklyZone1And2.h"

namespace MyTicTravelPass{

	WeeklyZone1And2::WeeklyZone1And2() : TravelPass("Weekly", "Zone 1", 0){ }

	WeeklyZone1And2::WeeklyZone1And2(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost){ }

	WeeklyZone1And2::WeeklyZone1And2(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	WeeklyZone1And2::~WeeklyZone1And2(){ }

	// This function allows you to set the instance variables manually,
	// or override the existing values
	void WeeklyZone1And2::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& WeeklyZone1And2::print(ostream& os) const{

		os << "Weekly:Zone12:" << cost;

		return os;

	}

}