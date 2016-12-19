all: Tourney

Tourney: main.o
	g++ main.o -o Tourney

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o Tourney
