#ifndef __USER_H_
#define __USER_H_

#include <iostream>
#include <string>
#include "myTic.h"
#include "fullMyTic.h"
#include "juniorMyTic.h"
#include "seniorMyTic.h"

using namespace std;
using namespace MyTicBase;

namespace MyTicUser{

	class User
	{
	public:
		User();
		User(string newId, string newName, string emailAddress);
		virtual ~User();

		MyTic *usersMyTic;
		string getName() const;
		string getEmail() const;
		string getId() const;
		void setName(string newUserName);
		void setId(string newUserId);
		void setEmailAddress(string newUserEmail);
		void assignUserMyTic(MyTic &newMyTic);
		virtual ostream& print(ostream& os) const = 0;

		friend ostream& operator <<(ostream& os, const User& passRef);

	protected:
		string id;
		string name;
		string email;
		
	};
}
#endif
