#include "User.h"

// Constructor for User Class sets default user to not Logged in
User::User(){
	logged = false;
}

// getters and setters 
void User::setFirstname(string first){
	firstname = first;
}
string User::getFirstname(){
	return firstname;
}
void User::setUsername(string usern){
	username = usern;
}
string User::getUsername(){
	return username;
}
void User::setPassword(string pass){
	password = pass;
}
string User::getPassword(){
	return password;
}
void User::setLogged(bool log){
	logged = log;
}
bool User::getLogged(){
	return logged;
}