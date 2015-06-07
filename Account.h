#ifndef Account_h
#define Account_h
#endif

#include <string>
using namespace std;

// define Account class
class Account {
	string AccountNum;
	long double Balance;
public:
	void setAccountNum(string accountNum);
	string getAccountNum();
	void setBalance(long double Balance);
	long double getBalance();
};
