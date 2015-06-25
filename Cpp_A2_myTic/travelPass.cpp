#include "travelPass.h"

namespace MyTicTravelPass{

	TravelPass::TravelPass() :length("Not Set"), zones("Not Set"), cost(0){ }


	TravelPass::TravelPass(string theLength, string theZones, float theCost)
		: length(theLength), zones(theZones), cost(theCost){ }

	TravelPass::TravelPass(TravelPass &passToCopy)
		: length(passToCopy.length), zones(passToCopy.zones), cost(passToCopy.cost) { }

	TravelPass::~TravelPass(){ 
	
	}


	string TravelPass::getLength() const{

		return length;

	}

	string TravelPass::getZones() const{

		return zones;

	}

	float TravelPass::getCost() const{

		return cost;

	}


	void TravelPass::setCost(float newCost){

		cost = newCost;

	}


	// Overloaded operators definitions
	ostream& operator <<(ostream& os, const TravelPass& passRef){

		return passRef.print(os);
	}

	istream& operator >>(istream& is, TravelPass& passRef){

		string inLength, inZone;
		float inCost;

		is >> inLength;
		is >> inZone;
		is >> inCost;


		passRef.length = inLength;
		passRef.zones = inZone;
		passRef.cost = inCost;

		return is;
	}
}