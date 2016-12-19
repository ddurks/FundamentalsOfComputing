//David Durkin
//Fund Comp II
//mortgage.cpp
//Functions file

#include "mortgage.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Default constructor
Mortgage::Mortgage(){
	principal = 100000;
	rate = .05;
	payment = 500;
}

//Overloaded constructor
Mortgage::Mortgage(double principalIN, double rateIN, double paymentIN){
	principal = principalIN;
	rate = rateIN;
	payment = paymentIN;

}

//Deducts value from principal remaining
void Mortgage::credit(double value){

	principal = principal - value;

}

//returns principal value remaining
double Mortgage::getPrincipal(){

	return principal;
}

//returns an amortization table of a mortgage
void Mortgage::amortize(){

	double currentInterest;
	int month = 1;

	//Displays error and exits function if values are improper
	if(payment<=(principal*rate/12)){
		cout << "Error, payment is too small." << endl;
		return;
	}
	if(rate>=1 || rate<0){
		cout << "Error, please enter rate in positive decimal form." << endl;
		return;
	}
	if(principal<0){
		cout << "Error, original principal must be greater than 0" << endl;
		return;
	}

	//Displays table headings with nice spacing
	cout << setw(15) << "Month" <<
			setw(15) << "Payment" <<
			setw(15) << "Interest" <<
			setw(15) << "Balance" << endl;

	//Calculates and displays table while there is balance remaining
	while(principal > 0){
		
		currentInterest = principal*rate/12;
		principal = principal+currentInterest;
		
		//Adjusts principal and displays table line
		if(principal>payment){
			cout << setw(15) << month <<
					setw(15) << payment <<
					setw(15) << currentInterest <<
					setw(15) << principal-payment << endl;

			principal=principal-payment;
		}

		//Adjusts principal when it is less than payment and displays table line
		else{
			cout << setw(15) << month <<
					setw(15) << principal <<
					setw(15) << currentInterest <<
					setw(15) << principal-principal << endl;

			principal = 0;
		}

		month++;
	}

}