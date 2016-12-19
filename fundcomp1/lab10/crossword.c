#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 16
#define MAXWORDS 20


int prompt_user(char [MAXWORDS][MAXLEN]);
void create_board(char [MAXWORDS][MAXLEN]);
int compare(const void *, const void *);
void sort_words(int newlen, char [newlen][MAXLEN]);
void place_first_word(char *, char[MAXLEN][MAXLEN]);
int place_word(char *, char [MAXLEN][MAXLEN]);
int can_place_word(char *, char [MAXLEN][MAXLEN], int row, int col);
int can_place_letter(char, char [MAXLEN][MAXLEN], int row, int col);
void print_solution_board(char [MAXLEN][MAXLEN]);
void print_puzzle_board(char [MAXLEN][MAXLEN]);

int main(void){

	char board[MAXLEN][MAXLEN], words[MAXWORDS][MAXLEN], clues[MAXWORDS][100];

	int newlen = prompt_user(words);

	//Creates a new array, trimming off the null part
	char newwords[newlen][MAXLEN];
	int i;
	int j;
	for(i=0;i<newlen;i++){
		for(j=0;j<MAXLEN;j++){
			newwords[i][j]=words[i][j];
		}
	}
	
	create_board(board);

	sort_words(newlen,words);

	place_first_word(words[0],board);

	//Cycles through the word list, places them, or tells the user that they could not be placed
	int k;
	for(k=1;k<newlen;k++){
		if(!place_word(words[k], board)){
			printf("Can't place words");
		}
	}

	print_solution_board(board);
	print_puzzle_board(board);
}

//Prompts the user for words and places them into an array, returns length of that array
int prompt_user(char words[MAXWORDS][MAXLEN]){

	printf("Enter up to 20 words, max 15 characters each. End your list with a period");
	printf("\n");

	int i = 0;
	do{
		scanf("%s",words[i]);
		i++;
		if(i>=MAXWORDS){
			printf("You have exceeded the 20 word maximum.");
			break;
		}
	}while((words[i-1][0]!='.'));

	return i-1;
}

//Creates the board array
void create_board(char board[MAXLEN][MAXLEN]){
	int i;
	int j;
	for(i=0;i<MAXLEN;i++){
		for(j=0;j<MAXLEN;j++){
			board[i][j] = '.';
		}
	}
}

//Compares the length of two words against each other
int compare(const void * a, const void * b){
	const char fa = strlen((const char *)a);
	const char fb = strlen((const char *)b);
	return (fa<fb) - (fa>fb);
}

//Sorts the words by length from largest to smallest
void sort_words(int newlen, char words[newlen][MAXLEN]){
	qsort(words,newlen,MAXLEN,compare);
}

//Places the first word in the middle of the board
void place_first_word(char *words, char board[MAXLEN][MAXLEN]){
	int length = strlen(words);
	int diff = MAXLEN - length;
	int indent = diff/2;
	int i = 0;
	int j;
	for(j=indent;j<MAXLEN;j++){
		if(words[i]=='\0') break;

		board[8][j] = words[i];
		i++;
	}
}

//Tests whether a word can be placed on the board
int place_word(char *words, char board[MAXLEN][MAXLEN]){
	int row;
	int col;
	int place = 0;
	for(row=0;row<MAXLEN;row++){
		for(col=0;col<MAXLEN;col++){

			if(can_place_word(words, board, row, col)){
				place++;
			}

		}
	}
	if(place==0){
		return 0;
	}
	return 1;
}

//tests whether a word can be placed at coordinates (row, col)
int can_place_word(char *words, char board[MAXLEN][MAXLEN], int row, int col){

	int len = strlen(words);
	int vertplace = 0;
	int horizplace = 0;
	
	//attempt to place vertically from row, col
	if(row+len<=15){
		int i;
		int j;
		vertplace = 1;
		for(j=0;j<len;j++){
			for(i=row;i<row+len;i++){
				if(!can_place_letter(words[j],board,i,col)){
					vertplace = 0;
					break;
				}
				if(words[j]==board[i][col]){
					vertplace = 1;
				}
			}

		}
	}
	
	//attempt to place horizontally from row, col
	else if(col+len<=15){
		int k;
		int l;
		for(l=0;l<len;l++){
			for(k=col;k<col+len;k++){
				if(!can_place_letter(words[l],board,row,k)){
					horizplace = 0;
					break;
				}
				if(words[l]==board[row][k]){
					horizplace = 1;
				}
			}
		}
	}

	//If it is possible to place vertically, place the word and return success
	if(vertplace){

		return vertplace;
	}

	//If it is possible to place horizontally, place the word and return success
	if(horizplace){

		return horizplace;
	}

	return 0;
}

//Tests whether a letter can be places at the coordinates (row, col)
int can_place_letter(char letter,char board[MAXLEN][MAXLEN], int row, int col){
	
	if((board[row][col]==letter) || (board[row][col]=='.')){
		return 1;
	}

	return 0;

}

//Prints the solution board
void print_solution_board(char board[MAXLEN][MAXLEN]){
	int i;
	int j;
	for(i=0;i<MAXLEN;i++){
		for(j=0;j<MAXLEN;j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

//Prints the board in puzzle form
void print_puzzle_board(char board[MAXLEN][MAXLEN]){
	int i;
	int j;
	for(i=0;i<MAXLEN;i++){
		for(j=0;j<MAXLEN;j++){
			if(board[i][j]=='.'){
				board[i][j] = '#';
			}
			else if( (board[i][j]>=65&&board[i][j]<=90) || (board[i][j]>=97&&board[i][j]<=122)){
				board[i][j] = ' ';
			}
				printf("%c",board[i][j]);
		}
		printf("\n");
	}

}






