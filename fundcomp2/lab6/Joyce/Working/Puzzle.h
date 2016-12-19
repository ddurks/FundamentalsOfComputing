//David Durkin
//Fund Comp II
//Puzzle.h

#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <iostream>
using namespace std;

//Implementation of puzzle class, templated for different types
class Puzzle{
	public:
		//Constructor
		Puzzle(vector<int> in){
			int a = 0;
			for(int i=0;i<9;i++){
				vector<int> row;
				for(int j=0;j<9;j++){
					row.push_back(in[a]);
					++a;
				}
				puzzle.push_back(row);	
			}

			vector<int> oneD;
			for(int i=0; i<=9; i++){
				oneD.push_back(0);
			}

			vector<vector<int> > twoD;
			for(int i=0; i<9; i++){
				twoD.push_back(oneD);
			}

			for(int i=0; i<9; i++){
				possible.push_back(twoD);
			}

			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(puzzle[i][j] != 0){
						known(i, j, puzzle[i][j]);
					}
				}
			}
		}
		//member functions
		void print();
		int checkrow(int, int, int);
		int checkcol(int, int, int);
		int checksquare(int, int, int);
		int didSolve();
		void solve();
		void singleton(int, int);
		void known(int, int, int);
		void getPossible(int, int);
		void getVal(int, int);
		int sumPossible(int, int);
		int oneRemaining(int, int);		
	private:
		//Private data member vector containing the board
		vector< vector<int> > puzzle;
		vector< vector< vector<int> > > possible;
};


#endif