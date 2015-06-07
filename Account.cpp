#include "Account.h"


// getters and setters
void Account::setAccountNum(string accountNum){
	AccountNum = accountNum;
}

string Account::getAccountNum(){
	return AccountNum;
}

void Account::setBalance(long double balance){
	Balance = balance;
}

long double Account::getBalance(){
	return Balance;
}