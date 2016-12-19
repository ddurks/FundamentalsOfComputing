//David Durkin
//Fund Comp II
//BankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;

//Declaration of BankAccount class
class BankAccount {
public:
	//Constructors
	BankAccount();
	BankAccount(string, int, double);
	//member functions
	string getName();
	int getBooty();

private:
	string name;
	int booty;
	double value;
};

#endif