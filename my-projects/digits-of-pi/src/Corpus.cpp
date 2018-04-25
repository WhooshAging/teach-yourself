/*
 * Corpus.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Cherie
 */

#include "Corpus.h"
#include "Bucket.h"
#include <iostream>
#include <iomanip> // setw - fix width for cout
using namespace std;

// BIRTH

Corpus::Corpus(int n) {
	cout << "Creating Corpus." << endl;
	cout << "Creating Buckets: " << flush;
	NBUCKETS = n;
	pcorpus = new Bucket[NBUCKETS]; // create pointer to array of 9 buckets
	cout << endl << endl;
}

// PRIVATE

Bucket * Corpus::getBucket(int n) const {
	return &pcorpus[n];
}

// PUBLIC

string Corpus::getRandomWord(int n) const {
	Bucket *p_bucket = getBucket(n);
	return p_bucket->getRandomWord();
}

int Corpus::getHowMany(int n) const {
	Bucket *p_bucket = getBucket(n);
	return p_bucket->getHowMany();
}

void Corpus::printSummary() const {
	// array of Buckets is indexed from 0
	// but obviously our min word length is 1
	cout << setw(6);
	cout << "Length" << flush;
	cout << "\t\t" << flush;
	cout << setw(9);
	cout << "Word" << flush;
	cout << "\t\t" << flush;
	cout << setw(5);
	cout << "Count" << endl;
	for (int i = 0; i < NBUCKETS; i++) {
		cout << i + 1 << flush;
		cout << "\t\t" << flush;
		cout << setw(9);
		string word = getRandomWord(i);
		cout << word << flush;
		cout << "\t\t" << flush;
		cout << getHowMany(i) << endl;
	}
	return;
}

string Corpus::generatePhrase(int n_ele, char s_digits[]) {
	// array of Buckets is indexed from 0
	// but obviously our min word length is 1
	// loop over our value of pi
	// select words of appropraite length
	string output;
	int j;
	for (int i = 0; i < n_ele - 1; i++) {
		j = s_digits[i] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		output += getRandomWord(j - 1); // becuase of indexing from 0, we need the -1 here
		output += " ";
	}
	return output;
}

// DEATH

Corpus::~Corpus() {
	cout << endl;
	// Don't forget to destory the buckets we created with new when we instantiated Corpus
	cout << "Destroying Buckets: " << flush;
	delete[] pcorpus;
	cout << endl;
	cout << "Destroying Corpus." << endl;
}

