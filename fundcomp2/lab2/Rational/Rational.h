//David Durkin
//Fund Comp II
//Rational.h

#include <iostream>
using namespace std;

//Class declaration
class Rational{

friend ostream& operator<<(ostream& os, const Rational& r);

public:
	Rational();
	Rational(int, int);
	Rational operator+(const Rational& r);
	Rational operator-(const Rational& r);
	Rational operator*(const Rational& r);
	Rational operator/(const Rational& r);
	Rational operator^(const Rational& r);
	int gcd(int, int);
	void interactive();

private:
	int x;
	int y;
};