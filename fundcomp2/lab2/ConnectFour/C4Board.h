//David Durkin
//Fund Comp II
//C4Board.h

#include "C4Col.h"
using namespace std;

//Declaration of member functions and variables in C4Col Class
class C4Board{

//Friend function overloaded cout
friend ostream& operator<<(ostream& os, const C4Board & board);

public:
	//Constructor
	C4Board();
	void display();
	void play();
	int aiPlay();
	//Deconstructor
	~C4Board();

private:
	int numCols;
	//Dynamic Memory allocatin
	C4Col *board;
	int didWin();
	
};