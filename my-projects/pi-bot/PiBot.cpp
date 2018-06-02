/*
 * PiBot.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: Cherie
 */

#include <iomanip>
#include "PiBot.h"

PiBot::PiBot() {
	cout << "Starting Bot." << endl;
	n_buckets = 9;
	p_corpus = new Corpus(n_buckets);

	//cout << "Starting DIct" << endl;
	words = new Dict();

}

PiBot::~PiBot() {
	delete words;
	delete p_corpus;

}

void PiBot::addEntry(string word1, string word2, int n_many) {
	words->add(word1, word2, n_many);
}

void PiBot::printDict() const {
	words->print();
}

void PiBot::printCorpusSummary() {
	p_corpus->printSummary();
}

void PiBot::loadCorpus() {
	p_corpus->loadCorpus();
}

void PiBot::saveCorpus() {
	p_corpus->saveCorpus();
}
void PiBot::loadDict() {
	words->load();
}
void PiBot::saveDict() {
	words->save();
}

void PiBot::addFile(string fname) {
	stringstream ss;
	ss << "data/textin/";
	ss << fname;
	ss << ".txt";

	fstream myf;
	myf.open(ss.str());
	string word;
	string delim = " ";
	int start, end;
	char fullstop = '.';
	string o_key;
	int file_total = 0;

	for (string line; getline(myf, line);) {
		if (file_total % 250 == 0) {
			cout << setw(16) << "\rCurrent word: " << setw(12) << word
					<< setw(27) << " | Total words seen this file: "
					<< setw(7) << file_total << flush;
		}
		start = 0;
		end = line.find(delim);
		while (end != (int) string::npos) {
			word = line.substr(start, end - start);
			if (word.size() <= n_buckets) {
				if (start == 0) {
					o_key = word.substr(0, word.size());
				}
				else {
					if (word.back() == fullstop) {
						word = word.substr(0, word.size() - 1);
						words->add(o_key, word, 1);
						o_key.clear();
					}
					else {
						words->add(o_key, word, 1);
						o_key += +" " + word;
					}
				}
				p_corpus->addWord(word);
			}
			else {
				o_key.clear(); // word is too long so reset our outer key and don't add
			}
			start = end + delim.length();
			end = line.find(delim, start);
			file_total++;
		}
		word = line.substr(start, end - start);
		word = word.substr(0, word.size() - 1);
		words->add(o_key, word, 1);
		o_key.clear();
	}

	myf.close();
	cout << endl;
	return;
}

string PiBot::randomPhrase(int n_ele, char s_digits[]) {
	return p_corpus->generatePhrase(n_ele, s_digits);
}

string PiBot::genPhrase(int n_ele, char s_digits[]) {
	string output;
	string next_word;
	string inner_key;
	string outer_key;
	vector<string> *inner_keys = new vector<string>;
	unsigned int j;
	int best;
	string best_word;
	int inner_k_value;
	for (int i = 0; i < n_ele - 1; i++) {
		inner_k_value = 0;
		best = 0;
		j = s_digits[i] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		//cout << "Current digit of pi we are using: " << j << endl;
		if (i == 0) {
//			cout << "PiBot genPhrase i=0" << endl;
			next_word = p_corpus->getRandomWord(j - 1);
//			cout << "Digit of Pi : " << j << " | i=0 Word selected: " << next_word << endl;
			outer_key = next_word;
			output += "[" + next_word + "]" + " ";
		} else {
//			cout << "PiBot genPhrase i not 0" << endl;
//			cout << "Outer key is now: " << outer_key << endl;
			words->lookupOuter(outer_key, inner_keys);
//			cout << "\nChoices for inner keys are: " << endl;
//			for (unsigned int x=0; x<inner_keys->size();x++) {
//				cout << (*inner_keys)[x] << endl;
//			}
//			cout << "inner_keys->size(): " << inner_keys->size() << endl;

			// inner_keys could be empty
			// we randomly pick a seed word for the first digit from our buckets
			// there's no guarantee it's an outer key ...
			// should we just return a new random coice?
			// and mark this is such with []

			// or should we hold two lists in buckets? one for inner and one for outer?
			// but a bucket object shouldnt care about that

			if (inner_keys->size() == 0) {
				// it wan't an outer key, we dont have an inner keys to pick from
				// just random a new entry
//				cout << "Inner keys == 0." << endl;
				next_word = p_corpus->getRandomWord(j - 1);
//				cout << "Digit of Pi : " << j << " | i=0 Word selected: " << next_word << endl;
				outer_key = next_word;
				output += "[" + next_word + "]" + " ";
			} else {

//				for (unsigned int v = 0; v < inner_keys->size(); v++) {
//					cout << "inner_keys->size(): " << inner_keys->size()
//							<< endl;
//					cout << v << " " << (*inner_keys)[v] << flush;
//				}

//				cout << endl;

				for (unsigned int k = 0; k < inner_keys->size(); k++) {
					inner_key = (*inner_keys)[k];
					if (inner_key.size() == j) {
//					cout << "Searching for inner key: " << inner_key << endl;
						inner_k_value = words->lookupInner(outer_key,
								inner_key);
//					cout << "Inner k value after lookup of" << inner_key << " " << inner_k_value << endl;
						if (inner_k_value > best) {
							best = inner_k_value;
							best_word = inner_key;
							next_word = best_word;
						}
//					cout << "After inner lookup, next_word is: " << next_word << endl;
					}
				}
				if (best == 0) {
					// we didn't find a valid inner key
					next_word = p_corpus->getRandomWord(j - 1);
	//				cout << "Digit of Pi : " << j << " | i=0 Word selected: " << next_word << endl;
					outer_key = next_word;
					output += "[" + next_word + "]" + " ";
				} else {
//				cout << "Digit of Pi : " << j << " | Word selected: "
//						<< best_word << endl;
				outer_key += " " + next_word;
				output += next_word + " ";
				inner_keys->clear();
				}
			}
		}
	}
	delete inner_keys;
	inner_keys = NULL;
	return output;
}

