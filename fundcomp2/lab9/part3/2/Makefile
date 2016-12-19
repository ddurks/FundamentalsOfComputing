all: main.o Node.o BinaryTree.o
	g++ main.o Node.o BinaryTree.o -o Node

main.o: main.cpp
	g++ -c main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *o Node