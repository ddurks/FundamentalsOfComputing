//David Durkin
//Fund Comp II
//BankAccount.cpp

#include "BankAccount.h"

//Default Constructor
BankAccount::BankAccount(){
	booty = 0;
	value = 0;
	name = "unknown";
}

//Constructor
BankAccount::BankAccount(string nameIn, int bootyIn, double bootyValue){
	name = nameIn;
	booty = bootyIn;
	value = bootyValue;
}

//get functions for use in derived classes
string BankAccount::getName(){
	return name;
}

int BankAccount::getBooty(){
	return booty;
}