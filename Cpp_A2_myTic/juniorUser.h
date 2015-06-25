#ifndef __JUNIORUSER_H_
#define __JUNIORUSER_H_

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

namespace MyTicUser{

	class JuniorUser : public User{

	public:
		JuniorUser();
		JuniorUser(string newId, string newName, string emailAddress);
		~JuniorUser();
		ostream& print(ostream& os) const;
	};
}

#endif
