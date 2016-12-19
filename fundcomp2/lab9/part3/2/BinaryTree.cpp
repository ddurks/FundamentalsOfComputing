//David Durkin
//BinaryTree class implementation

#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <math.h>

//Constructor
BinaryTree::BinaryTree(string filename){
	//Open file
	ifstream ifile;
	ifile.open(filename);

	//Read in data into two separate arrays
	if(ifile.is_open()){
		int num;
		string label;
		while(ifile >> label && ifile >> num){
			data.push_back(num);
			labels.push_back(label);
		}
	}
	else{
		cerr << "Error openining file";
		exit(1);
	}
}

//Return the number of levels in the tree
int BinaryTree::getLevels(){ return numlevels; }

//Make nodes for all given label, data pairs
void BinaryTree::makeNodes(){
	for(int i = 0; i<data.size(); i++){
		Node<int> pair(labels[i],data[i]);
		pairs.push_back(pair);
	}
	numlevels = log(pairs.size())/log(2) + 1;
}

//build binary tree witht the given pairs
void BinaryTree::buildTree(){
	//parent node array
	vector<Node<int> > winners;
	//Carry out the new function on each
	for(int i = 0; i < pairs.size(); i+=2){
		Node<int> winner("round", i);
		winner.setChildren(pairs[i],pairs[i+1]);
		winner.newFunc();
		winners.push_back(winner); 
	}
	//setting pairs equal to the parent nodes
	pairs = winners;

	//recursive call
	if(pairs.size() >= 2){
		buildTree();
	}
}

//inOrder transversal function
void BinaryTree::inOrder(Node<int> *curNode){
	if (curNode != NULL){
		inOrder(curNode->getLeft());
		cout << curNode->getLabel() << endl;
		inOrder(curNode->getRight());

	}
}

//preOrder transversal function
void BinaryTree::preOrder(Node<int> *curNode){
	if (curNode!=NULL){
		cout << curNode->getLabel() << endl;
		preOrder(curNode->getLeft());
		preOrder(curNode->getRight());
	}
}

//postOrder transversal function
void BinaryTree::postOrder(Node<int> *curNode){
	if(curNode!=NULL){
		postOrder(curNode->getLeft());
		postOrder(curNode->getRight());
		cout << curNode->getLabel() << endl;
	}
}

//get Root function
Node<int>* BinaryTree::getRoot(){
	Node<int> *root = &pairs[0];
	return root;
}