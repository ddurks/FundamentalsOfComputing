all: main.o NDVector.o 
	g++ main.o NDVector.o -o NDVector

main.o: main.cpp
	g++ -c main.cpp

NDVector.o: NDVector.cpp NDVector.h
	g++ -c NDVector.cpp

clean:
	rm *o NDVector
