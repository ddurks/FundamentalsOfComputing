CardDeck: mainCardDeck.o CardDeck.o
	g++ main2.o CardDeck.o -o CardDeck

mainCardDeck.o: mainCardDeck.cpp
	g++ -c mainCardDeck.cpp

CardDeck.o: CardDeck.cpp NDVector.h
	g++ -c CardDeck.cpp

clean: 
	rm -f *.o CardDeck
