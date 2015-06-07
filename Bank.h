#ifndef Bank_h
#define Bank_h
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "User.h"

// define Bank class

class Bank{
	// struct created to store multi-type data from txt file
	struct bankDatas{
		string firstname;
		string username;
		string password;
		string checkingAccN;
		long double checkingBalance;
		string savingsAccN;
		long double savingsBalance;
	} bankData;

public:
	Bank();
	void bankControl(string input, User user);
	void bankMainMenu(User user);
	void bankWithdraw(User user);
	void bankDeposit(User user);
	void bankTransfer(User user);
	void bankSummary(User user);
	void bankLogout(User user);
};
