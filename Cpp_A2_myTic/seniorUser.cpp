#include "seniorUser.h"

namespace MyTicUser{

	SeniorUser::SeniorUser() : User("not set", "no set", "not set"){
		
		usersMyTic = new SeniorMyTic(0, 100);

	}

	SeniorUser::SeniorUser(string newId, string newName, string emailAddress) : User(newId, newName, emailAddress){ 
	
		usersMyTic = new SeniorMyTic(0, 100);
			
	}

	SeniorUser::~SeniorUser(){
		
		delete usersMyTic;

	}

	ostream& SeniorUser::print(ostream& os) const{

		os << id << ":senior:" << name << ":" << email << ":" << usersMyTic->getCredit();

		return os;
	}
}