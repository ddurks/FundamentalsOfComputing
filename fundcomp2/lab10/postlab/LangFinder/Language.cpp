//David Durkin
//Fund Comp II
//Language.cpp

#include "Language.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//Constructor
Language::Language(){
	
	//Read the English dictionary into a set
	ifstream ifile1;
	ifile1.open("english.txt");
	if(ifile1.is_open()){
		string word;
		while(ifile1 >> word){
			english.insert(word);
		}
	}
	else{
		cerr << "Error openining file 1." << endl;
		exit(1);
	}

	//Read the spanish dictionary into a set
	ifstream ifile2;
	ifile2.open("spanish.txt");
	if(ifile2.is_open()){
		string word;
		while(ifile2 >> word){
			spanish.insert(word);
		}
	}
	else{
		cerr << "Error opening file 2." << endl;
		exit(1);
	}

	//Read the words from the plain text file into a vector
	ifstream ifile3;
	ifile3.open("language.txt");
	if(ifile3.is_open()){
		string word;
		while(ifile3 >> word){
			langVec.push_back(word);
		}
		//Remove punctuation and set to lower case
		strip();
		//Place all updated strings from the vector into a set
		for (int i = 0; i < langVec.size(); ++i){
			language.insert(langVec[i]);
		}
	}
	else{
		cerr << "Error opening file 3." << endl;
		exit(1);
	}
}

//Function to set all strings to lower case and remove punctuation
void Language::strip(){
	for(int i = 0; i < langVec.size(); i++){
		//set to lower
		transform(langVec[i].begin(), langVec[i].end(), langVec[i].begin(), ::tolower);
		//remove punctuation
		langVec[i] = removePunc(langVec[i]);
	}
}

//Removes punctuation from an individual string by iterating through the characters
string Language::removePunc(string in){
	for(int i = 0; i < in.length(); i++){
		if(ispunct(in[i])){
			in.erase(i, 1);
		}
	}
	return in;
}

//Determine which Language the file is in based on the size of the intersections
void Language::findLang(){
	set<string> engintersect;
	set_intersection(language.begin(), language.end(), english.begin(), english.end(), inserter(engintersect, engintersect.begin()));

	set<string> spanintersect;
	set_intersection(language.begin(), language.end(), spanish.begin(), spanish.end(), inserter(spanintersect, spanintersect.begin()));

	//If the intersection with one dictionary is larger than another, then guess that it is in that language
	if( engintersect.size() >= spanintersect.size() ){
		cout << "This file appears to be in English!" << endl;
	}	
	else{
		cout << "This file appears to be in Spanish!" << endl;
	}
}

//Print out the original file (Used for testing)
void Language::print(){
	set<string> s = language;
	cout << "Set contains:" << endl;
  	while (!s.empty()) {      // while elements in the set
    	cout << *s.begin() << ' ';
    	s.erase(s.begin());
  	}
}