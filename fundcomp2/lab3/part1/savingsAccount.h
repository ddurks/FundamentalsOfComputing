//David Durkin
//Fund Comp II
//savingsAccount.h

#include "BankAccount.h"

//SavingsAccount declaration derived from BankAccount
class SavingsAccount : public BankAccount {
public:
	SavingsAccount();
	SavingsAccount(double, double, int, string, int, double);
	void print();
private:
	double intRate;
	double maxWithdrawal;
	int accountNum;
};