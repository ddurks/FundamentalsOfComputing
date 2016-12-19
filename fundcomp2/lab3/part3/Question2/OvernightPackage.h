//David Durkin
//Fund CompII
//OvernightPackage.h

#include <string>
#include "Package.h"

//Class declaration which inherits class Package
class OvernightPackage : public Package{
public:
	//Constructor and calculate function
	OvernightPackage(string, int, double, double, double);
	double CalculateOvernightCost();

//Private data members
private:
	double extraCostPerOunce;

};