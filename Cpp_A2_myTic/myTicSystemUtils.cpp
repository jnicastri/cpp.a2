#include "myTicSystemUtils.h"
namespace MyTicSystemUtilities{

	// function to clear the input buffer
	void clearInputBuffer()
	{
		char symbol;
		do
		{
			cin.get(symbol);
		} while (symbol != '\n');
	}


	time_t getTime(string dayStr, string monthStr, string timeStr) throw (InvalidFormatException){

		time_t nowTm;
		struct tm time_tm;
		string hourStr, minsStr;
		int dateDayNum, dateMonthNum, timeNumHour, timeNumMins;
		//int startTimeNum;

		try{
			dateDayNum = Util_StringNumberParse<int>(dayStr);
			dateMonthNum = Util_StringNumberParse<int>(monthStr);
			//startTimeNum = Util_StringNumberParse<int>(timeStr); //Done just to check that timeStr is an int
		}
		catch (InvalidCastException){
			throw InvalidFormatException();
		}

		if (timeStr.length() == 4){
			timeNumHour = Util_StringNumberParse<int>(timeStr.substr(0, 2));
			timeNumMins = Util_StringNumberParse<int>(timeStr.substr(2, 2));
		}
		else if (timeStr.length() == 3){
			timeNumHour = Util_StringNumberParse<int>(timeStr.substr(0, 1));
			timeNumMins = Util_StringNumberParse<int>(timeStr.substr(1, 2));
		}
		else{
			throw InvalidFormatException();
		}

		nowTm = time(NULL);
		time_tm = *localtime(&nowTm);

		time_tm.tm_hour = timeNumHour;
		time_tm.tm_min = timeNumMins;
		time_tm.tm_sec = 0;
		time_tm.tm_mday = dateDayNum;
		time_tm.tm_mon = dateMonthNum - 1;

		return mktime(&time_tm);

	}

	template<typename T>
	T Util_StringNumberParse(const string& numberString) throw (InvalidCastException)
	{
		T numVersion;

		stringstream stream(numberString);
		stream >> numVersion;
		if (stream.fail()) {
			throw InvalidCastException(numberString);
		}
		return numVersion;
	}

}
