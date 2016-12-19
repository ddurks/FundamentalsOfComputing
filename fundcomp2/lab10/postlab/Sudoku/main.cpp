//David Durkin
//Fund Comp II
//Lab 5 Driver for part 2

#include "Puzzle.h"
#include <iostream>

int main(){

	Puzzle<int> sudoku;
	cout << endl << "Original Puzzle:" << endl;
	sudoku.display();
	sudoku.solve();
	cout << "-----------------" << endl;
	cout << "Solved Puzzle:" << endl;
	sudoku.display();

	return 0;

}