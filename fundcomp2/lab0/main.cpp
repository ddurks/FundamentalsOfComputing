//David Durkin
//Fund Comp II
//main.cpp
//Main driver file

#include<iostream> // for cout
#include "mortgage.h" // declaration of Mortgage class; for 2a
using namespace std; 

int main () {
	Mortgage first (10000, .05, 500); // uses non-default initialization(interest in decimal form); for 2b 
	Mortgage second; // uses default constructor, mortgage of $100k; for 2c

	// demonstrate functions requested in 2d
	second.credit(10000); // credit 10,000; careful as this should ideally be 10000.00 
	cout << "Current balance after crediting second mortgage 10K: "<< second.getPrincipal() << endl;
	cout << "Amortization schedule for first mortgage:" << endl;
	first.amortize();
}