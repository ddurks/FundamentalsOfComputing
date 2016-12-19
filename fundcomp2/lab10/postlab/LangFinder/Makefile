all: main.o Language.o
	g++ main.o Language.o -o Language

main.o: main.cpp
	g++ -c main.cpp

Language.o: Language.cpp Language.h
	g++ -c Language.cpp

clean:
	rm *.o Language