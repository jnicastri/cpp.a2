#include "user.h"

namespace MyTicUser{

	User::User() : id("not set"), name("not set"), email("not set"){ }

	User::User(string newId, string newName, string emailAddress) : id(newId), name(newName), email(emailAddress){ }

	User::~User(){

	}

	string User::getId() const{
		return id;
	}

	string User::getEmail() const{
		return email;
	}

	string User::getName() const{
		return name;
	}

	void User::setName(string newUserName){
		name = newUserName;
	}

	void User::setId(string newUserId){
		id = newUserId;
	}

	void User::setEmailAddress(string newUserEmail){
		email = newUserEmail;
	}

	void User::assignUserMyTic(MyTic &newMyTic){
		usersMyTic = &newMyTic;
	}

	ostream& operator <<(ostream& os, const User& passRef){

		return passRef.print(os);
	}

}
