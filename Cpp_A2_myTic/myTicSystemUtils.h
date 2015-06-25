#ifndef __MYTICSYSTEMUTILS_H__
#define __MYTICSYSTEMUTILS_H__

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
//#include "myTicSystem.h"
#include "exceptions.h"

using namespace std;



namespace MyTicSystemUtilities{

	void clearInputBuffer();
	time_t getTime(string dayStr, string monthStr, string timeStr) throw (InvalidFormatException);
	template<typename T>
	T Util_StringNumberParse(const string& numberString) throw (InvalidCastException);
}

	
#endif
