//David Durkin
//Fund Comp II
//Blackjack driver program

#include "CardDeck.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

	//instantiating variables
	int play = 1;
	CardDeck *deck = new CardDeck;
	int hit = 0;
	int dealerWins = 0;
	int playerWins = 0;

	//shuffle the deck
	srand(time(NULL));
	deck->shuffle();

	//play blackjack while loop
	while(play){

		//set a seed to shuffle the deck
		srand(time(NULL));

		//Opens a new deck and deletes the old one if there are less than 15 cards
		if(deck->getSize()<15){
			delete deck;
			cout << "A new Deck has been opened and shuffled" << endl;
			CardDeck *deck = new CardDeck(52);
			deck->shuffle();
		}

		//vestors which contain the player and dealer's cards
		vector<int> player;
		vector<int> dealer;

		//deal two cards to the player 
		player.push_back(deck->deal());
		player.push_back(deck->deal());

		//display the cards and ask the player what to do
		cout << "Your two cards are: " << player[0] << ", " << player[1] << endl;

		cout << "What would you like to do?" << endl;
		cout << "1 to hit, anything else to stand: ";
		cin >> hit;

		int index = 1;

		//if the player chooses to hit, give a new card and ask again
		while(hit){
			player.push_back(deck->deal());
			index++;
			cout << "Your next card is: " << player[index] << endl;

			cout << "What would you like to do?" << endl;
			cout << "1 to hit, anything else to stand: ";
			cin >> hit;
		}

		//display the player's card values and calculate sum of card values
		int playersum = 0;
		cout << "Your Cards are:" << endl;
		for(int i = 0; i < index; i++){
			cout << player[i] << ", ";
			playersum += player[i];
		}
		playersum += player[index];
		cout << player[index] << endl;

		//simulate the dealer drawing cards and calculate sum of card values
		int dealersum = 0;
		int dealerindex = 0;

		while(dealersum < 17){
			dealer.push_back(deck->deal());
			dealersum += dealer[dealerindex];
			dealerindex++;
		}
		dealerindex--;

		//display the dealer's cards
		cout << "The Dealer's Cards are:" << endl;
		for(int j = 0; j < dealerindex; j++){
			cout << dealer[j] << ", ";
		}
		cout << dealer[dealerindex] << endl;

		//determine who won an display the result, keeping track of how many wins the dealer and player have
		if( playersum > 21 || ((dealersum >= playersum) && dealersum <= 21) ){
			cout << "YOU LOST" << endl;
			dealerWins++;
		}
		else{
			cout << "YOU WON" << endl;
			playerWins++;
		}

		//display dealer wins and player wins and player wins and asks if the user wants to play again
		cout << endl;
		cout << "Dealer wins: " << dealerWins << endl;
		cout << "Player wins: " << playerWins << endl;
		cout << "Enter 1 to play again, anything else to quit: " << endl;
		cin >> play;

	}

	return 0;
}