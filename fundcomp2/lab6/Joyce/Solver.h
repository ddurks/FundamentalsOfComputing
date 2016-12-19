//Solver.h 
//John Joyce 2016
//Sudoku solver class header file
#ifndef Solver_h
#define Solver_h
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 

template <typename T>
class Solver {

	public: 
	Solver(); //default constructor 
	void Display(); //display board
	void Solve(); //attempts to solve the board using simply algorithm
	
	protected:
	vector<vector <T> > board; //2d vector representing the board
	vector<vector <vector <T> > > possVals; //possible values at each position
	bool replaceCell(int, int, T); //tries to replace a cell on the board -- returns true for success
	bool checkWin(); //checks the win of the game -- returns true for success
	void removePossibilities(); //removes possibilities from 3rd dimension of vector
	bool placePossibilities(); //places a value on the board if possible
	void removePossibilitiesForPosition(int i, int j); //removes possibilities for a specific position (row, grid, col)
	void DisplayFinalBoard(); //displays the final board after puzzle has been solved
	bool isSingleton(int, int, int); //checks if a certain value is a singleton
	void SingletonSolve(); // attempts to solve the board using singleton

};

//solver default constructor -- sets up the possible values 3D vector, and also the board 2D vector
template <typename T>
Solver<T>::Solver() {
	
	string fileName;
	cout << "Please enter a file name: "; //snag the filename for input
	cin >> fileName;
	//read in the file using ifstream and a temporary vector
	ifstream infile; 
	infile.open(fileName.c_str());
	//create temporary vector to initialize the sudoku board 
	vector<T> tempVec;
	T tempVar; 
	
	//create two temporary vectors to initialize the possible temporary vector
	vector<vector <T> > possTempVec1; 
	T possVar1; 
	vector<T> possTempVec2; 
        T possVar2; 
	
	for (int i = 0; i<9; i++){ //For each column
         	for(int j = 0 ; j < 9 ; j++){    //Read in a row into temp vect
                  	infile >> tempVar; //Store value 
                  	tempVec.push_back(tempVar); //push row into board vector
                  	
                  	//available variable simply says if the spot on the board is still available - 1 for yes, 0 for no
                  	int available; 
                  	if (tempVar != 0) available = 0; 
                  	else available = 1; 
                 
                  	//populate the possibilities 3D array
                  	for (int k=0; k<10; k++) {
                  		//first add whatever variable is on the current board
                  		if (k == 0) possTempVec2.push_back(tempVar); 
                  		possTempVec2.push_back(available); 
                  	}
                  	//push entire possibility vector into 3D vector
                  	possTempVec1.push_back(possTempVec2); 
                  	possTempVec2.clear(); //free memory
                  	
          	}
          	possVals.push_back(possTempVec1); //push back the possible temp vector
          	possTempVec1.clear(); //free memory
          	
          	board.push_back(tempVec);   //Push back the line just read)
          	tempVec.clear(); //Clear/recycle temporary vector
	}
}


//display the sudoku board
template <typename T> 
void Solver<T>::Display() {
	//loop through the 2d vector
	for (int i = 0; i<9; i++) {
		for (int j = 0; j < 9; j++) {
			//cout << board[i][j] << " "; //display entry on board
			
				for (int k = 0; k<10; k++) {
					//print out the possible values (3rd dimension of array)
					cout << possVals[i][j][k];
				} 
				cout << endl; 
		}
		cout << endl;  // print end line
	}

}


//begin solving the board using the simple algorithm
template <typename T> 
void Solver<T>::Solve() {
	//remove initial possibilities 
	removePossibilities(); 
	//attempt to solve simply first then use singleton solve if necessary
	while (!checkWin()) {
		//place and remove possibilities based on there being one option remaining
		bool didPlace = placePossibilities();
		//if we cannot place anymore, use the singleton solve. 
		if (!didPlace) {
			SingletonSolve();
		}
	}	
	//display the result of the simplesolve!
	DisplayFinalBoard(); 
	

}

//tries to complete solving the puzzle using the singleton method. 
template <typename T>
void Solver<T>::SingletonSolve() {
	
	removePossibilities(); 
	//Scan through the columns
	for (int i = 0; i<9; i++) {
		//scan through the rows
		for (int j = 0; j<9; j++) {
			//check if the spot on board is open
			if (possVals[i][j][0] == 0) {
				//check the possibilities
				for (int m = 1; m<10; m++) {
					if (possVals[i][j][m] == 1) {
						//check if this value is a singleton
						if (isSingleton(i, j, m)) possVals[i][j][0] = m; 
					}
				}
			}
		}
	}

}

//checks if certain value is a column singleton
template <typename T>
bool Solver<T>::isSingleton(int i, int j, int m) {
	for (int k = 0; k<9; k++) {
		if (possVals[i][k][0] == 0 && j != k) {
			//if the column contains another value with same possibility return false, value is not a singleton
			if (possVals[i][k][m] == 1) return false; 
		}
	}
	//if no others found return true
	return true; 
}


//removes possibilities from 3rd dimension of vector based on spots that have a value already
template <typename T>
void Solver<T>::removePossibilities() {
	//scan through the columns and rows
	for (int i = 0; i<9; i++) {
		for (int j =0; j<9; j++) {
			//if the spot on the board is unavailable, remove all possibilities from corresponding row, col, grid
			if (possVals[i][j][0] != 0) {
				removePossibilitiesForPosition(i, j); 
			}
		}
			
	}

}


//places a possibility based on one remaining option available
template <typename T>
bool Solver<T>::placePossibilities() {
	bool didPlace = 0; 
	for (int i =0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			if (possVals[i][j][0] == 0) {
				//check if there is one option left in the 3rd dimension of the vector. if so, place the corresponding value on board
				int count = 0; 
				int value; 
				for (int m = 1; m<10; m++) {
					
					if (possVals[i][j][m] == 1){
						count++; 
						value = m; 
					}
				}
				//place the corresponding possible value on the board if there is only one option remaining
				if (count == 1) {
					possVals[i][j][0] = value; 
					didPlace=1;
					//remove column, row, grid possibilities after placement
					removePossibilitiesForPosition(i, j); 
				}
			}
		}
	}
	return didPlace; 

}

//simple scans through the corresponding row, col, and grid of a position on the board and removes possibilities from 3rd dimension of vector
template <typename T>
void Solver<T>::removePossibilitiesForPosition(int i, int j) {
	//check current row
	for (int k = 0; k<9; k++) {
		for (int m=1; m<10; m++) {
			if (possVals[i][j][0] == m) {
				possVals[i][k][m] = 0; 
					
			}
		}
	}
				
	//check current col
	for (int k = 0; k<9; k++) {
		for (int m=1; m<10; m++) {
			if (possVals[i][j][0] == m) {
				possVals[k][j][m] = 0; 
			}
		}
	}
				
	//check current sub-grid 
	for (int r = i-i%3; r<(i-i%3+3); r++) {
		for (int c = j-j%3; c<(j-j%3+3); c++) {
			for (int m=1; m<10; m++) {
						
				if (possVals[i][j][0] == m) {
					possVals[r][c][m] = 0; 
				}
			}
						
		}
	}


}

//displays the board after the board has been solved
template <typename T>
void Solver<T>::DisplayFinalBoard() {
	//loop through the 2d vector
	for (int i = 0; i<9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << possVals[i][j][0] << " "; //display entry on board
		}
		cout << endl;  // print end line
	}

}

//looks for open spaces to check if a player has won a game
template <typename T>
bool Solver<T>::checkWin() {
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			if (possVals[i][j][0] == 0) return false; //if the board has open spaces return false
		}
	}
	//its a win!!! -- no open spaces left on the board
	return true; 
}

#endif
