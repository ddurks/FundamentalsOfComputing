//David Durkin
//Fund Comp II
//Package.cpp

#include "Package.h"
#include <iostream>
using namespace std;

//Constructor
Package::Package(){
	name = "None";
	zip = 00000;
	weight = 0;
	ozCost = 0;
}

//Overloaded constructor
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

//Calculating cost function
double Package::CalculateCost(){
	return ozCost * weight;
}


//Get functions
double Package::getWeight(){
	return weight;
}

string Package::getName(){
	return name;
}

int Package::getZip(){
	return zip;
}