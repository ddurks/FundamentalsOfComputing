//David Durkin
//Fundamentals of Computing II
//BinaryTree.h

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include "Node.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
	BinaryTree(string filename= "pairs.txt");
	void makeNodes();
	void buildTree();
	void inOrder(Node<int> * curNode);
	int getLevels();
	Node<int>* getRoot();
	void preOrder(Node<int> * curNode);
	void postOrder(Node<int> * curNode);

private:
	vector<int> data;
	vector<string> labels;
	int numlevels;
	vector<Node<int> > pairs;
	vector<Node<int> > winners;
};

#endif