#ifndef __MYTICSTATION_H_
#define __MYTICSTATION_H_

#include <string>
#include <iostream>

using namespace std;

namespace MyTicStation{

	class Station{

	private:
		string name;
		int zone;
		int beginningJourneys;
		int endingJourneys;
	public:
		Station();
		Station(string stationName, int stationZone);
		~Station();

		void setName(string newName);
		void setZone(int newZone);
		void registerJourneyStart();
		void registerJourneyEnd();

		string getName() const;
		void print();
		int getZone() const;

		friend ostream& operator <<(ostream& os, const Station& passRef);
	};

}

#endif
