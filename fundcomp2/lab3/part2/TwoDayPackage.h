//David Durkin
//Fund Comp II
//TwoDayPackage.h

#include "Package.h"
#include <string>
using namespace std;

//Declaration of TwoDayPackage derived from Package
class TwoDayPackage : public Package{
public:
	//Constructors
	TwoDayPackage();
	TwoDayPackage(string, int, double, double, double);
	//Price calculating function
	double CalculateCostwFee();

private:
	double flatFee;

};