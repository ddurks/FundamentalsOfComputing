//David Durkin
//Fund Comp II
//BankAccount.h with composition

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

//Bank Account base class
class BankAccount {
public:
	BankAccount();
	BankAccount(int, double);
	int getBooty();

private:
	int booty;
	double value;
};

#endif