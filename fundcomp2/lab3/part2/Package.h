//David Durkin
//Fund Comp II
//Package.h

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>

using namespace std;

//Base class Package declaration
class Package{

public:
	//Constructors
	Package();
	Package(string, int, double, double);
	//Member Functions
	double CalculateCost();
	double getWeight();
	string getName();

private:
	//Variables
	string name;
	int zip;
	double weight;
	double ozCost;

};

#endif