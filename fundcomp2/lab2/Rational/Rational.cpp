//David Durkin
//Fund Comp II
//Rational.cpp

#include "Rational.h"
#include <iostream>
#include <math.h>
using namespace std;

//Constructor
Rational::Rational(){
	x = 1;
	y = 1;
}

//Overloaded constructor
Rational::Rational(int xIn, int yIn){
	//Return an error if the denominator entered is 0
	if(yIn == 0){
		cout << "Error, denominator cannot be 0." << endl;
	}
	//Find Gcd in order to simplify if needed
	int gDenom = gcd(xIn,yIn);
	x = xIn/gDenom;
	y = yIn/gDenom;
}

//Overloaded cout operator to take Class objects
ostream& operator<<(ostream& os, const Rational& r){

	os << "(Fraction Format)" << (float)r.x << "/" << (float)r.y;
	os << " (Decimal Format)" << (float)r.x/(float)r.y << endl;
	return os;
}

//Overloaded adding operator
Rational Rational::operator+(const Rational& r){
	Rational fresh;
	fresh.x = (this->x * r.y) + (r.x * this->y);
	fresh.y = r.y * this->y;

	return fresh;
}

//Overloaded subtracting operator
Rational Rational::operator-(const Rational& r){
	Rational fresh;
	fresh.x = (this->x * r.y) - (r.x * this->y);
	fresh.y = r.y * this->y;

	return fresh;	
}

//Overloaded multiplication operator
Rational Rational::operator*(const Rational& r){
	Rational fresh;
	fresh.x = (float)this->x * r.x;
	fresh.y = (float)this->y * r.y;

	return fresh;
}

//Overloaded division operator
Rational Rational::operator/(const Rational& r){
	Rational fresh;
	fresh.x = (float)this->x * r.y;
	fresh.y = (float)this->y * r.x;

	return fresh;
}

//Overloaded caret operator
Rational Rational::operator^(const Rational& r){
	Rational fresh;
	fresh.x = pow(this->x,r.x);
	fresh.y = pow(this->y,r.y);

	return fresh;
}

//Gcd function
int Rational::gcd(int m, int n){
	int i;

	while(n != 0){
		i = m % n;
		m = n;
		n = i;
	}

	return m;
}