/*
CSCI2400 - Fall 2015

App allows a user to login.Data is gathered from text file.
Then allows them to withdraw, deposit, transfer funds, 
account summary. All through acommandline menu similar to 
an ATM.

Account.cpp
Account.h
Bank.cpp
Bank.h
User.h
User.cpp
Main.cpp
BankData.txt
makefile

login data:
Username: Dan01
Password: password
*/

#include "Bank.h" 

int main(){

	//create default user
	User user1;
	//crease bank object
	Bank bank;
	//pass user to the bank object
	bank.bankMainMenu(user1);
}