//David Durkin
//Fund Comp II
//Puzzle.h 
#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <fstream>
#include <iostream> 
#include <set>

//used auto whenever possible in order to use C++11

using namespace std; 

//Declaration of templated class with public and private members
template <typename T>
class Puzzle {

	public: 
	//Constructor
	Puzzle(); 
	//Member Functions
	int didSolve();
	void display(); 
	void solve();
	void removePossibleAt(int i, int j);    
	void removePossible(); 
	int elimination(); 
	
	private:
	//Multi Dimensional Vectors to hold puzzles and possible values
	vector<vector <T> > puzzle; 
	vector<vector <set <T> > > possible; 

};

//Constructor, reads input and fills arrays with the information
template <typename T>
Puzzle<T>::Puzzle(){
	
	cout << "David Durkin's Sudoku Solver" << endl;
	cout << "----------------------------" << endl;
	//Take input from user
	string file;
	cout << "Name of file containing puzzle: "; 
	cin >> file;
	
	//open file
	ifstream infile; 
	infile.open(file.c_str());

	//Temporary vectors and sets to aid in filling 2D vector of sets
	vector<T> temp1;
	T value;
	vector< set<int> > temp2;
	set<int> tempset;

	if(infile.is_open()){
		//Fill 2D vector of sets
		for(auto row = 0; row < 9; row++){
			for(auto col = 0; col <9; col++){
				infile >> value;
				temp1.push_back(value);

				for(auto k = 1; k <= 9; k++){
					tempset.insert(k);
				}

				temp2.push_back(tempset);
				tempset.clear();	
			}

			possible.push_back(temp2);
			temp2.clear();

			puzzle.push_back(temp1);
			temp1.clear();
		}
	}
	//Error message if file opening fails
	else{
		cerr << "Error opening file." << endl;
		exit(1);
	}
}

//Tests if the Puzzle has been solved, 1 for yes, 0 for no
template <typename T>
int Puzzle<T>::didSolve(){
	//loop through every position in the puzzle
	for(auto row = 0; row<9; row++){
		for(auto col = 0; col <9; col++){
			//if spot is unfilled, return 0
			if(puzzle[row][col] == 0){
				return 0;
			}
		}
	}

	return 1;
}

//Display the values stored in the puzzle vector
template <typename T> 
void Puzzle<T>::display(){
	//loop through the puzzle vector, display all values neatly
	for(auto i = 0; i <9; i++){
		for(auto j = 0; j < 9; j++){
			cout << puzzle[i][j] << ' ';
		}
		cout << endl;
	}
}

//Solve the puzzle using both regular elimination and the singleton algorithm
template <typename T> 
void Puzzle<T>::solve(){
	
	removePossible();

	while(!didSolve()){
		auto end = elimination();
	}

}

//Basic scanning/elimination algorithm
template <typename T>
int Puzzle<T>::elimination(){
	auto end = 0;

	for(auto row = 0; row < 9; row++){
		for(auto col = 0; col < 9; col++){
			//If there is only one remaining option for an open space, set the space to that value
			if(possible[row][col].size() == 1 && puzzle[row][col] == 0){
				puzzle[row][col] = *possible[row][col].begin();
				//Update the rest of the puzzle as a result of the new number
				removePossibleAt(row, col);
			}
		}
	}
	return end;
}

//Removes all possible values from any non-open indexes
template <typename T>
void Puzzle<T>::removePossible(){
	
	for(auto row = 0; row < 9; row++){
		for(auto col = 0; col < 9; col++){
			if(puzzle[row][col] !=0){
				removePossibleAt(row, col);
			}
		}
	}
}

//Removing all values that are no longer possible from the proper sets
template <typename T>
void Puzzle<T>::removePossibleAt(int row, int col){
	
	//check Row
	for(auto i = 0; i <9; i++){
		for(auto k = 1; k <=9; k++){
			if(puzzle[row][col] == k){
				possible[row][i].erase(k);
			}
		}
	}

	//Check Col
	for(auto i = 0; i <9; i++){
		for(auto k = 1; k <=9; k++){
			if(puzzle[row][col] == k){
				possible[i][col].erase(k);
			}
		}
	}

	//Check Small Square
	for(auto i = row-row%3; i<(row-row%3+3); i++){
		
		for(auto j = col-col%3; j<(col-col%3+3); j++){
			
			for(auto k=1; k<=9; k++){
						
				
				if(puzzle[row][col] == k){
					possible[i][j].erase(k); 
				}
			}
		}
	}
}

#endif
