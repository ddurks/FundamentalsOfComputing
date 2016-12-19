all: main.o C4Board.o C4Col.o
	g++ main.o C4Board.o C4Col.o -o connectfour

main.o: main.cpp C4Board.h
	g++ -c main.cpp 

C4Board.o: C4Board.cpp C4Board.h
	g++ -c C4Board.cpp 

C4Col.o: C4Col.cpp C4Col.h
	g++ -c C4Col.cpp 

clean:
	rm connectfour