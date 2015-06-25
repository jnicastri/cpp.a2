#include "adultUser.h"

namespace MyTicUser{

	AdultUser::AdultUser() : User("not set", "no set", "not set"){ 
		
		usersMyTic = new FullMyTic(0, 100);
	
	}

	AdultUser::AdultUser(string newId, string newName, string emailAddress) : User(newId, newName, emailAddress){ 
		
		usersMyTic = new FullMyTic(0, 100);

	}

	AdultUser::~AdultUser(){ 
	
		delete usersMyTic;
	}

	ostream& AdultUser::print(ostream& os) const{

		os << id << ":adult:" << name << ":" << email << ":" << usersMyTic->getCredit();

		return os;

	}
}