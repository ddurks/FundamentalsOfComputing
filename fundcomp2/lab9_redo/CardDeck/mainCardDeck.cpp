//David Durkin
//FundComp II
//CardDeck main.cpp

#include <iostream>
#include "CardDeck.h"
#include "NDVector.h"
#include <algorithm>
#include <time.h>
#include <ctime>
using namespace std;

int main(void){
	//Seeding rand
	srand (time(NULL));

	//Instantiate a deck
	CardDeck deck(10); 

	cout << "Your Card Deck: " << deck << endl;
	
	//Check if Deck is in order
	if(deck.inOrder()){
		cout << "Deck is in order" << endl;
	}
	else{
		cout << "Deck isn't in order" << endl;
	} 
	cout << endl;

	//Printing deck in reverse
	cout << "Your Deck in reverse: " << endl;
	deck.printReverse();

	cout << endl << "Shuffling... " << endl;
	deck.shuffle();

	cout << "Your Deck shuffled" << endl;
	cout << deck << endl;

	//Checking if Deck is in order
	if(deck.inOrder()){
		cout << "Deck is in order" << endl << endl;
	}
	else{
		cout << "Deck isn't in order" << endl << endl;
	} 
	
return 0; 	
}

