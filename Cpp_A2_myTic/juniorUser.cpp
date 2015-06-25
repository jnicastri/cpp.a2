#include "juniorUser.h"

namespace MyTicUser{

	JuniorUser::JuniorUser() : User("not set", "no set", "not set"){
		
		usersMyTic = new JuniorMyTic(0, 100);

	}

	JuniorUser::JuniorUser(string newId, string newName, string emailAddress) : User(newId, newName, emailAddress){ 
		
		usersMyTic = new JuniorMyTic(0, 100);

	}

	JuniorUser::~JuniorUser(){ 
		
		delete usersMyTic;
			
	}

	ostream& JuniorUser::print(ostream& os) const{

		os << id << ":junior:" << name << ":" << email << ":" << usersMyTic->getCredit();

		return os;
	}
}