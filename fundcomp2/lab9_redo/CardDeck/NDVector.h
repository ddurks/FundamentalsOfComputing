//David Durkin
//FundComp II
//NDVector.h
//Typedefed implementation and declaration

#ifndef NDVECTOR_H
#define NDVECTOR_H
#include <iomanip>
#include <iostream>
using namespace std;

//NDVector class declaration
template <typename T>
class NDVector {
	public:
		//Default constructor with fallback value
		NDVector( int size = 10 );
		//Copy Constructor
		NDVector( const NDVector<T> & );
		//Destructor
		~NDVector();                    
		//Returns size
		int getSize() const;
		//Overloaded assignment operator
		const NDVector &operator=( const NDVector<T> & );  
		//Overloaded [] operator
		T& operator[](int offset) const{ return ptr[offset];}
		//Required member functions
		void push_back( T value);
		void increaseBuffer();
		void pop_back();
		void clear();
		T back();               

	private:
		//Array size
		int size;
		//Denotes how many slots are filled
		int current;
		//Pointer to first element of array
		T *ptr;
};

template<typename T>
NDVector<T>::NDVector( int sizeIN )  {
	size = ( sizeIN > 0 ? sizeIN : 10 ); // validate arraySize
  
  	//Allocate space for array
  	ptr = new T[size];
	//Set current spots filled to 0
	current = 0; 
} 

// Copy Constructor
template<typename T>
NDVector<T>::NDVector( const NDVector<T> &arrayToCopy )  : size( arrayToCopy.size )  {

  	ptr = new T[size];

  	for ( int i = 0; i < size; i++ ){
    	ptr[ i ] = arrayToCopy.ptr[i]; // copy into object
	}

}  // end of copy constructor

// Destructor
template<typename T>
NDVector<T>::~NDVector() {

  	delete [] ptr; // release pointer-based array space

} // end destructor

// getSize()
template<typename T>
int NDVector<T>::getSize() const  {

  	return (size); // number of elements in NDVector

} // end function getSize

template<typename T>
const NDVector<T> &NDVector<T>::operator=( const NDVector<T> &right ) {

	//Avoid self-assignment
  	if ( &right != this ) { 
    	if ( size != right.size ) {
     	 	//free space
     	 	delete [] ptr;
     	 	//resize
      		size = right.size;
      		//allocate space
      		ptr = new T[size];
    	} 
    	for ( int i = 0; i < size; i++ ){
    		//copy array into object
      		ptr[ i ] = right.ptr[i];
		}
  	} 

  return (*this);
}

template<typename T>
void NDVector<T>::push_back(T value){
	//adds a value to the back of the array
	if( current < size){
			ptr[current] = value;
			current++;
	}
	else{
		increaseBuffer();
		ptr[current] = value;
		current++;
	}
}

template<typename T>
void NDVector<T>::increaseBuffer(){
	size = 2*size;

	//Temporary pointer
	T *temp;
	//Allocate space
	temp = new T[size];

	for(int i = 0; i < size; i++){
		temp[i] = ptr[i];
	}
	
	delete [] ptr;
	
	ptr = temp;
}

template<typename T>
void NDVector<T>::pop_back(){
	//removes a value from the back of the array
	if(current > 0){
		ptr[current-1] = NULL;
		current-=1;
	}
	//if not possible, throw exception
	else{
		throw 20;
	}
}

template<typename T>
T NDVector<T>::back(){
	//return the final element in the array
	return ptr[current-1];
}


template<typename T>
void NDVector<T>::clear(){
	//Go through array and set all pointers to 0
	for(int i = 0; i < size; i++){
		ptr[i] = NULL;
	}	
}
#endif
