#ifndef __ADULTUSER_H_
#define __ADULTUSER_H_

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

namespace MyTicUser{

	class AdultUser : public User{
	
	public:
		AdultUser();
		AdultUser(string newId, string newName, string emailAddress);
		~AdultUser();
		ostream& print(ostream& os) const;

	};
}

#endif
