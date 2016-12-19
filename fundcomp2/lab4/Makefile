all: main.o CardDeck.o 
	g++ main.o CardDeck.o -o CardDeck

main.o: main.cpp
	g++ -c main.cpp

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp

clean:
	rm *o CardDeck