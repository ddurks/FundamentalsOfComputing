//David Durkin
//FundComp II
//Node.h class typedefed declaration and implementation
#ifndef NODE_H
#define NODE_H
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
//forward declaration
class BinaryTree;

template<typename T> 
class Node{
	friend class BinaryTree; 

 	public:
 		//Constructor
  		Node(const T &, string);
  		T getData() const; 
		void setNode();
		string getLabel();
		Node<T> * getLeft();
		Node<T> * getRight();
		void setLeft(Node<T> *);
		void setRight(Node<T> *);

 	private:
 		//Node data
  		T data;
  		//Node label
  		string label;
  		//Left and right nodes
  		Node<T> *left;  
		Node<T> *right;
};

//constructor
template<typename T>
Node<T>::Node(const T &dataIN, string labelIN) :data(dataIN), label(labelIN), left(NULL), right(NULL) {}

//get the data of a node
template<typename T>
T Node<T>::getData(void) const {return data;}

//get the label of a node
template<typename T>
string Node<T>::getLabel(){
	return label;
}

//set the node, depending on which node has a larger value
template<typename T>
void Node<T>::setNode(){

	if (left->getData() <= right->getData()){
		data=left->getData();
		label=left->getLabel();
	}
	else{
		data=right->getData();
		label=right->getLabel();
	}
}

//get the left node
template<typename T>
Node<T> * Node<T>::getLeft(){
	return left;
}

//get the right node
template<typename T>
Node<T> * Node<T>::getRight(){
	return right;
}

//set the left node
template<typename T>
void Node<T>::setLeft(Node<T> *p){
	left = p;
}	

//set the right node
template<typename T>
void Node<T>::setRight(Node<T> *p){
	right = p;
}	
#endif

