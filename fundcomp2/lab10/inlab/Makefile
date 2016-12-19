all: main.o DataMine.o
	g++ main.o DataMine.o -o Mine

main.o: main.cpp
	g++ -c main.cpp

DataMine.o: DataMine.cpp DataMine.h
	g++ -c DataMine.cpp

clean:
	rm *o Mine