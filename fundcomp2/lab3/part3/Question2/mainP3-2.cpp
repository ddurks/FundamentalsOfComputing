//David Durkin
//Fund Comp II
//Driver for Part III Question 2

#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <iostream>
#include <vector>
using namespace std;

//Driver function for part 3 question 2
int main(){

	//Instantiate vectors and iterators
	vector<TwoDayPackage *> tupac;
	vector<TwoDayPackage *>::const_iterator i;
	vector<OvernightPackage *> nightpac;
	vector<OvernightPackage *>::const_iterator j;

	//Add object data to the vectors
	tupac.push_back(new TwoDayPackage("Michael", 18504, 25, 5, 2.50));
	tupac.push_back(new TwoDayPackage("Dwight", 18501, 21, 5, 1.25));
	tupac.push_back(new TwoDayPackage("Jim", 18503, 13, 5, 4.99));

	nightpac.push_back(new OvernightPackage("Ross", 10002, 9, 4, 3));
	nightpac.push_back(new OvernightPackage("Monica", 10001, 27, 6, 3.56));
	nightpac.push_back(new OvernightPackage("Rachel", 10000, 7, 5, 6.77));

	double sum = 0;

	cout << "Two Day Packages: " << endl;

	//Looping through data, printing info, calculating sum
	for(i=tupac.begin(); i != tupac.end(); ++i){
		cout << "Name: " << (*i)->getName() << endl;
		cout << "Zip: " << (*i)->getZip() << endl;
		sum += (*i)->CalculateCostwFee();
	}

	cout << endl << "Overnight Packages:" << endl;

	for(j=nightpac.begin(); j != nightpac.end(); ++j){
		cout << "Name: " << (*j)->getName() << endl;
		cout << "Zip: " << (*j)->getZip() << endl;
		sum += (*j)->CalculateOvernightCost();	
	}

	cout << "The total cost to ship these packages will be $" << sum << endl;

	return 0;
}