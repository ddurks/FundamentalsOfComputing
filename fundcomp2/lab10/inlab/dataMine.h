//David Durkin
//Fund Comp II
//Data Mining program

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Class declaration
class DataMine {
public:
	DataMine();
	void print();
	void strip();
	string removePunc(string);
	void uniqueWords();
	void wordCounts();
	void displayUnique();
	void Jaccard();

private:
	//Vectors to hold all strings from each file
	vector<string> words1;
	vector<string> words2;
};