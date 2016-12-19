#ifndef _NODE_H_
#define _NODE_H_
#include <string>
#include <iostream>
using namespace std;

class BinaryTree; // forward declaration of List

template<typename T>   // templated node type
class Node {

	friend class BinaryTree;

public:
	Node(string inlabel, const T &);     // constructor
	T getData() const;
	string getLabel() const;   // get function
	void newFunc();
	void setData(int in);
	void setLabel(string in);
	void setChildren( Node<T> in1, Node<T> in2 );
	Node<T>* getLeft();
	Node<T>* getRight();
	Node<T> *left;
	Node<T> *right;

private:
	string label;
	T data;           // data for linked list node 

};

// NOTE:  all of the functions are in the .h file to overcome issues with
//        templates and linking

// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(string inlabel, const T &info) :label(inlabel),data(info),left(NULL),right(NULL) {}

// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { return data; }

//get label function
template<typename T>
string Node<T>::getLabel(void) const{ return label; }

//set data function
template<typename T>
void Node<T>::setData(int in){
	data = in;
}

//set label function
template<typename T>
void Node<T>::setLabel(string in){
	label = in;
}

//set Children function
template<typename T>
void Node<T>::setChildren(Node<T> in1, Node<T> in2){
	left = &in1;
	right = &in2;
}

//get left function
template<typename T>
Node<T>* Node<T>::getLeft(){
	return left;
}

//get right function
template<typename T>
Node<T>* Node<T>::getRight(){
	return right;
}

//new function which sets the parent as the larger of the children
template<typename T>
void Node<T>::newFunc(){
	if( left->getData() > right->getData() ){
		setData(left->getData());
		setLabel(left->getLabel());
	}
	else if( left->getData() < right->getData() ){
		setData(right->getData());
		setLabel(right->getLabel());
	}
	else{
		setData(left->getData());
		setLabel(left->getLabel());
	}
}
#endif