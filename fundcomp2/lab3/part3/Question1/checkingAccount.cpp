//David Durkin
//Fund Comp II
//checkingAccount.cpp with composition

#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(){
	maxWithdrawal = 500;
	accountNum = 0;
}

//Print function utilizing BankAccount object in the checkingAcount class (Composition)
void CheckingAccount::print(){

	cout << "In this pirate checking account, the max withdrawal is " << maxWithdrawal 
		<< " the account number is " << accountNum << " and their booty total is: " << 
		b.getBooty() << ", aargh!" << endl;

}