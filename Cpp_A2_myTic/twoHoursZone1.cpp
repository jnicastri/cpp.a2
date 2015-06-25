#include "twoHoursZone1.h"

namespace MyTicTravelPass{
	TwoHoursZone1::TwoHoursZone1() : TravelPass("2 Hour", "Zone 1", 0){ }

	TwoHoursZone1::TwoHoursZone1(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost){ }

	TwoHoursZone1::TwoHoursZone1(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	TwoHoursZone1::~TwoHoursZone1(){ }

	// This function allows you to set the instance variables manually,
	// or override the existing values
	void TwoHoursZone1::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& TwoHoursZone1::print(ostream& os) const{

		os << "2Hour:Zone1:" << cost;

		return os;

	}
}