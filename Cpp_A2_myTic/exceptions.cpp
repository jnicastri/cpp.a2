#include "exceptions.h"

InvalidCastException::InvalidCastException() : message("No Message"){}

InvalidCastException::InvalidCastException(string unCastableString) : message(unCastableString) { }

string InvalidCastException::getMessage() const { return message; }


FileException::FileException() : message("Message"){ }

FileException::FileException(string fileName) : message(fileName){ }

string FileException::getMessage() const { return message; }


InvalidFormatException::InvalidFormatException(){ }


InsufficientFundsException::InsufficientFundsException(){ }
	

CreditLimitExceededException::CreditLimitExceededException() { }

