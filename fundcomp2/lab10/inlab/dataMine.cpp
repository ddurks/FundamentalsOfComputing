//David Durkin
//Fund Comp II
//DataMine.cpp

#include "DataMine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

DataMine::DataMine(){
	//Open file
	string file1;
	string file2;
	cout << "Please provide the names of two plain text files." << endl;
	cout << "File 1: ";
	cin >> file1;
	cout << "File 2: ";
	cin >> file2;

	ifstream ifile1;
	ifile1.open(file1);

	//Read in data into two separate vectors
	if(ifile1.is_open()){
		string word;
		while(ifile1 >> word){
			words1.push_back(word);
		}
	}
	else{
		cerr << "Error opening file 1." << endl;
		exit(1);
	}

	ifstream ifile2;
	ifile2.open(file2);

	if(ifile2.is_open()){
		string word;
		while(ifile2 >> word){
			words2.push_back(word);
		}
	}
	else{
		cerr << "Error opening file 2." << endl;
		exit(1);
	}
}


void DataMine::strip(){
	//Set each string in both vectors to lowercase, strip punctuation
	for(int i = 0; i < words1.size(); i++){
		transform(words1[i].begin(), words1[i].end(), words1[i].begin(), ::tolower);
		words1[i] = removePunc(words1[i]);
	}
	for(int i = 0; i < words2.size(); i++){
		transform(words2[i].begin(), words2[i].end(), words2[i].begin(), ::tolower);
		words2[i] = removePunc(words2[i]);
	}
}

//Display the unique words and their counts
void DataMine::displayUnique(){
	//load all strings from both vectors into maps
	map<string, int> unique;
	map<string, int> uniqueCount;
	for(int i = 0; i < words1.size(); i++){
		unique[words1[i]]++;
	}
	for(int i = 0; i < words2.size(); i++){
		uniqueCount[words2[i]]++;
	}
	int uniqueWords = 0;
	//Count the number of unique words in the "unique" vector AKA the first file
	for ( map<string, int>::iterator it=unique.begin(); it!=unique.end(); ++it){
		//cout << it->first << " => " << it->second << endl;
		if (it->second == 1){
			uniqueWords++;
		}
	}

	//Display the number of unique words in file 1
	cout << "There are " << uniqueWords << " unique words in the first file." << endl;
	//Display the words and their counts from file 2
	cout << endl << "Second file (Word => Count):" << endl;
	for ( map<string, int>::iterator it=uniqueCount.begin(); it!=uniqueCount.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}
}

//Remove punctuation from a given string
string DataMine::removePunc(string in){
	for(int i = 0; i < in.length(); i++){
		if(ispunct(in[i])){
			in.erase(i, 1);
		}
	}
	return in;
}

//Compute the Jaccard Similarity Coefficient of the two files
void DataMine::Jaccard(){
	//Load all of the strings from each file into sets
	set<string> first, second;
	for(int i = 0; i < words1.size(); i++){
		first.insert(words1[i]);
	}
	for(int i = 0; i < words2.size(); i++){
		second.insert(words2[i]);
	}

	//Determine the intersection of the two files
	set<string> intersect;
	set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(intersect, intersect.begin()));

	//Determine the union of the two files
	set<string> theunion;
	set_union(first.begin(), first.end(), second.begin(), second.end(), inserter(theunion, theunion.begin()));

	//Calculate the Jaccard Coefficient by dividing the intersection by the union
	//The expected Jaccard Coefficient using faust10.txt and randj.txt is .238834
	double jaccard = double(intersect.size())/double(theunion.size());

	//print the coefficient
	cout << "The Jaccard Similarity coefficient is " << jaccard << endl;
}

//Print out each file (used mostly for testing)
void DataMine::print(){
	for(int i = 0; i < words1.size(); i++){
		cout << words1[i] << " ";
	}
	cout << endl;
	cout << endl;
	for(int j = 0; j < words1.size(); j++){
		cout << words2[j] << " ";
	}
	cout << endl;
}