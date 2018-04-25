//============================================================================
// Name        : digits-of-pi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : How I wish I could calculate Pi ... (3.141592 ... )
//				 Load of large corpus of text
//				 Build arrays of word lengths from 1-9
//				 Build new phrases to be used to remember digits of PI
//               Uses ML to pick sensible next words
//				 Twitter Bot? Tweets new phrases, replies to tweets specifying a word or # digits?
//============================================================================

#include <iostream>
#include "Corpus.h"
#include "utils.h"

using namespace std;

int main() {
	// max word length we have, stored in data/n.txt
	int N_BUCKETS = 9;

	// Make our Corpus, which is an array of Buckets, which have Vectors of words.
	// A Bucket's ID is the length of the words it holds.
	Corpus *p_corpus = new Corpus(N_BUCKETS);

	//  ~*~*~*~*~*~*~*~*~*~*~*~*~ DO STUFF WITH BUCKETS

	p_corpus->printSummary();

	// Set what we want to use for pi
	char my_pi[] = "31415926";
	int n_digits = sizeof(my_pi);

	// Get a phrase
	string phrase = p_corpus->generatePhrase(n_digits, my_pi);

	cout << endl;
	cout << "Our phrase to remember pi is: " << phrase << endl;

	// ~*~*~*~*~*~*~*~*~*~*~*~*~ STOP DOING STUFF WITH BUCKETS

	// CLEANUP
	delete p_corpus;
	p_corpus = NULL;
	return 0;
}

