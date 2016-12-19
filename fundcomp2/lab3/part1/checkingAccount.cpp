//David Durkin
//Fund Comp II
//checkingAccount.cpp

#include "CheckingAccount.h"
#include <iostream>
using namespace std;

//Default Constructor
CheckingAccount::CheckingAccount(){
	maxWithdrawal = 500;
	accountNum = 1;
}

//Constructor with parameters along with base class constructor implementation
CheckingAccount::CheckingAccount(double maxIn, int accountIn, string inName, int bootyIn, double valueIn) : BankAccount(inName, bootyIn, valueIn){
	maxWithdrawal = maxIn;
	accountNum = accountIn;
}

//Print function
void CheckingAccount::print(){

	cout << "In " << getName() << "'s checking account, the max withdrawal is " << maxWithdrawal 
		<< ", the account number is " << accountNum << ", and the value is $" << getBooty() << ", aargh!" << endl;

}