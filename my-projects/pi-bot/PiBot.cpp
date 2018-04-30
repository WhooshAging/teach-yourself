/*
 * PiBot.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: Cherie
 */

#include "PiBot.h"

PiBot::PiBot() {
	n_buckets = 9;
	p_corpus = new Corpus(n_buckets);

	cout << "Starting DIct" << endl;
	words = new Dict();


}

PiBot::~PiBot() {
	delete words;
	delete p_corpus;

}

void PiBot::addEntry(string word1, string word2, int n_many) {
	words->add(word1,word2,n_many);
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
	cout << " addFile() START " << endl;
	stringstream ss;
	ss << "data/textin/";
	ss << fname;
	ss << ".txt";

	fstream myf;
	myf.open(ss.str());
	string word;
	string sentance;
	string delim = " ";

	int start, end;

	char fullstop = '.';
	char comma = ',';

	const int MAXLENGTH = 9;

	string o_key;

	for (string line; getline(myf, line);) {
		cout << line << endl;
		cout << "\n" << endl;
		start = 0;
		end = line.find(delim);
		while (end != (int) string::npos) {
			cout << "TRACE ~~~~~~~~~~~~ CURRENT WORD ~~~~~~~~" << line.substr(start, end - start) << endl;
			word = line.substr(start, end - start);
			//cout << "END OF WORD ~~~~~~~~ " << word.back() << endl;
			// we now have individual words
			// if word > maxlength reset o_key
			// if last char full stop, strip, add as inner key and reset o key
			// if last char comma, strip, add as inner key, and add to o key
			// otherwise, add as inner key, add to u key
			// grill...THAT'S -> treated as a single word ==> how to deal with this?
			// etc). -> removes the . adds etc) as key
			// etc.) -> does nothing, adds etc.)
			// need to deal with "..."
			//
			//
			//
			// cout << word << " : " << flush;
			//
			if (word.size() < MAXLENGTH && word != ",") { // terrible fix here in case we encounter ' , ' in an entry
				if (o_key.size() == 0) {
					if (word.back() == comma) {
						o_key = word.substr(0, word.size() - 1) + " ";
					} else {
					o_key = word + " ";
					}
					cout << "\n\n~~~~~~TRACE~~~~~~ O KEY LESS THAN 0\n\n" << endl;
				} else {
					if (word.back() == fullstop) {
						if (word != "...") {
						word = word.substr(0, word.size() - 1);
						cout << "ADD FINAL ENTRY: " << o_key << " : "
								<< word + " "
								<< endl;
						words->add(o_key, word, 1);
						o_key.clear();
						}
					} else if (word.back() == comma) {
						word = word.substr(0, word.size() - 1);
						cout << "ADD ENTRY: " << o_key << " : "
								<< word + " "
								<< endl;
						words->add(o_key, word, 1);
						o_key += word + " ";
					} else {
						cout << "ADD ENTRY: " << o_key << " : " << word << endl;
						words->add(o_key, word, 1);
						o_key += word + " ";
					}
				}
				p_corpus->addWord(word);
			} else { // word is too long so reset
				// need to handle things like grill...THAT'S -> treated as a single word ==> how to deal with this? here
				cout << "~~~Word Too Long~~~" << endl;
				o_key.clear();
			}
			start = end + delim.length();
						end = line.find(delim, start);
		}
		// last word of the entire entry is not analysed by above for loop
		// do it manually here
		word = line.substr(start, end - start);
		cout << "TRACE ~~~~~~~~~~~~ FINAL WORD OUTSIDE LOOP~~~~~~~~" << line.substr(start, end - start) << endl;
		cout << "word.size() : " << word.size() << endl;
		if (word.size() < MAXLENGTH && word.size() != 0) {
			word = line.substr(start, end - start);
			if (word.back() == fullstop) {
				word = word.substr(0, word.size() - 1);
			}
			cout << "ADD FINAL ENTRY OUT OF LOOP: " << o_key << " : "
					<< word + " " << endl;
			cout << "p corpus add word : " << word << endl;
			p_corpus->addWord(word);
			cout << "add to dict words" << endl;
			words->add(o_key, word, 1);
		}
		o_key.clear();
		cout << "~~~~~~~~~~~~TRACE ~~~~~~~~ FINAL TASK OF THIS LINE OF FILE" << endl;
		//break; // only work on the first line in text file for now. Don't forget to delete!

	}
	cout << "\n\n\n~~~~TRACE ~~~~ All lines processed\n\n" << endl;
	myf.close();
	return;
}

string PiBot::randomPhrase(int n_ele, char s_digits[]) {
	return p_corpus->generatePhrase(n_ele, s_digits);
}

string PiBot::genPhrase(int n_ele, char s_digits[]) {
	string output;
	string next_word;
	string key;
	int j;
	for (int i = 0; i < n_ele - 1; i++) {
		j = s_digits[i] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		if (i==0) {
			next_word = p_corpus->getRandomWord(j - 1);
			output += next_word;
		} else {
			next_word = words->nextWord(output);
			output += " " + next_word;
		}
		}
	return output;
}
