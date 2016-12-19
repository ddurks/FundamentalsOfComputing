//David Durkin
//Fund Comp II
//OvernightPackage.cpp

#include "OvernightPackage.h"

//Constructor
OvernightPackage::OvernightPackage(string inName, int inZip, double inWeight, double inOzCost, double inExCost) : Package(inName, inZip, inWeight, inOzCost){
	extraCostPerOunce = inExCost;
}

//Calculating overnight cost using main class function
double OvernightPackage::CalculateOvernightCost(){
	return CalculateCost() + (getWeight() * extraCostPerOunce);
}