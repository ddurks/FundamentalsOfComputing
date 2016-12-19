all: main.o Puzzle.o 
	g++ main.o Puzzle.o -o Puzzle

main.o: main.cpp Puzzle.h
	g++ -c main.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	g++ -c Puzzle.cpp

clean:
	rm *o Puzzle