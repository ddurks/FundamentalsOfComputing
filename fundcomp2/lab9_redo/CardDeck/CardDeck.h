//David Durkin
//FundComp II
//CardDeck.h
//CardDeck class declaration

#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include <iostream>
#include "NDVector.h"
using namespace std;

//CardDeck Class Declaration
class CardDeck{
	friend ostream &operator<<(ostream &, CardDeck &);	

	public:
		//Constructor
		CardDeck(int numCardsIN = 52);
		//Member functions
		int getSize();
		int inOrder();
		void printReverse();
		void shuffle();	

	private:
		//Instantiates an NDVector as a member
		NDVector<int> cards;
		int numCards;
};

#endif


