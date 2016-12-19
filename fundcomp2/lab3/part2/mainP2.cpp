//David Durkin
//Fund Comp II
//Driver for Lab 3

#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>

using namespace std;

//Simple driver function for Package derivatives
int main(){

	//Declaring class objects
	TwoDayPackage Tupac("David", 60546, 7.5, 2, 5);
	OvernightPackage Biggie("Rico", 46556, 10, 3, 1);

	//Printing using member functions from all classes
	cout << "The Two Day Package for " << Tupac.getName() << " will cost $" << 
	Tupac.CalculateCostwFee() << " and weighs " << Tupac.getWeight() << " oz." << endl;
	cout << "The Overnight Package for " << Biggie.getName() << " will cost $" << 
	Biggie.CalculateOvernightCost() << " and weighs " << Biggie.getWeight() << " oz." << endl;

	return 0;
}