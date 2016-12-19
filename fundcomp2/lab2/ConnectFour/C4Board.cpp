//David Durkin
//Fund Comp II
//C4Board.cpp

#include <iostream>
#include "C4Board.h"
using namespace std;

//Constructor
C4Board::C4Board(){
	numCols = 7;
	board = new C4Col[numCols];
}

//Deconstructor
C4Board::~C4Board(){
	delete [] board;
}

//Display the Board with current discs placed
void C4Board::display(){
	cout << *this << endl;
}

//overloaded cout operator
ostream& operator<<(ostream& os, const C4Board & c4){
	int i;
	int j;
	//Column headers
	os << " 1 2 3 4 5 6 7 " << endl;

	//Cycle through each disk space and format output to look like a connect four board.
	for(i = c4.board[0].getMaxDiscs() - 1; i>=0; i--){
		for(j = 0; j< 7; j++){
			os << "|" << c4.board[j].getDisc(i);
		}
		os << "|" << endl;
	}

	return os;

}

//Play function
void C4Board::play(){

	int turn = 0;
	int colNum;
	int ai;

	//Makes sure user is only allowed to type 0 or 1
	do{
		cout << "Enter 1 to play with AI, Enter 0 to play two player" << endl;
		cin >> ai;
	}while(ai<0||ai>1);

	//Run the game continuously until someone wins	
	while(1){

		display();

		//If it is player 1's turn
		if((turn%2)+1==1){
			cout << "Player 1, which column would you like to place a disk in?" << endl;
			cin >> colNum;

			//Make sure column exists
			if(colNum < 1||colNum > 7){
				cout << "Not a valid column." << endl;
				cout << "Player 1, which column would you like to place a disk in?" << endl;
				cin >> colNum;
			}
			//Add disc to appropriate column
			else{
				board[colNum-1].addDisc('X');
			}

			//Check if player 1 wins, and, if so, display winning board
			if(didWin()){
				cout << "PLAYER 1 WINS!" << endl;
				display();
				cout << "GAME OVER" << endl;
				return;
			}

		}
		//If it is player 2's turn
		else if((turn%2)+1==2){
			
			if(ai){
				colNum = aiPlay();
			}
			else{
				cout << "Player 2, which column would you like to place a disk in?" << endl;
				cin >> colNum;
			}

			//Make sure column exists
			if(colNum < 1||colNum > 7){
				cout << "Not a valid column." << endl;
				cout << "Player 2, which column would you like to place a disk in?" << endl;
				cin >> colNum;
			}
			//Add disc to appropriate column
			else{
				board[colNum-1].addDisc('O');
			}

			//Check if player 2 wins, and, if so, display winning board
			if(didWin()){
				cout << "PLAYER 2 WINS!" << endl;
				display();
				cout << "GAME OVER" << endl;
				return;
			}
		}

		//Increment turn number
		turn++;
	}

}

//Tests the entire board for a winning situation, returns 1 for a win, 0 otherwise
int C4Board::didWin(){

	int i;
	int j;
	
	//Cycle through all disk spaces on the board
	for(j = board[0].getMaxDiscs() - 1; j>=0; j--){
		for(i = 0; i< numCols; i++){
			
			//Test for a horizontal win
			if( (i+3) < numCols && 
				board[i].getDisc(j)!=' ' && 
				board[i].getDisc(j)==board[i+1].getDisc(j) && 
				board[i].getDisc(j)==board[i+2].getDisc(j) && 
				board[i].getDisc(j)==board[i+3].getDisc(j)){
				
				return 1;
			}
			
			//Test for a vertical win
			if( (j+3) <= (board[0].getMaxDiscs() - 1) && 
				board[i].getDisc(j)!=' ' && 
				board[i].getDisc(j)==board[i].getDisc(j+1) && 
				board[i].getDisc(j)==board[i].getDisc(j+2) && 
				board[i].getDisc(j)==board[i].getDisc(j+3)){
				
				return 1;
			}

			//Test for a downwards diagonal win
			if( (i+3) < numCols && (j-3) >= 0 && 
				board[i].getDisc(j)!=' ' && 
				board[i].getDisc(j)==board[i+1].getDisc(j-1) && 
				board[i].getDisc(j)==board[i+2].getDisc(j-2) && 
				board[i].getDisc(j)==board[i+3].getDisc(j-3)){
				
				return 1;
			}
			
			//Test for an upwards diagonal win
			if( (i-3) >= 0 && (j-3) >= 0 && 
				board[i].getDisc(j)!=' ' && 
				board[i].getDisc(j)==board[i-1].getDisc(j-1) && 
				board[i].getDisc(j)==board[i-2].getDisc(j-2) && 
				board[i].getDisc(j)==board[i-3].getDisc(j-3)){
				
				return 1;
			}
		}

	}

	//Return 0 if no win is detected
	return 0;
}

//AI player function, returns a random column number 
int C4Board::aiPlay(){
	int col;

	//Ensure that the specified random column is not full
	do{

		col = rand()%7 + 1;

	}while(board[col].isFull());

	return col;
}





