/*
 * Bucket.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Cherie
 */

#include "Bucket.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h> // rand, srand
#include <ctime> // to use with srand to seed rand

using namespace std;

int Bucket::count = 0;

Bucket::Bucket() {
	// seed rand func
	srand(time(NULL));
	how_many = 0;
	id = ++count;
	cout << id << " " << flush;
	loadData();

}

Bucket::~Bucket() {
	cout << id << " " << flush;
}

int Bucket::getID() const {
	return id;
}

void Bucket::loadData() {
	ifstream myf;
	stringstream ss;
	ss << "data/";
	ss << id;
	ss << ".txt";
	myf.open(ss.str());
	int count = 0;
	string x;

	while (myf >> x) {
		if (count == 0) {
			int n = 0;
			stringstream int_str(x);
			int_str >> n;
			how_many = n;
		} else {
			words.push_back(x);
		}
		count++;
	}
	myf.close();
}

string Bucket::getRandomWord() const {
	if (words.size() == 0) {
		return "";
	} else {
	int choice = rand() % words.size();
	return words[choice];
	}
}
