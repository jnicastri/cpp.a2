#include "myTicStation.h"

namespace MyTicStation{

	Station::Station() : name("No Name"), zone(0), beginningJourneys(0), endingJourneys(0){ }

	Station::Station(string stationName, int stationZone) : name(stationName), zone(stationZone), beginningJourneys(0), endingJourneys(0){ }

	Station::~Station(){ }

	void Station::setName(string newName){
		name = newName;
	}

	void Station::setZone(int newZone){
		zone = newZone;
	}

	string Station::getName() const{
		return name;
	}

	int Station::getZone() const{
		return zone;
	}

	void Station::registerJourneyStart(){ 
		beginningJourneys++; 
	}

	void Station::registerJourneyEnd(){ 
		endingJourneys++; 
	}

	void Station::print(){
		cout << name << ": "
			<< beginningJourneys
			<< " journeys started here, "
			<< endingJourneys
			<< " journeys ended here"
			<< endl;
	}

	ostream& operator <<(ostream& os, const Station& passRef){

		os << passRef.name << ":" << passRef.zone;

		return os;
	}

}