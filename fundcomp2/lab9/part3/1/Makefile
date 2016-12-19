all: main.o NDVector.o CardDeck.o
	g++ main.o NDVector.o CardDeck.o -o NDVector

main.o: main.cpp
	g++ -c main.cpp

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp

NDVector.o: NDVector.cpp NDVector.h
	g++ -c NDVector.cpp

clean:
	rm *o NDVector
