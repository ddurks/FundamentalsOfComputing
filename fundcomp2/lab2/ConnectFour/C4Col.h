//David Durkin
//Fund Comp II
//C4Col.h

//C4Col class declaration
class C4Col{

public:
	//Constructor
	C4Col();
	int isFull();
	char getDisc(int);
	int getMaxDiscs();
	void addDisc(char);
	C4Col operator+=(char);

private:
	int numDiscs;
	int maxDiscs;
	char discs[6];

};