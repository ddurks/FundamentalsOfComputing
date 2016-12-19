all: Package.o TwoDayPackage.o OvernightPackage.o mainP3-2.o
	g++ mainP3-2.o Package.o TwoDayPackage.o OvernightPackage.o -o Package

main.o: mainP3-2.cpp Package.h TwoDayPackage.h
	g++ -c mainP3-2.cpp

Package.o: Package.cpp Package.h
	g++ -c Package.cpp

TwoDayPackage.o: TwoDayPackage.cpp TwoDayPackage.h
	g++ -c TwoDayPackage.cpp

OvernightPackage.o: OvernightPackage.cpp OvernightPackage.h
	g++ -c OvernightPackage.cpp

clean:
	rm *o Package