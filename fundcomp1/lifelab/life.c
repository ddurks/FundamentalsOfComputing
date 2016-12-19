//David Durkin
//The Game of Life Program
//Based on the rules found on Wikipedia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//Set the dimensions of the board
#define BWIDTH	40
#define BHEIGHT 40

void initialize_board(int board[BWIDTH][BHEIGHT]);
int xadd(int, int);
int yadd(int, int);
int find_neighbors(int board[BWIDTH][BHEIGHT], int, int);
void play(int board[BWIDTH][BHEIGHT]);
void print(int board[BWIDTH][BHEIGHT]);
void from_file(int board[BWIDTH][BHEIGHT], char *);
void interactive_mode(int board[BWIDTH][BHEIGHT]);

//Main function
int main (int argc, char *argv[]){
	
	int	board[BWIDTH][BHEIGHT];

	initialize_board(board);

	if (argc == 1){	
		interactive_mode(board);
	}

	else if (argc == 2){	
		from_file(board,argv[1]);	
	}

	else{	
		printf("Too many input arguments.");
	}
}

//Set up the board to all 0s
void initialize_board(int board[BWIDTH][BHEIGHT]){
	int	i;
	int j;

	for(i=0; i<BWIDTH; i++){
		for(j=0; j<BHEIGHT; j++){ 
			board[i][j] = 0;
		}
	}
}

//Add to the width index, wrapping around if the index is off the board
int xadd(int i, int a){
	i += a;
	
	while(i < 0){ 
		i += BWIDTH;
	}
	while(i >= BWIDTH){
		i -= BWIDTH;
	}
	
	return i;
}

//Add to the height index, wrapping around if the index is off the board
int yadd(int i, int a){
	i += a;
	
	while(i < 0){ 
		i += BHEIGHT;
	}
	while(i >= BHEIGHT){ 
		i -= BHEIGHT;
	}
	
	return i;
}

//Find the number of neighbors at cell a, b
int find_neighbors(int board[BWIDTH][BHEIGHT], int a, int b){
	int	i;
	int j;
	int count = 0;

	//Go to the cells around the given cell
	for(i=-1; i<=1; i++){ 
		for(j=-1; j<=1; j++){
			//Only count if at least one of i,j isn't zero 
			//Uses the wrapping add functions in case point is off the board.
			if(i || j){
				if (board[xadd(a,i)][yadd(b,j)]) count++;
			}
		}
	}
	return count;
}

//Play the game of life based on the rules
void play(int board[BWIDTH][BHEIGHT]){
/*
	RULES(From Wikipedia):

	1) Any live cell with fewer than two live neighbours dies, 
		as if caused by under-population.
	2) Any live cell with two or three live neighbours lives on 
		to the next generation.
	3) Any live cell with more than three live neighbours dies, 
		as if by over-population.
	4) Any dead cell with exactly three live neighbours becomes a live cell, 
		as if by reproduction.
*/
	int	i;
	int j;
	int neighbors;
	int newboard[BWIDTH][BHEIGHT];

	//For each individual cell, apply the rules
	for(i=0; i<BWIDTH; i++){ 
		for(j=0; j<BHEIGHT; j++){
			neighbors = find_neighbors(board, i, j);
		
			//Rule 2
			if(neighbors == 2) newboard[i][j] = board[i][j];
		
			//Rule 4/Rule 2
			if(neighbors == 3) newboard[i][j] = 1;
		
			//Rule 1
			if(neighbors < 2) newboard[i][j] = 0;
		
			//Rule 3
			if(neighbors > 3) newboard[i][j] = 0;
		}
	}

	//Copy the new board onto the old board
	for(i=0; i<BWIDTH; i++){ 
		for(j=0; j<BHEIGHT; j++){
			board[i][j] = newboard[i][j];
		}
	}
}

//Print the game of life board
void print(int board[BWIDTH][BHEIGHT]){
	int	i; 
	int j;

	for(j=0; j<BHEIGHT; j++){
		for(i=0; i<BWIDTH; i++) {
			//Prints an x if board[i][j] is a 1, prints a space if it is a 0
			printf("%c", board[i][j] ? 'x' : ' ');
		}
		printf("\n");
	}

}

//Read a file and create a game of life board accordingly
void from_file(int board[BWIDTH][BHEIGHT], char *name) {
	FILE *fp;
	int	i = 0;

	//Character input array
	char inputc[1000][1];
	//Integer input array
	int inputi[1000][2];

	fp = fopen(name, "r");

	if (fp == NULL){
		printf("Error opening file");
	}

	while(inputc[i][0]!='p'){

		//Scan the file, one line at a time, for chars and ints
		//Put them into the proper arrays
		fscanf(fp, "%c %d %d", &inputc[i][0], &inputi[i][0], &inputi[i][1]);

		//behaves accordingly based on each line found in the input file
		switch(inputc[i][0]){
				case 'a':
					board[inputi[i][0]][inputi[i][1]] = 1;
					break;
				case 'r':
					board[inputi[i][0]][inputi[i][1]] = 0 ;
					break;
				case 'n':
					play(board);
					break;
				case 'q':
					exit(0);
					break;
				case 'p':
					//Runs the game indefinitely
					while(1){
						print(board);
						play(board);
						usleep(50000);
						printf("\033[2J\033[H");
					}
					break;
		}

		i++;
		//In case the file exceeds the buffer
		if(i>=1000){
			printf("input file exceeded 100 lines");
			break;
		}
	}
	
	fclose(fp);
}

//Executes interactive mode, waiting for user input and behaving accordingly.
void interactive_mode(int board[BWIDTH][BHEIGHT]){
	char choice;
	int a, b, c, d;
	
	while(1){
			printf("You are now in interactive mode.\n");
			printf("a - new live cell\n");
			printf("r - remove current cell\n");
			printf("n - move to the next iteration\n");
			printf("q - quit the program\n");
			printf("p - play the game continuously (Ctrl-C to stop)\n");
			scanf("%c",&choice);
		
			//behaves according to user input
			switch(choice){
				case 'a':
					printf("Enter an x and y coordinate for a new live cell: ");
					scanf("%d %d",&a,&b);
					board[a][b] = 1;
					break;
				case 'r':
					printf("Ender an x and y coordinate where a cell should be removed: ");
					scanf("%d %d",&c,&d);
					board[c][d] = 0;
					break;
				case 'n':
					play(board);
					break;
				case 'q':
					exit(0);
					break;
				case 'p':
					//Runs the game indefinitely
					while(1){
						print(board);
						play(board);
						usleep(50000);
						printf("\033[2J\033[H");
					}
					break;		
			}
			
			if(choice == 'p') break;

			print(board);
	}
}


