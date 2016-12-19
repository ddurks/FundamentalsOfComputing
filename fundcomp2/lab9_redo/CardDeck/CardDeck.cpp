//David Durkin
//FundComp II
//CardDeck.cpp
//Card Deck class implementation

#include "NDVector.h"
#include "CardDeck.h"
#include <iostream>
using namespace std;

CardDeck::CardDeck(int numCardsIN){
	numCards = numCardsIN;
	for (int i = 0; i < numCards; i ++){
		cards.push_back(i);
	}	
}

ostream &operator << (ostream &out, CardDeck &card){
	for (int i = 0; i != card.cards.getSize(); ++i){
		out << card.cards[i] << ", ";
	}
	out << endl;
	return out;
}

//Returns the size of the deck
int CardDeck::getSize(){
	int size = cards.getSize();

	return size;
}

//Checks if the cards are in order
int CardDeck::inOrder(){
	int inorder = 1;

	for (int i = 0; i < cards.getSize() - 1; ++i){
		if (cards[i] > cards[i + 1]){
			inorder = 0;
			break;
		}	
	}	
	return inorder;
}

//Shuffles the deck of cards
void CardDeck::shuffle(){
	for (int i = 1; i < cards.getSize(); i++){
		int j = rand() % (i+0);
		if (j!=i){
			int temp1 = cards[i];
			int temp = cards[j];
			cards[j] = temp1;
			cards[i] = temp;
		}
	}
}	

//Prints the cards in reverse
void CardDeck::printReverse(){
	for (int i = cards.getSize()-1; i != -1; i--) {
		cout << cards[i] << ", ";
	}	
	cout << endl;
}

