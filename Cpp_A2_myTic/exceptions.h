#ifndef _MYTICEXCEPTIONS_H__
#define _MYTICEXCEPTIONS_H__

#include <iostream>

using namespace std;



	class InvalidCastException{
	public:
		InvalidCastException();
		InvalidCastException(string unCastableString);
		string getMessage() const;

	private:
		string message;
	};

	class FileException{
	public:
		FileException();
		FileException(string fileName);
		string getMessage() const;
	private:
		string message;
	};

	class InvalidFormatException{
	public:
		InvalidFormatException();
	};

	class InsufficientFundsException{
	public:
		InsufficientFundsException();
	};

	class CreditLimitExceededException{
	public:
		CreditLimitExceededException();
	};

#endif
