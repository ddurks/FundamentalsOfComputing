//David Durkin
//Fund Comp II
//Package.cpp

#include "Package.h"
#include <iostream>
using namespace std;

//Defualt Constructor
Package::Package(){
	name = "None";
	zip = 00000;
	weight = 0;
	ozCost = 0;
}

//Overloaded Constructor
Package::Package(string inName, int inZip, double inWeight, double inOzCost){
	if(inWeight<0|| inOzCost<0){
		cout << "Error, all weight and cost numbers must be positive" << endl;
	}
	else{
		name = inName;
		zip = inZip;
		weight = inWeight;
		ozCost = inOzCost;
	}
}

//Calculates cost
double Package::CalculateCost(){
	return ozCost * weight;
}

//Get functions for use in derived classes
double Package::getWeight(){
	return weight;
}

string Package::getName(){
	return name;
}