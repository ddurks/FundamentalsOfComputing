//David Durkin
//Fund Comp II
//checkingAccount.h with composition

#include "BankAccount.h"

//Class checking Account with BankAccount object included (Composition)
class CheckingAccount{

public:
	CheckingAccount();
	void print();
	BankAccount b;
	
private:
	double maxWithdrawal;
	int accountNum;	


};