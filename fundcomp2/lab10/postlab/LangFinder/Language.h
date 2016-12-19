//David Durkin
//Fund Comp II
//Language.h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

//Class Declaration
class Language {
public:
	Language();
	void print();
	void strip();
	string removePunc(string);
	void findLang();

private:
	//Sets and vectors to hold data
	vector<string> langVec;
	set<string> english;
	set<string> spanish;
	set<string> language;
};