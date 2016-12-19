//David Durkin
//Fund Comp II
//CardDeck.cpp

#include "CardDeck.h"
#include <deque>
#include <algorithm>
#include <iostream>
#include <iterator>

//Default Constructor
CardDeck::CardDeck(){
	int num = 0, n = 52, i;

	//sets card deque up 1-52
	for(i=0;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//Overloaded Constructor
CardDeck::CardDeck(int n){
	int num = 0, i;

	//sets card deque up 1-n
	for(i=0;i<n;i++){
		cards.push_back(num);
		num++;
	}
}

//Destructor
CardDeck::~CardDeck(){
	cards.clear();
}

//Overloaded cout operator friend function
ostream& operator<<(ostream& os, const CardDeck & deck){

	deque<int>::const_iterator i = deck.cards.begin();

	//prints out deck of cards with commas in between numbers
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

//shuffles deque using random_shuffle
void CardDeck::shuffle(){
	random_shuffle(cards.begin(), cards.end());
}

//Tests whether the cards are in order using adjacent_find function
int CardDeck::inOrder(){
	deque<int>::iterator i = adjacent_find(cards.begin(), cards.end(), greater<int>());

	if(i == cards.end()){
		return 1;
	}
	else{
		return 0;
	}
}

//prints the deck of cards in reverse order
void CardDeck::printReverse(){

	deque<int>::const_reverse_iterator r;
	deque<int>::const_reverse_iterator end = cards.rend();

	for( r = cards.rbegin(); r != end; ++r){
		cout << (*r) << ", ";
	}
	cout << endl;

}







