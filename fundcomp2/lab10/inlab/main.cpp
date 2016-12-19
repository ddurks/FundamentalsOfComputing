//David Durkin
//Fund Comp II
//Main function for data mining

#include "DataMine.h"
#include <iostream>

int main(){

	DataMine test;
	test.strip();
	test.displayUnique();
	cout << "Would you also like to calculate the Jaccard Coefficient? 1-yes, 0-no." << endl;
	//The expected Jaccard Coefficient using faust10.txt and randj.txt is .238834
	int choice;
	cin >> choice;
	if(choice == 1){
		test.Jaccard();
	}
	return 0;
}