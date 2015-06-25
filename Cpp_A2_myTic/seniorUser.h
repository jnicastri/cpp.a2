#ifndef __SENIORUSER_H_
#define __SENIORUSER_H_

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

namespace MyTicUser{

	class SeniorUser : public User{

	public:
		SeniorUser();
		SeniorUser(string newId, string newName, string emailAddress);
		~SeniorUser();
		ostream& print(ostream& os) const;

	};
}

#endif
