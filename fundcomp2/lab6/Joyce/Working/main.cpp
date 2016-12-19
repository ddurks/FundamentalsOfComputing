//David Durkin
//Fund Comp II
//Lab 5 Driver for part 2

#include "Puzzle.h"
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

int main(){

	//reads in sodoku.txt file for the starting board, returns error message if it does not exist
	ifstream numFile("sudoku.txt");
	while(!numFile){
		cout << "Please quit the program and add a file named sodoku.txt to the directory" << endl;
	}

	//reads in board from file, creates a vector of the numbers, reads the vector into a puzzle class object named sodoku
	istream_iterator<int> start(numFile), end;
	vector<int> numbers(start, end);
	Puzzle sudoku(numbers);

	sudoku.print();

	sudoku.solve();

	sudoku.print();

	return 0;
}