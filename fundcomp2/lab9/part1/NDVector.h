//David Durkin
//NDVector.h

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
using namespace std;

//Class Declaration
template<typename T>
class NDVector{
public:
	NDVector();
	NDVector( const NDVector<T> &V);
	~NDVector();
	const NDVector &operator=(const NDVector<T> &V);
	T& operator[](int offset){ 
		return start[offset]; 
	}
	int getSize();
	void push_back(const T& value);
	void pop_back();
	T getBack();
	void clear();

private:
	int size;
	T *start;

};

//Constructor, initializes things
template<typename T>
NDVector<T>::NDVector(){
	int sizeIN = 1;
	size = ( sizeIN > 0 ? sizeIN : 10 );
	start = new T[ size ];
} 

//Copy Constructor
template<typename T>
NDVector<T>::NDVector( const NDVector<T> &arrayToCopy ) : size( arrayToCopy.size ) {
	start = new T[size];

	for (int i = 0; i < size; i++ ){
		start[i] = arrayToCopy.start[i];
	}
}

//Deconstructor
template<typename T>
NDVector<T>::~NDVector(){
	delete [] start;
}

//Equals operator overloaded
template<typename T>
const NDVector<T> &NDVector<T>::operator=( const NDVector<T> &right ) {
	if ( &right != this ){
		if ( size != right.size ){
			delete [] start;
			size = right.size;
			start = new T[size];
		}
		for( int i = 0; i < size; i++){
			start[i] = right.start[i];
		}
	}
	return (*this);
}

//getSize function
template<typename T>
int NDVector<T>::getSize(){
	return size;
}

//push back function
template<typename T>
void NDVector<T>::push_back(const T & value){
	start[size++] = value;
}

//pop back function
template<typename T>
void NDVector<T>::pop_back(){
	delete start[size];
	size--;
}

//get back function
template<typename T>
T NDVector<T>::getBack(){
	return start[size];
}

#endif