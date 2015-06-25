#include "twoHoursZone1And2.h"

namespace MyTicTravelPass{

	TwoHoursZone1And2::TwoHoursZone1And2() : TravelPass("2 Hour", "Zones 1 and 2", 0){ }

	TwoHoursZone1And2::TwoHoursZone1And2(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost){ }

	TwoHoursZone1And2::TwoHoursZone1And2(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	TwoHoursZone1And2::~TwoHoursZone1And2(){ }

	// This function allows you to set the instance variables manually,
	// or override the existing values
	void TwoHoursZone1And2::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& TwoHoursZone1And2::print(ostream& os) const{

		os << "2Hour:Zone12:" << cost;

		return os;

	}

}