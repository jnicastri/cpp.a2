#ifndef __MYTICSYSTEM_H_
#define __MYTICSYSTEM_H_

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

#include "myTicSystemUtils.h"
#include "myTicStation.h"
#include "exceptions.h"

#include "travelPass.h"
#include "allDayZone1.h"
#include "allDayZone1And2.h"
#include "twoHoursZone1.h"
#include "twoHoursZone1And2.h"
#include "weeklyZone1.h"
#include "weeklyZone1And2.h"

#include "user.h"
#include "adultUser.h"
#include "juniorUser.h"
#include "seniorUser.h"

using namespace std;
using namespace MyTicSystemUtilities;
using namespace MyTicTravelPass;
using namespace MyTicUser;
using namespace MyTicStation;


typedef std::map<string, User*>::iterator user_itr; // For looping through Users map
typedef std::map<string, TravelPass*>::iterator pass_itr; // For looping through TravelPasses map
typedef std::map<string, Station*>::iterator station_itr; //Looping through map of stations

void printMenu();

//This is only here because putting it in myTicSystemUtils.cpp file caused errors!
template<typename T>
T StringNumberParse(const string& numberString) throw (InvalidCastException);

// Loading/Saving operations 
void loadUsersAndTravelPasses(string filePath, map<string, TravelPass*> &passes, map<string, User*> &Users) throw (FileException, InvalidFormatException); // Loads Users & Travel Pass types from input file
void loadStations(string filePath, map<string, Station*> &stations) throw (FileException, InvalidFormatException); //Loads Stations from input file
void saveUserData(string outFileName, map<string, TravelPass*> &passes, map<string, User*> &Users) throw (FileException); //Writes User data, user myTic balance & TravelPasses information to file

// System Operations (menu options)
void purchaseTravelPass(map<string, User*> &Users, map<string, TravelPass*> &passes, map<string, Station*> &stations);
void rechargeMyTic(map<string, User*> &Users);
void printUserReports(map<string, User*> &Users);
void updateTravelPassPricing(map<string, TravelPass*> &passes);
void printStationStats(map<string, Station*> &stations);
void addNewUser(map<string, User*> &Users);

#endif
