//David Durkin
//Calculating PI

#include <iostream>
#include <math.h>
using namespace std;

int main(){

	//Print out instructions and take input
	cout << "Calculating the value of Pi." << endl;
	cout << "How many terms?" <<endl;

	int terms;
	cin >> terms;

	//Ensure that the terms are greater than 1
	if(terms<2){
		cout << "Error! Provided value must be >= 2! Enter again:" << endl;
		cin >> terms;
	}

	//Calculate and print
	int i;
	double sum = 0;
	for(i=0;i<terms;i++){
		sum += 4*(pow(-1,i)/(2*i+1));
		cout << "The approximation for " << i+1 << " term(s) is " << sum << endl;
	}

}
