all: main.o BankAccount.o SavingsAccount.o CheckingAccount.o
	g++ main.o BankAccount.o SavingsAccount.o CheckingAccount.o -o pirateBank

main.o: main.cpp BankAccount.h CheckingAccount.h SavingsAccount.h
	g++ -c main.cpp 

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h
	g++ -c SavingsAccount.cpp 

CheckingAccount.o: CheckingAccount.cpp CheckingAccount.h
	g++ -c CheckingAccount.cpp

clean:
	rm *o pirateBank