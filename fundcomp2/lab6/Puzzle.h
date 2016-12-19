//David Durkin
//Fund Comp II
//Puzzle.h 
#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <fstream>
#include <iostream> 

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
	int isSingleton(int, int, int); 
	void singleton();  
	void removePossible(); 
	int elimination(); 
	
	private:
	//Multi Dimensional Vectors to hold puzzles and possible values
	vector<vector <T> > puzzle; 
	vector<vector <vector <T> > > possible; 

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
	
	//Three temporary vectors for initializing puzzle and possible value vectors
	vector<T> temp1;
	T tempVar1; 
	vector<vector <T> > temp2; 
	T possVar1; 
	vector<T> posstemp2; 
     T tempVar2; 
	
	//loop through possible row and column values
	for(int row = 0; row<9; row++){ 
         	
         	for(int col = 0 ; col < 9 ; col++){    
                  	
                  	infile >> tempVar1; 
                  	temp1.push_back(tempVar1); 
                  	
                  	//If open = 1, spot is available, if 0, it is not
                  	int open; 
                  	
                  	if(tempVar1 != 0){ 
                  		
                  		open = 0;
                  	} 
                  	else{
                  		
                  		open = 1;
                  	} 
                 
                 	//fill the possible values 3D array
                  	for(int k=0; k<=9; k++){
                  		
                  		//Add the variables which are in the read in puzzle
                  		if(k == 0){ 
                  			posstemp2.push_back(tempVar1); 
                  		}
                  			posstemp2.push_back(open); 
                  		
                  	}
                  	
                  	temp2.push_back(posstemp2); 
                  	posstemp2.clear(); 
                  	
          	}
          	//Finally assign the puzzle and possible values array the last temp vector
          	possible.push_back(temp2); 
          	temp2.clear(); 
          	
          	puzzle.push_back(temp1);   
          	temp1.clear(); 
	}
}

//Tests if the Puzzle has been solved, 1 for yes, 0 for no
template <typename T>
int Puzzle<T>::didSolve(){
	//loop through every position in the puzzle
	for(int row = 0; row<9; row++){
		
		for(int col = 0; col<9; col++){
			
			//if there is a 0 found, the puzzle is not solved
			if(possible[row][col][0] == 0){
				
				return 0;
			}
		}
	}
	return 1; 
}

//Display the values stored in the possible vector
template <typename T> 
void Puzzle<T>::display(){
	
	//loop through every position in the column
	for(int row = 0; row<9; row++){
		
		for(int col = 0; col < 9; col++){
			
			//print the zeroth element, or the puzzle value of each row, col index
			cout << possible[row][col][0] << " "; 
		}
		
		cout << endl; 
	}

}

//Solve the puzzle using both regular elimination and the singleton algorithm
template <typename T> 
void Puzzle<T>::solve(){
	
	//remove possible values at any already filled indexes
	removePossible(); 
	
	//loops continuously while 0s remain in the puzzle
	while(!didSolve()){
		
		//run the elimination algorithm, return its status
		int end = elimination();
		
		//if the elimination process has been carried out as far as possible
		if(!end){
			//Run the singleton algorithm
			singleton();
		}
	}	
	
}

//Basic scanning/elimination algorithm
template <typename T>
int Puzzle<T>::elimination(){
	int end = 0; 

	//Loop through indexes
	for(int row =0; row<9; row++){
		
		for(int col = 0; col<9; col++){
			
			//If only one option remains in dimension 3, replace the puzzle value witht that one
			if(possible[row][col][0] == 0){
				
				//counter and value variables
				int count = 0; 
				int value; 
				
				//loop through possible values
				for(int val = 1; val<=9; val++){
					
					//If a value works, increase the count, set the value
					if(possible[row][col][val] == 1){
						
						count++; 
						value = val; 
					
					}
				}
				
				//If there is only one third dimension index left, set the puzzle accordingly
				if(count == 1){
					
					possible[row][col][0] = value; 
					end=1;
					removePossibleAt(row, col); 
				}
			}
		}
	}
	//return the status of the process
	return end; 

}

template <typename T>
void Puzzle<T>::singleton(){
	
	//loop through possible indexes in the puzzle 
	for(int i = 0; i<9; i++){
		
		for(int j = 0; j<9; j++){
			
			//If the index combination is open (equal to zero)
			if(possible[i][j][0] == 0){
				
				//loop through possible values
				for(int k = 1; k<=9; k++){
					
					//If the value is a possibility
					if(possible[i][j][k] == 1){
						
						//If the value is a singleton calling the is Singleton Function
						if(isSingleton(i, j, k)){ 
							
							//set the Corresponding puzzle valu after identifying a singleton
							possible[i][j][0] = k; 
						}
					}
				}
			}
		}
	}

}

//Test for a singleton in any given row
template <typename T>
int Puzzle<T>::isSingleton(int i, int j, int m){
	
	//loop through all columns of the puzzle
	for(int k = 0; k<9; k++){
		
		//If another index in the same row but a different column has the same possible value, it is not a singleton
		if(possible[i][k][0] == 0 && j != k){
			
			if(possible[i][k][m] == 1){
				
				return 0; 
			}
		}
	}
	return 1; 
}

//Removes all possible values from any non-open indexes
template <typename T>
void Puzzle<T>::removePossible(){
	
	//Loop through all row, column indexes of the board
	for(int row = 0; row<9; row++){
		
		for(int col =0; col<9; col++){
			
			//If the spot is not open
			if(possible[row][col][0] != 0){
				
				//Reomove all possibilities in the 3D part at that combination
				removePossibleAt(row, col); 
			}
		}
			
	}

}

//Set all 3D array values of a given index to 0, removing all possible values
template <typename T>
void Puzzle<T>::removePossibleAt(int row, int col){
	
	//check Row
	for(int k = 0; k<9; k++){
		
		for(int l=1; l<10; l++){
			
			if(possible[row][col][0] == l){
				
				possible[row][k][l] = 0; 
					
			}
		}
	}
	
	//Check Col
	for(int k = 0; k<9; k++){
		
		for(int l=1; l<10; l++){
			
			if(possible[row][col][0] == l){
				
				possible[k][col][l] = 0; 
			}
		}
	}
	
	//Check small Square			
	for(int i = row-row%3; i<(row-row%3+3); i++){
		
		for(int j = col-col%3; j<(col-col%3+3); j++){
			
			for(int k=1; k<=9; k++){
						
				
				if(possible[row][col][0] == k){
					possible[i][j][k] = 0; 
				}
			}
		}
	}


}

#endif
