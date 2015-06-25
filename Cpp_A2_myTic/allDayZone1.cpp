#include "allDayZone1.h"

namespace MyTicTravelPass{

	AllDayZone1::AllDayZone1() : TravelPass("All Day", "Zone 1", 0){ }

	AllDayZone1::AllDayZone1(string theLength, string theZones, float theCost)
					: TravelPass(theLength, theZones, theCost){ }

	AllDayZone1::AllDayZone1(TravelPass &objToCopy)
		: TravelPass(objToCopy) { }

	AllDayZone1::~AllDayZone1(){ }

	// This function allows you to set the cost
	void AllDayZone1::input(){

		float newCost;

		cout << "\nEnter a new cost: $";
		cin >> newCost;
		clearInputBuffer();
		cout << "\n";

		setCost(newCost);

	}

	ostream& AllDayZone1::print(ostream& os) const{

		os << "AllDay:Zone1:" << cost;

		return os;

	}

}
