//David Durkin
//Fund Comp II
//BankAccount.cpp with composition

#include "BankAccount.h"

BankAccount::BankAccount(){
	booty = 0;
	value = 0;
}

BankAccount::BankAccount(int bootyIn, double bootyValue){
	booty = bootyIn;
	value = bootyValue;
}

int BankAccount::getBooty(){
	return booty;
}