//David Durkin
//Fund Comp II
//CardDeck.h

#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

//class declaration for CardDeck
class CardDeck{

public:
	//member functions
	CardDeck();
	~CardDeck();
	CardDeck(int);
	int getSize();
	void shuffle();
	int inOrder();
	void printReverse();
	int deal();
	friend ostream& operator<<(ostream& os, const CardDeck & deck);

private:
	//private deque of cards
	deque<int> cards;

};