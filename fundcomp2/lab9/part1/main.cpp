//David Durkin
//NDVector Driver

#include "NDVector.h"
#include <iostream>
using namespace std;

int main(){
	NDVector<int> vec;
	
	for(int i = 1; i<20; i++){
		vec.push_back(i);
	}

	for(int i=0; i<vec.getSize(); i++){
		cout << vec[i] << endl;
	}
}
