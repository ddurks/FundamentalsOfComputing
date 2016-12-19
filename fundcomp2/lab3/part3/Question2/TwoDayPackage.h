//David Durkin
//Fund Comp II
//TwoDayPackage.h

#include "Package.h"
#include <string>
using namespace std;

//Class declaration inheriting Package class
class TwoDayPackage : public Package{
public:
	TwoDayPackage(string, int, double, double, double);
	double CalculateCostwFee();

private:
	double flatFee;

};