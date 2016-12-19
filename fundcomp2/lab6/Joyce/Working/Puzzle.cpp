//David Durkin
//Fund Comp II
//Puzzle.cpp

#include "Puzzle.h"
#include <iostream>

//Prints the board
void Puzzle::print(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
				cout << possible[i][j][0] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

//Checks the row of a given input to see if placement is possible
int Puzzle::checkrow(int row, int col, int in){
	if(in == 0){
		return 1;
	}
	//loop through the row, check
	for(int i = 0; i < 9; i++){
			if(possible[row][i][0] == in){
				return 0;
			}
	}
	return 1;
}

//Checks the column of a given input to see if placement is possible
int Puzzle::checkcol(int row, int col, int in){
	if(in == 0){
		return 1;
	}
	//loop through the column, check
	for(int i = 0; i < 9; i++){
		if(possible[i][col][0] == in){
			return 0;
		}
	}
	return 1;
}

//Checks the corresponding square of 9 numbers to see if placement is possible
int Puzzle::checksquare(int row, int col, int in){
	if(in == 0){
		return 1;
	}
	//creates squares and loops through them
	int squareSize = 3;
	int topLeftX = row / 3 * 3;
	int topLeftY = col / 3 * 3;

	for(int i=0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(possible[topLeftX+i][topLeftY+j][0] == in){
				return 0;
			}

		}
	}
	return 1;
}

//Checks if the user has won, returns a 1 if yes, a 0 if no
int Puzzle::didSolve(){
	//loops through the board and checks for 0s
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(possible[i][j][0] == 0){
				return 0;
			}
		}
	}
	return 1;
}

void Puzzle::solve(){

	while(!didSolve()){
		for(int i=0; i < 9; i++){
			for(int j=0; j < 9; j++){
				if(possible[i][j][0] == 0){
					getPossible(i,j);
					getVal(i, j);
					singleton(i, j);
				}
			}
		}
	}
}

void Puzzle::singleton(int row, int col){
	int num = 0;
	int singletonRow = 0;
	int singletonCol = 0;
	cout << singletonRow << " ";

	for(int value= 1; value <= 9; value++){

		//ROW SINGLETONS
		for(int i=0; i<9; i++){
			if (possible[row][i][0]==0 && possible[row][i][value]==1){
				num++;
				if(num==1){
					singletonRow=row;
					singletonCol=i;
				}
			}
		}

		if(checkrow(singletonRow,singletonCol,value) && checkcol(singletonRow,singletonCol,value) 
			&& checksquare(singletonRow,singletonCol,value) && num==1){

			known(singletonRow,singletonCol,value);
		}

		num = 0;

		//COLUMN SINGLETONS
		for(int i=0; i<9; i++){
			if (possible[i][col][0]==0 && possible[row][col][value]==1){
				num++;
				if(num==1){
					singletonRow=i;
					singletonCol=col;
				}
			}
		}

		if(checkrow(singletonRow,singletonCol,value) && checkcol(singletonRow,singletonCol,value) 
			&& checksquare(singletonRow,singletonCol,value) && num==1){

			known(singletonRow,singletonCol,value);
		}

		num = 0;

		//SQUARE SINGLETONS
		int size = 3;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(possible[i][j][0] == 0 && possible[i][j][value] == 1){
					num++;
						if(num == 1){
							singletonRow = i;
							singletonCol = j;
						}
				}
			}

		}

		if(checkrow(singletonRow,singletonCol,value) && checkcol(singletonRow,singletonCol,value) 
			&& checksquare(singletonRow,singletonCol,value) && num==1){

			known(singletonRow,singletonCol,value);
		}

	}
}

void Puzzle::known(int row, int col, int in){
	
	possible[row][col][0]=in;

	for(int i=1;i<=9;i++){
		if(i!=in){
			possible[row][col][i]=0;
		}
	}
}

void Puzzle::getPossible(int row, int col){
	for(int k = 1; k <= 9; k++){
		if(checkrow(row, col, k) && checkcol(row, col, k) && checksquare(row, col, k)){
			possible[row][col][k] = 1;
		}
		else{
			possible[row][col][k] = 0;
		}
	}
}

void Puzzle::getVal(int row, int col){
	if(sumPossible(row, col) == 1){
		for(int i = 1; i <= 9; i++){
			if(possible[row][col][i]==1){
				known(row, col, i);
			}
		}
	}
}

int Puzzle::sumPossible(int row, int col){
	int sum = 0;
	for(int i = 1; i <= 9; i++){
		sum += possible[row][col][i];
	}
	return sum;
}

