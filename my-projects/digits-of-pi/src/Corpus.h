/*
 * Corpus.h
 *
 *  Created on: Apr 25, 2018
 *      Author: Cherie
 */

#include "Bucket.h"

#ifndef CORPUS_H_
#define CORPUS_H_

class Corpus {
private:
	// vars
	Bucket *pcorpus = pcorpus; // an array to hold the Buckets
	int NBUCKETS;
	// funcs
	Bucket * getBucket(int) const;
public:
	// birth
	Corpus(int);
	// funcs
	int getHowMany(int n) const; // Give word length, Return how many words a bucket has
	void printSummary() const; // prints length, random word, count of all buckets
	string getRandomWord(int) const; // Give word length, Return random word from that bucket
	string generatePhrase(int, char[]); // Give how many and the digits, Return a valid phrase.
	// death
	virtual ~Corpus();
};

#endif /* CORPUS_H_ */
