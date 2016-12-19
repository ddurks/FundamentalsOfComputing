//David Durkin
//Fund Comp II
//Puzzle.h

#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <iostream>
using namespace std;

//Implementation of puzzle class, templated for different types
template <typename T>
class Puzzle{
	public:
		//Constructor
		Puzzle(vector<T> in){
			int a = 0;
			for(int i=0;i<9;i++){
				vector<T> row;
				for(int j=0;j<9;j++){
					row.push_back(in[a]);
					++a;
				}
				puzzle.push_back(row);
			}
		}
		//member functions
		void print();
		int add(int, int, T);
		int checkrow(int, int, T);
		int checkcol(int, int, T);
		int checksquare(int, int, T);
		int didWin();
	private:
		//Private data member vector containing the board
		vector< vector<T> > puzzle;
};

//Prints the board
template <typename T>
void Puzzle<T>::print(){
	for(int i = 0; i < puzzle.size(); i++){
		for(int j = 0; j < puzzle[i].size(); j++){
				cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

//checks if number can be placed using other functions, returns a 1 and places it
//if possible, returns a 0 and does not if it is not possible
template <typename T>
int Puzzle<T>::add(int row, int col, T in){
	if(checkrow(row, col, in) && checkcol(row, col, in) && checksquare(row, col, in)){
		puzzle[row][col] = in;
		return 1;
	}
	else{
		return 0;
	}
}

//Checks the row of a given input to see if placement is possible
template <typename T>
int Puzzle<T>::checkrow(int row, int col, T in){
	//loop through the row, check
	for(int i = 0; i < 9; i++){
		if(i != col){
			if(puzzle[row][i] == in && in != 0){
				return 0;
			}
		}
	}
	return 1;
}

//Checks the column of a given input to see if placement is possible
template <typename T>
int Puzzle<T>::checkcol(int row, int col, T in){
	//loop through the column, check
	for(int i = 0; i < 9; i++){
		if (i != row){
			if(puzzle[i][col] == in && in != 0){
				return 0;
			}
		}
	}
	return 1;
}

//Checks the corresponding square of 9 numbers to see if placement is possible
template <typename T>
int Puzzle<T>::checksquare(int row, int col, T in){
	//creates squares and loops through them
	int vsquare = row/3;
	int hsquare = col/3;

	for(int i = vsquare*3; i < (vsquare*3 + 3); i++){
		for(int j = hsquare*3; j < (hsquare*3 + 3); j++){
			if(!(i==row && j==col)){
				if(puzzle[row][col] == in && in != 0){
					return 0;
				}
			}
		}
	}
	return 1;
}

//Checks if the user has won, returns a 1 if yes, a 0 if no
template <typename T>
int Puzzle<T>::didWin(){
	//loops through the board and checks for 0s
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(puzzle[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
}

#endif