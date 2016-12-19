//David Durkin
//Fund Comp II
//Lab 5 Driver Part 1

#include "Puzzle.h"
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

int main(){

	//reads in sodoku.txt file for the starting board, returns error message if it does not exist
	ifstream numFile("sodoku.txt");
	while(!numFile){
		cout << "Please quit the program and add a file named sodoku.txt to the directory" << endl;
	}

	//reads in board from file, creates a vector of the numbers, reads the vector into a puzzle class object named sodoku
	istream_iterator<int> start(numFile), end;
	vector<int> numbers(start, end);
	Puzzle<int> sodoku(numbers);
	sodoku.print();

	cout << endl;

	ifstream wordFile("wordoku.txt");
	while(!wordFile){
		cout << "Please quit the program and add a file named wordoku.txt to the directory" << endl;
	}

	istream_iterator<char> start1(wordFile), end1;
	vector<char> characters(start1, end1);
	Puzzle<char> wordoku(characters);
	wordoku.print();


	return 0;
}