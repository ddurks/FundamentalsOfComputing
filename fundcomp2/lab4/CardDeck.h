//David Durkin
//Fund Comp II
//CardDeck.h

#include "NDVector.h"
#include <algorithm>
#include <iostream>
using namespace std;

//CardDeck class declaration
class CardDeck{

public:
	//Members Functions
	CardDeck();
	~CardDeck();
	CardDeck(int);
	int getSize();
	void shuffle();
	int inOrder();
	void printReverse();
	friend ostream& operator<<(ostream& os, const CardDeck & deck);

private:
	//"Hidden" card deque
	deque<int> cards;

};