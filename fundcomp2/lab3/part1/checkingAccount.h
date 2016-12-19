//David Durkin
//Fund Comp II
//checkingAccount.h

#include "BankAccount.h"

//Declaration of CheckingAccount derived from BankAccount
class CheckingAccount : public BankAccount {

public:
	CheckingAccount();
	CheckingAccount(double, int, string, int, double);
	void print();
private:
	double maxWithdrawal;
	int accountNum;	

};