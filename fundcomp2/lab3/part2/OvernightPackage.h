//David Durkin
//Fund CompII
//OvernightPackage.h

#include <string>
#include "Package.h"

//Declaration of OvernightPackage derived from package
class OvernightPackage : public Package{
public:
	//Constructors
	OvernightPackage();
	OvernightPackage(string, int, double, double, double);
	//Price calculating function
	double CalculateOvernightCost();

private:
	double extraCostPerOunce;

};