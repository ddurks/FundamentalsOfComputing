all: mainBlackjack.o CardDeck.o 
	g++ -g mainBlackjack.o CardDeck.o -o CardDeck

main.o: mainBlackjack.cpp
	g++ -g -c main.cpp

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -g -c CardDeck.cpp

clean:
	rm *o CardDeck