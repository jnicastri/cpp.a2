//
// travelPass.h
//
// Parent TravelPass class
//


#ifndef __TRAVELPASS_H__
#define __TRAVELPASS_H__

#include <string>
#include <iostream>
#include "myTicSystemUtils.h"
#include "myTicStation.h"

using namespace std;
using namespace MyTicSystemUtilities;
using namespace MyTicStation;

namespace MyTicTravelPass{

	class TravelPass
	{
	protected:
		string length;
		string zones;
		float cost;

	public:
		TravelPass();
		TravelPass(string theLength, string theZones, float theCost);
		TravelPass(TravelPass &passToCopy);
		virtual ~TravelPass();
		virtual void input() = 0;
		virtual ostream& print(ostream& os) const = 0;

		string getLength() const;
		string getZones() const;
		float getCost() const;

		void setCost(float newCost);

		friend ostream& operator <<(ostream& os, const TravelPass& passRef);
		friend istream& operator >>(istream& is, TravelPass& passRef);
	};
}
#endif
