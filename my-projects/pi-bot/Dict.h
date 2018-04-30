/*
 * Dict.h
 *
 *  Created on: Apr 28, 2018
 *      Author: Dan
 */
#include <iostream>
#include <sstream>
#include <unordered_map> // c++ eqv of Python {}
#include <fstream> // read and write files
using namespace std;

#ifndef DICT_H_
#define DICT_H_

class Dict {
private:
	unordered_map<string, unordered_map<string, int> > *hash_tbl;
	// set our iterators, one for each umap we have
	// https://stackoverflow.com/questions/26281979/c-loop-through-map
	unordered_map<string, unordered_map<string, int> >::iterator it1;
	unordered_map<string, int>::iterator it2;
	// delimiters used for reading/writing our data strcutures
	string delim_outer;
	string delim_inner;

public:
	Dict();
	virtual ~Dict();
	void print();
	void add(string, string, int); // and a single db entry { key : { key : value } }
	void save();
	void load();
	string nextWord(string);
};

#endif /* DICT_H_ */

