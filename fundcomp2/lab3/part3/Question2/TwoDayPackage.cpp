//David Durkin
//Fund Comp II
//TwoDayPackage.cpp

#include "TwoDayPackage.h"

//Constructor
TwoDayPackage::TwoDayPackage(string inName, int inZip, double inWeight, double inOzCost, double inFee) : Package(inName, inZip, inWeight, inOzCost){
	flatFee = inFee;
}

//Calculating using base class member function
double TwoDayPackage::CalculateCostwFee(){
	return CalculateCost() + flatFee;
}