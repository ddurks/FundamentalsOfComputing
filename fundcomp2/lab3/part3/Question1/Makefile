all: mainP3-1.o BankAccount.o checkingAccount.o
	g++ mainP3-1.o BankAccount.o checkingAccount.o -o Composition

mainP3-1.o: mainP3-1.cpp
	g++ -c mainP3-1.cpp

BankAccount.o: BankAccount.h
	g++ -c BankAccount.cpp

checkingAccount.o: checkingAccount.h
	g++ -c checkingAccount.cpp

clean:
	rm *o Composition