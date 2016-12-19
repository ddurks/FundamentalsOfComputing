//David Durkin
//Fund Comp II
//CardDeck.cpp

#include "CardDeck.h"
#include "NDVector.h"
#include <deque>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>

//Default Constructor
CardDeck::CardDeck(){
	int num = 1, n = 52, i;

	//sets card deque up 1-52
	for(i=1;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//Overloaded Constructor
CardDeck::CardDeck(int n){
	int num = 1, i;

	//sets card deque up 1-n
	for(i=1;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//Destructor
CardDeck::~CardDeck(){
	//cards.clear();
}

//Overloaded cout operator friend function
void CardDeck::print(){

	//prints out deck of cards with commas in between numbers
	for(int i = 0; i < cards.getSize(); i++){
		cout << cards[i] << ", ";
	}

	cout << endl;
}

//returns size of deck
int CardDeck::getSize(){
	return cards.getSize();
}

//shuffles deque using random_shuffle
void CardDeck::shuffle(){
	for(int i = cards.getSize()-1; i >= 1; i--){
		int card = cards[i];
		int randnum = rand() % i;
		int swapcard = cards[randnum];
		cards[randnum] = card;
		cards[i] = swapcard;

	}
	//random_shuffle(cards.begin(), cards.end());
}

//Tests whether the cards are in order using adjacent_find function
int CardDeck::inOrder(){
	for(int i = 1; i < cards.getSize(); i++){
		if(cards[i] < cards[i-1]){
			return 0;
		}
	}
	return 1;
}

//prints the deck of cards in reverse order
void CardDeck::printReverse(){

	for(int i = cards.getSize()-1; i>=0; i--){
		cout << cards[i] << ", ";
	}
	cout << endl;

}







