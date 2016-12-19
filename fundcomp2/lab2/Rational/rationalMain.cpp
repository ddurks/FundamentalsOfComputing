//David Durkin
//Fund Comp II
//Driver for Rational class 

#include "Rational.h"
using namespace std;

int main(){
	//Declare variables, instruct user, take input
	int n1, d1, n2, d2, n3, d3;

	cout << "Enter three rational numbers in numerator followed by denominator format." << endl;
	cout << "Number 1:" << endl;
	cin >> n1;
	cout << "-" << endl;
	cin >> d1;
	cout << "Number 2:" << endl;
	cin >> n2;
	cout << "-" << endl;
	cin >> d2;
	cout << "Number 3:" << endl;
	cin >> n3;
	cout << "-" << endl;
	cin >> d3;

	//Declare rational number objects with inputted values
	Rational r1(n1,d1);
	Rational r2(n2,d2);
	Rational r3(n3,d3);

	//Output the rationals in floating point format
	cout << "Number 1: " << r1 << endl;
	cout << "Number 2: " << r2 << endl;
	cout << "Number 3: " << r3 << endl;

	//Compute various formulas and mathematical operations using overloaded operators
	Rational rAns1;
	rAns1 = r1 * r2;
	cout << "Voltage(V=IR), with number 1 as Current(I) and number 2 as Resistance(R): " << endl << rAns1 << endl;

	Rational rAns2;
	rAns2 = r2 / r3;
	cout << "Velocity, with number 2 as distance, and number 3 as time: " << endl << rAns2 << endl;

	Rational rAns3;
	rAns3 = r1 + (r2*r3);
	cout << "Velocity, with number 1 as v nought, number 2 as acceleration, and number 3 as time: " << endl << rAns3 << endl;

	Rational rAns4;
	rAns4 = r1^r3;
	cout << "Number 1 raised to the power of number 3: (with all numbers cut off to ints) " << endl << rAns4 << endl;

	Rational rAns5;
	rAns5 = r1 * r3;
	cout << "Work, with number 1 as force, and number 2 as distance: " << endl << rAns5 << endl;
	
	return 0;
}


