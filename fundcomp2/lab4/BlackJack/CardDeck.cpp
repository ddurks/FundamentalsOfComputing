//David Durkin
//Fund Comp II
//CardDeck.cpp

#include "CardDeck.h"
#include <deque>
#include <algorithm>
#include <iostream>
#include <iterator>

//Defaut constructor
CardDeck::CardDeck(){
	int num = 0, n = 52, i;

	//sets up a 52 card deck
	for(i=0;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//Overloaded constructor
CardDeck::CardDeck(int n){
	int num = 0, i;

	//sets up a n card deck
	for(i=0;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//destructor
CardDeck::~CardDeck(){
	cards.clear();
}

//Overloaded cout friend function
ostream& operator<<(ostream& os, const CardDeck & deck){

	deque<int>::const_iterator i = deck.cards.begin();

	while(i != deck.cards.end()){

		os << (*i) << ", ";

		++i;
	}

	os << endl;

	return os;

}

//returns size of deck
int CardDeck::getSize(){
	return cards.size();
}

//shuffled deck
void CardDeck::shuffle(){
	random_shuffle(cards.begin(), cards.end());
}

//check whether deck is in order
int CardDeck::inOrder(){
	deque<int>::iterator i = adjacent_find(cards.begin(), cards.end(), greater<int>());

	if(i == cards.end()){
		return 1;
	}
	else{
		return 0;
	}
}

//prints deck in reverse
void CardDeck::printReverse(){

	deque<int>::const_reverse_iterator r;
	deque<int>::const_reverse_iterator end = cards.rend();

	for( r = cards.rbegin(); r != end; ++r){
		cout << (*r) << ", ";
	}
	cout << endl;

}

//deals out a card with respect to its value in blackjack
int CardDeck::deal(){

	int dealt = cards.back()%13;
	int card;
	cards.pop_back();

	if(dealt >=0 && dealt <=8){
		card = dealt+2;
	}
	if(dealt >=9 && dealt <=11){
		card = 10;
	}
	if(dealt == 12){
		card = 11;
	}

	return card;
	
}






