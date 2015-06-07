#include "Bank.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

// constructor for Bank class 
Bank::Bank(){

	// creates temp_array to store data from txt file
	string line;
	string temp_array[7];
	int x = 0;

	ifstream f("BankData.txt");
	if (f.is_open()){ 
		while (getline(f, line)){
			stringstream ss(line);
			string word = "";
			while (getline(ss, word, ',')){
				temp_array[x] = word;
				
				x++;
			}
		}
		
		//initializes bank struct to hold data from txt file
		bankData.firstname = temp_array[0];
		bankData.username = temp_array[1];
		bankData.password = temp_array[2];
		bankData.checkingAccN = temp_array[3];
		bankData.checkingBalance = stod(temp_array[4]);
		bankData.savingsAccN = temp_array[5];
		bankData.savingsBalance = stod(temp_array[6]);

		
		f.close();
	}
	else cout << "Unable to open file";



}

void Bank::bankMainMenu(User user1){
	
	// initializes variables
	string user;
	string pass;
	string input;


	//if user logged in go to bank options
	if (user1.getLogged() == true){
		cout << endl;
		cout << "Welcome to the Bank " + user1.getFirstname() << endl;
		cout << endl;
		cout << "1 - Withdraw" << endl;
		cout << endl;
		cout << "2 - Deposit" << endl;
		cout << endl;
		cout << "3 - Transfer Funds" << endl;
		cout << endl;
		cout << "4 - Account Summary" << endl;
		cout << endl;
		cout << "5 - Logout" << endl;
		cout << endl;
		cout << "Please input choice: ";
		cin >> input;
		Bank::bankControl(input, user1);
	}
	else {
		//if user is not logged in prompt them to log in
		while (user1.getLogged() == false){
			cout << endl;
			cout << "Welcome to the Bank" << endl;
			cout << endl;
			cout << "Please log into your Account" << endl;
			cout << endl;
			cout << "Login Data is Dan01/password, case sensitive" << endl;
			cout << endl;
			cout << "Enter Username or [0] to quit: ";
			cin >> user;

			// if user = 0 exit program.
			if (user == "0"){
				exit(0);
			}
			else {
				//if user input = user data from txt file

				if (user == bankData.username) {
					//prompt to enter password
					cout << "Enter Password: ";
					cin >> pass;
					//if pass = password data from txt file 
					if (pass == bankData.password){
						// initializes user with all data from txt file and set user.logged = true
						user1.setFirstname(bankData.firstname);
						user1.setUsername(bankData.username);
						user1.CheckingAcc.setAccountNum(bankData.checkingAccN);
						user1.CheckingAcc.setBalance(bankData.checkingBalance);
						user1.SavingAcc.setAccountNum(bankData.savingsAccN);
						user1.SavingAcc.setBalance(bankData.savingsBalance);
						user1.setLogged(true);

						//once initializes recall bankMainMenu method
						Bank::bankMainMenu(user1);
					}
					else {
						cout << endl; cout << "Password Incorrect" << endl;
					}
				}
				else { cout << endl; cout << "Username is Incorrect" << endl; }
			}
		}
	}

}

// sets user.logged to false and sends back to BankMainMenu
void Bank::bankLogout(User user1){
	user1.setLogged(false);
	Bank::bankMainMenu(user1);
}

//Displays summary of banks accounts and balance. sends user back to main menu
void Bank::bankSummary(User user1){
	cout << endl;
	cout << "Bank Statement for " + user1.getUsername() << endl;
	cout << endl;
	cout << "Checking Account #: " + user1.CheckingAcc.getAccountNum() << endl;
	cout << "Checking Balance: $" + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl; // type cast fix for gcc compiler
	cout << endl;
	cout << "Savings Account #: " + user1.SavingAcc.getAccountNum() << endl;
	cout << "Savings Balance: $" + to_string(static_cast<long double>(user1.SavingAcc.getBalance())) << endl;
	cout << endl;
	Bank::bankMainMenu(user1);
}


//Allows to transfer between Accounts
void Bank::bankTransfer(User user1){
	
	int x = 1;
	string input;
	long double amount = 0;
	// ask user to select what direction of transfer
	while (x == 1){
		cout << endl;
		cout << "Welcome to the Bank " + user1.getFirstname() << endl;
		cout << endl;
		cout << "1 - Transfer from Checking to Savings" << endl;
		cout << endl;
		cout << "2 - Transfer from Savings to Checking" << endl;
		cout << endl;
		cout << "Choose a transfer option or [0] to go Back: ";
		cin >> input;
		
		// go back to Main Menu if input = 0
		if (input == "0"){
			x = 0;
		}
		else {
			// if 1 transfer from checking to savings
			if (input == "1"){
				cout << endl;
				cout << "Checking Account #: " + user1.CheckingAcc.getAccountNum() << endl;
				cout << "Checking Balance: $" + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Savings Account #: " + user1.SavingAcc.getAccountNum() << endl;
				cout << "Savings Balance: $" + to_string(static_cast<long double>(user1.SavingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Enter amount to Transfer from Checking to Savings: ";
				cin >> amount;

				//if amount is greater than 0 and less than checking balance move amount from checking to savings.
				if (amount > 0 && amount <= user1.CheckingAcc.getBalance()){
					user1.SavingAcc.setBalance(user1.SavingAcc.getBalance() + amount);
					user1.CheckingAcc.setBalance(user1.CheckingAcc.getBalance() - amount);
					cout << endl;
					cout << "$" + to_string(static_cast<long double>(amount)) + " was transfered from Checking to Savings" << endl;
				}
				else {
					cout << endl;
					cout << "Invalid input" << endl;
				}
			}
			//if input 2 transfer savings from savings to checking
			else if (input == "2"){
				cout << endl;
				cout << "Savings Account #: " + user1.SavingAcc.getAccountNum() << endl;
				cout << "Savings Balance: $" + to_string(static_cast<long double>(user1.SavingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Checking Account #: " + user1.CheckingAcc.getAccountNum() << endl;
				cout << "Checking Balance: $" + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Enter amount to Transfer from Savings to Checking: ";
				cin >> amount;

				//if amount is greater than 0 and less than savings balance
				if (amount > 0 && amount <= user1.SavingAcc.getBalance()){
					user1.CheckingAcc.setBalance(user1.CheckingAcc.getBalance() + amount);
					user1.SavingAcc.setBalance(user1.SavingAcc.getBalance() - amount);
					cout << endl;
					cout << "$" + to_string(static_cast<long double>(amount)) + " was transfered from Savings to Checking" << endl;
				}
				else {
					cout << endl;
					cout << "Invalid input" << endl;
				}
			}
			else {
				cout << endl;
				cout << "Invalid Input" << endl;
			}
		}
	}
	Bank::bankMainMenu(user1);
}

// Allow user to deposit amount into select account
void Bank::bankDeposit(User user1){
	long double amount;
	string input;
	int x = 1;

	while (x == 1){
		cout << endl;
		cout << "Welcome to the Bank " + user1.getUsername() << endl;
		cout << endl;
		cout << " 1 - Checking" << endl;
		cout << endl;
		cout << " 2 - Savings" << endl;
		cout << endl;
		cout << "Choose Account to Deposit or [0] to go Back: ";
		cin >> input;
		
		//if input = 0 go back to menu
		if (input == "0"){
			x = 0;
		}
		else {
			
			// if input = 1 then deposit into checking 
			if (input == "1"){
				cout << endl;
				cout << "Checking Account #: " + user1.CheckingAcc.getAccountNum() << endl;
				cout << "Checking Balance: $" + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Enter amount to deposit: ";
				cin >> amount;
				user1.CheckingAcc.setBalance(user1.CheckingAcc.getBalance() + amount);
				cout << endl;
				cout << "Amount Deposited" << endl;
				cout << "Checking Balance: $" + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl;
			}
			// if input = 2 then deposit into savings account
			else if (input == "2"){
				cout << endl;
				cout << "Savings Account #: " + user1.SavingAcc.getAccountNum() << endl;
				cout << "Savings Balance: $" + to_string(static_cast<long double>(user1.SavingAcc.getBalance())) << endl;
				cout << endl;
				cout << "Enter amount to deposit: ";
				cin >> amount;
				user1.SavingAcc.setBalance(user1.SavingAcc.getBalance() + amount);
				cout << endl;
				cout << "Amount Deposited" << endl;
				cout << "Savings Balance: $" + to_string(static_cast<long double>(user1.SavingAcc.getBalance())) << endl;
			}
			else {
				cout << endl;
				cout << "Invalid input" << endl;
			}
		}
	}
	Bank::bankMainMenu(user1);
}


// withdraw amount from checking account
void Bank::bankWithdraw(User user1){
	string input;
	long double amount;
	int x = 1;
	while (x == 1){
		cout << endl;
		cout << "Welcome to the Bank " + user1.getFirstname() << endl;
		cout << endl;
		cout << "Checking Account #: " + user1.CheckingAcc.getAccountNum() << endl;
		cout << "Balance: $ " + to_string(static_cast<long double>(user1.CheckingAcc.getBalance())) << endl;
		cout << endl;
		cout << "Enter amount to withdraw or [0] to go Back: ";
		cin >> amount;

		//if amount is less than checking balance and greater than 0 withdraw amount
		if (amount <= user1.CheckingAcc.getBalance() && amount > 0){
			user1.CheckingAcc.setBalance(user1.CheckingAcc.getBalance() - amount);
			cout << endl;
			cout << "You have withdrawn $" + to_string(static_cast<long double>(amount)) << endl;
			cout << "Have a nice day" << endl;
		}
		else if (amount == 0){
			x = 0;
		}
		else {
			cout << endl; cout << "Invalid Amount" << endl;
		}
	}
	Bank::bankMainMenu(user1);
}

// control structure for MainMenu, takes input and routes to proper method
void Bank::bankControl(string input, User user1){
	if (input == "1"){
		Bank::bankWithdraw(user1);
	}
	else if (input == "2"){
		Bank::bankDeposit(user1);
	}
	else if (input == "3"){
		Bank::bankTransfer(user1);
	}
	else if (input == "4"){
		Bank::bankSummary(user1);
	}
	else if (input == "5"){
		Bank::bankLogout(user1);
	}
	else {
		cout << endl;
		cout << "Invalid Input" << endl;
		Bank::bankMainMenu(user1);
	}
}
