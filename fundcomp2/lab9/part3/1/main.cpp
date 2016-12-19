//David Durkin
//Fund Comp II
//main Function for CardDeck

#include "NDVector.h"
#include "CardDeck.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){

	//Tests the overloaded operator and the reversePrint function
	CardDeck ten(52);

	if(ten.inOrder()){
		cout << "The cards are in order" << endl;
	}
	else{
		cout << "The cards are not in order" << endl;
	}

	cout <<"The cards in order: " << endl;
	ten.print();

	cout << endl;

	cout << "printReverse() output: " << endl;
	ten.printReverse();

	srand(time(NULL));
	ten.shuffle();

	cout << endl;

	cout << "Cards after shuffling: " << endl;
	ten.print();

	return 0;
}