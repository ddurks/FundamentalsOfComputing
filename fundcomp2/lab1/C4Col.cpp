//David Durkin
//Fund Comp II
//C4Col.cpp

#include "C4Col.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
C4Col::C4Col(){
	numDiscs = 0;
	maxDiscs = 6;
	int i;
	//Fills column with blanks
	for(i=0;i<6;i++){
		discs[i] = ' ';
	}
}

//Check if a column is full
int C4Col::isFull(){
	if(numDiscs>=maxDiscs){
		return 1;
	}
	else{
		return 0;
	}
}

//Return a disc from a certain column index
char C4Col::getDisc(int index){
	if(index>5||index<0){
		cout << "Error: disk does not exist" << endl;
	}
	return discs[index];
}

//Get the max number of discs
int C4Col::getMaxDiscs(){
	return maxDiscs;
}

//Add a disc to a certain column, error if it is already full
void C4Col::addDisc(char disc){
	if(isFull()){
		cout << "This Column is Full!" << endl;
	}
	else{
		discs[numDiscs] = disc;
		numDiscs++;
	}
}