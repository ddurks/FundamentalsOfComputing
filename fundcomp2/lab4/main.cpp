//David Durkin
//Fund Comp II
//main Function for CardDeck

#include "CardDeck.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){

	//Tests the overloaded operator and the reversePrint function
	CardDeck ten(10);

	if(ten.inOrder()){
		cout << "The cards are in order" << endl;
	}
	else{
		cout << "The cards are not in order" << endl;
	}

	cout << "printReverse() output: " << endl;
	ten.printReverse();

	srand(time(NULL));
	ten.shuffle();

	cout << endl;

	cout << "Cards after shuffling: " << endl;
	cout << ten << endl;

	//Monkey Sort
	//7 card deck
	CardDeck seven(7);
	seven.shuffle();
	int sevenshuffle = 1;
	while(!seven.inOrder()){
		seven.shuffle();
		sevenshuffle++;
	}
	cout << "Shuffles needed to re order 7 cards: " << sevenshuffle << endl;

	//8 card deck
	CardDeck eight(8);
	eight.shuffle();
	int eightshuffle = 1;
	while(!eight.inOrder()){
		eight.shuffle();
		eightshuffle++;
	}
	cout << "Shuffles needed to re order 8 cards: " << eightshuffle << endl;

	//9 card deck
	CardDeck nine(9);
	nine.shuffle();
	int nineshuffle = 1;
	while(!nine.inOrder()){
		nine.shuffle();
		nineshuffle++;
	}
	cout << "Shuffles needed to re order 9 cards: " << nineshuffle << endl;

	return 0;
}