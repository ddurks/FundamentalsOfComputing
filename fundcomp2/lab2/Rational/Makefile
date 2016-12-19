all: rationalMain.o Rational.o 
	g++ rationalMain.o Rational.o -o rational

main.o: main.cpp Rational.h
	g++ -c rationalMain.cpp 

Rational.o: Rational.cpp Rational.h
	g++ -c Rational.cpp 

clean:
	rm rational