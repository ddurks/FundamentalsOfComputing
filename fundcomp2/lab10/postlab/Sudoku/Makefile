all: main.o Puzzle.o 
	g++ -std=c++11 main.o Puzzle.o -o Puzzle

main.o: main.cpp Puzzle.h
	g++ -std=c++11 -c main.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	g++ -std=c++11 -c Puzzle.cpp

clean:
	rm *o Puzzle