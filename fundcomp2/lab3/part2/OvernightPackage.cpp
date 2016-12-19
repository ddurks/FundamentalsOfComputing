//David Durkin
//Fund Comp II
//OvernightPackage.cpp

#include "OvernightPackage.h"

//Defualt constructor
OvernightPackage::OvernightPackage(){
	extraCostPerOunce = 0;
}

//OVerloaded constructor
OvernightPackage::OvernightPackage(string inName, int inZip, double inWeight, double inOzCost, double inExCost) : Package(inName, inZip, inWeight, inOzCost){
	extraCostPerOunce = inExCost;
}

//Cost calculating function using member functions inherited from base class Package
double OvernightPackage::CalculateOvernightCost(){
	return CalculateCost() + (getWeight() * extraCostPerOunce);
}