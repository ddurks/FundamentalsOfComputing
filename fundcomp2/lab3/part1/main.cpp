//David Durkin
//Fund Comp II
//driver file for pirateBank

#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>

//Simple driver for BankAccount and its derived classes
int main(){

	//Declaring derived class objects
	SavingsAccount s1(.05, 1000, 123456, "Blackbeard", 1000000, 16000);
	CheckingAccount c1(500, 654321, "Jack Sparrow", 150, 10000);

	//Printing info
	c1.print();
	s1.print();


	return 0;
}