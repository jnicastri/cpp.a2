#include "allDayZone1And2.h"

namespace MyTicTravelPass{

	AllDayZone1And2::AllDayZone1And2() : TravelPass("All Day", "Zones 1 and 2", 0){ }

	AllDayZone1And2::AllDayZone1And2(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost){ }

	AllDayZone1And2::AllDayZone1And2(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	AllDayZone1And2::~AllDayZone1And2(){ }

	// This function allows you to set the instance variables manually,
	// or override the existing values
	void AllDayZone1And2::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& AllDayZone1And2::print(ostream& os) const{

		os << "AllDay:Zone12:" << cost;

		return os;

	}
}