#ifndef User_h
#define User_h
#endif

#include <string>
#include "Account.h"
using namespace std;

// defines User class
class User {
	string firstname;
	string username;
	string password;
	bool logged;
public:
	User();
	Account CheckingAcc;
	Account SavingAcc;
	void setFirstname(string first);
	string getFirstname();
	void setUsername(string usern);
	string getUsername();
	void setPassword(string pass);
	string getPassword();
	void setLogged(bool log);
	bool getLogged();
};
