//David Durkin
//Fund Comp II
//TwoDayPackage.cpp

#include "TwoDayPackage.h"

//Defualt Constructor
TwoDayPackage::TwoDayPackage(){
	flatFee = 0;
}

//OVerloaded Constructor
TwoDayPackage::TwoDayPackage(string inName, int inZip, double inWeight, double inOzCost, double inFee) : Package(inName, inZip, inWeight, inOzCost){
	flatFee = inFee;
}

//Calculate cost function utilizing member function inherited from base class Package
double TwoDayPackage::CalculateCostwFee(){
	return CalculateCost() + flatFee;
}