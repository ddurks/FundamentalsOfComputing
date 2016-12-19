//David Durkin
//Fund Comp II
//Package.h

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

//Base class package
class Package{

//Constructors and member functions
public:
	Package();
	Package(string, int, double, double);
	double CalculateCost();
	double getWeight();
	string getName();
	int getZip();

//Private data memberts
private:
	string name;
	int zip;
	double weight;
	double ozCost;

};

#endif