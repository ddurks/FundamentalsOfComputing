//David Durkin
//Fund Comp II
//savingsAccount.cpp

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

//Default constructor
SavingsAccount::SavingsAccount(){
	intRate = .03;
	maxWithdrawal = 800;
	accountNum = 0;
}

//Constructor with parameters along with base class constructor implementation
SavingsAccount::SavingsAccount(double intIn, double maxIn, int accountIn, string inName, int bootyIn, double valueIn) : BankAccount(inName, bootyIn, valueIn){
	maxWithdrawal = maxIn;
	accountNum = accountIn;
	intRate = intIn;
}

//Print function
void SavingsAccount::print(){
	cout << "In " << getName() << "'s savings account, the max withdrawal is " << maxWithdrawal 
			<< ", the interest rate is " << intRate*100 << " percent, and the value is $" << getBooty() << ", aargh!" << endl;
}

