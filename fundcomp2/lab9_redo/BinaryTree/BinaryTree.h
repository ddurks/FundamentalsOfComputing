//David Durkin
//FundComp II
//BinaryTree.h declaration and implementation

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h" 
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class BinaryTree{
 	public:
 		//Constructor
  		BinaryTree(string);
		//Three traversal functions
		void inOrder(Node<int> *);
		void preOrder(Node<int> *);
		void postOrder(Node<int> *);
		//search function
		Node<int>* search(int, Node<int> *);

 	private:
		//name of file
		string file;
 		//Composition. first element in tree
  		Node<int> *first;
};

// constructor as well as main operation of tournament bracket
BinaryTree::BinaryTree(string file) : first(NULL){

	//Read in File
	ifstream fileIn;
	fileIn.open(file.c_str());
	//Create a vector to hold tournament bracket
	vector<Node<int> *> bracket;
	//Create proper nodes and put them in bracket accordingly
	while (!fileIn.eof()){
		string name;
		int seed;

		fileIn >> name;
		fileIn >> seed;

		Node<int> *temporary = new Node<int>(seed,name);
		bracket.push_back(temporary);
	}

	cout << endl << "First Round:" << endl;
	//Print out first 16 teams
	for (int i = 0; i < bracket.size() - 1; i++){
		cout << bracket[i]->getLabel() << ", " << bracket[i]->getData() << endl;
	}

	//Temporary parent node
	Node<int> *tempParent;
	//New bracket vector for new sets of nodes
	vector<Node<int> *> newBracket;
	
	cout << endl << "Next Round: " << endl;
	//for each round, set up nodes
	while (bracket.size() > 1){
		for (int i = 0; i < bracket.size()-1; i += 2){
			//properly set nodes
			tempParent = new Node<int>(0,"temporary");
			tempParent->setLeft(bracket[i]);
			tempParent->setRight(bracket[i + 1]);
			tempParent->setNode();
			//add temporary parent node to new Bracket vector
			newBracket.push_back(tempParent);
		}
		//set bracket vector equal vector of nodes
		bracket=newBracket;

		//Print out teams and seeds
		for (int i = 0; i < bracket.size(); i++){
			cout << bracket[i]->getLabel() << ", " << bracket[i]->getData() << endl;
		}
		//Clear new bracket for use in other rounds
		newBracket.clear();
		cout << endl << "Next Round:" << endl;
	}

	//Make sure to reset the first node
	first = bracket[0];

	cout << "InOrder: " << endl;
	inOrder(first);
	cout << endl << endl;
	cout << "PreOrder: " << endl;
	preOrder(first);
	cout << endl << endl;
	cout << "PostOrder: " << endl;
	postOrder(first);
	cout << endl << endl;

	//Prompt the user to use the search function
	int searchFor;
	cout << "~SEARCH FUNCTIONALITY~ Enter a seed: ";
	cin >> searchFor;

	while(searchFor < 1 || searchFor > 16 ){
		cout << "Error: Seed must be betwixt 1 and 16" << endl << "Enter a seed:";
		cin >> searchFor;
	}
	Node<int> *found;
	found = search(searchFor,first);
	cout << found->getLabel() << endl;
}

//inOrder transversal function
void BinaryTree::inOrder(Node<int> *root){
	if (root != NULL){
		inOrder(root->left);
		cout << root->getLabel() << ", " << root->getData() << endl;
		inOrder(root->right);
	}
}

//preOrder transversal function
void BinaryTree::preOrder(Node<int> *root){
	if (root != NULL){
		cout << root->getLabel() << ", " << root->getData() << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

//postOrder transversal function
void BinaryTree::postOrder(Node<int> *root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->getLabel() << ", " << root->getData() << endl;
	}
}	

//Recursive search function
Node<int>* BinaryTree::search(int value, Node<int> *root){
		if (root == NULL){
			return NULL;
		}
		else{
			if (root->getData() == value){
				return root;
			}
			else{
				Node<int>* left = search(value, root->getLeft());
				Node<int>* right = search(value, root->getRight());
				if(left!=NULL){
					return left;
				}
				else{
					return right;
				}
			}
		}
}
#endif

