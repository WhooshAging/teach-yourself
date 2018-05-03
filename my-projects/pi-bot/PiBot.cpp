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

string PiBot::toLower(string phrase) {
	string x;
	for (unsigned int i = 0; i < phrase.length(); i++) {
		x += tolower(phrase[i]);
	}
	return x;
}

string PiBot::cleanWord(string wordin, bool &isvalid) {
	if (wordin.size() > n_buckets + 1 || wordin == "," || wordin == "."
			|| wordin == "" || wordin == " ") {
		isvalid = false;
		return "";
	}
	// PROBLEM - the above will wrongly reject "Christmas," becuase with the , it is too long!
	// So chnaged to wordsisize() > n_buckets+1
	char banned_chars[] = { '@', '#', '^', '*', '(', ')', ',', ';', ':', '/',
			'\\', '?', '[', ']', '"', '\'', '<', '>', '&', '%', '+', '=', '!',
			'-', ' ', '~' };
	// & should be accepted on its own. %,! should be accepted at end only.
	wordin = toLower(wordin);
	stringstream out;

	bool banned;
	for (string::iterator it = wordin.begin(), end = wordin.end(); it != end;
			++it) {
		banned = false;
		//std::cout << "One character: " << *it << "\n";
		//*it = '*';
		for (unsigned int i = 0; i < sizeof(banned_chars); i++) {
			if (*it == banned_chars[i]) {
				if (wordin.size() == 1) {
					isvalid = false;
					return "";
				}
				if (*it == '%' && it != wordin.end() - 1) {
					banned = true;
					break;
				}
				if (*it == '\''
						&& (it == wordin.begin() || it == wordin.end() - 1)) {
					banned = true;
					break;
				}
				if (*it == '!' && it != wordin.end() - 1) {
					banned = true;
					break;
				}
				banned = true;
				break;


			}
		}
		if (!banned) {
			out << *it;
		}
	}

//	cout << "\rCurrent word: " << out.str() << flush;
	return out.str();
}

void PiBot::addFile(string fname) {
	//cout << " addFile() START " << endl;
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
	char exclaim = '!';

	string o_key;
//	int total = 0;
	int file_total = 0;

	bool is_valid_word;

	for (string line; getline(myf, line);) {
//		cout << line << endl;
//		cout << "\n" << endl;
		start = 0;
		end = line.find(delim);
		while (end != (int) string::npos) {
			is_valid_word = false;
			word = cleanWord(line.substr(start, end - start), is_valid_word);
			if (file_total % 250 == 0) {
				cout << setw(16) << "\rCurrent word: " << setw(12) << word
						<< setw(27) << " | Total words seen this file: "
						<< setw(7) << file_total << flush;
			}
//			cout << "TRACE ~~~~~~~~~~~~ CURRENT WORD ~~~~~~~~"
//					<< word << endl;

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
			if (word.size() <= n_buckets && word != "," && word != "."
					&& word != "") { // terrible fix here in case we encounter ',' or '.' in an entry
				if (o_key.size() == 0) {
					o_key = word;

					//cout << "\n\n~~~~~~TRACE~~~~~~ O KEY LESS THAN 0\n\n"
					//				<< endl;
				} else {
					if (word.back() == fullstop || word.back() == exclaim) {
						if (word != "...") {
//							cout << "FULL STOP! " << word << endl;
							word = word.substr(0, word.size() - 1);
//							cout << "WORD after cut: " << word << endl;
//							cout << "ADD FINAL ENTRY: " << o_key << " : "
							//								<< word + " " << endl;
							words->add(o_key, word, 1);
							o_key.clear();
						}
					} else {
//						cout << "ADD ENTRY: " << o_key << " : " << word << endl;
						words->add(o_key, word, 1);
						o_key +=  + " " + word;
					}
				}
				p_corpus->addWord(word);
			} else { // word is too long so reset
				// need to handle things like grill...THAT'S -> treated as a single word ==> how to deal with this? here
				//cout << "~~~Word Too Long~~~" << endl;
				o_key.clear();
			}
			start = end + delim.length();
			end = line.find(delim, start);
			file_total++;
		}
		// last word of the entire entry is not analysed by above for loop
		// do it manually here
		word = cleanWord(line.substr(start, end - start), is_valid_word);
//		cout << "TRACE ~~~~~~~~~~~~ FINAL WORD OUTSIDE LOOP~~~~~~~~"
//				<< word << endl;
		//cout << "word.size() : " << word.size() << endl;
		if (word.size() <= n_buckets && word != "," && word != "."
				&& word != "") {
			if (word.back() == fullstop || word.back() == exclaim) {
//				cout << "OUT OF LOOP FULL STOP! " << word << endl;
				word = word.substr(0, word.size() - 1);
//				cout << "OUT OF LOOP WORD after cut: " << word << endl;

			}
//			cout << "ADD FINAL ENTRY OUT OF LOOP: " << o_key << " : "
//					<< word + " " << endl;
			//	cout << "p corpus add word : " << word << endl;
			p_corpus->addWord(word);
			//	cout << "add to dict words" << endl;
			words->add(o_key, word, 1);
		}
		o_key.clear();
//		total += file_total;
//		file_total++;
		//cout << "~~~~~~~~~~~~TRACE ~~~~~~~~ FINAL TASK OF THIS LINE OF FILE"
		//		<< endl;
		//break; // only work on the first line in text file for now. Don't forget to delete!

	}
	//cout << "\n\n\n~~~~TRACE ~~~~ All lines processed\n\n" << endl;
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
	int j;
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
			output += "[" + next_word + "]";
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
				output += " [" + next_word + "]";
			} else {

//				for (unsigned int v = 0; v < inner_keys->size(); v++) {
//					cout << "inner_keys->size(): " << inner_keys->size()
//							<< endl;
//					cout << v << " " << (*inner_keys)[v] << flush;
//				}

//				cout << endl;

				for (unsigned int k = 0; k < inner_keys->size(); k++) {
					inner_key = (*inner_keys)[k];
//					cout << "Searching for inner key: " << inner_key << endl;
					inner_k_value = words->lookupInner(outer_key, inner_key);
//					cout << "Inner k value after lookup of" << inner_key << " " << inner_k_value << endl;
					if (inner_k_value > best) {
						best = inner_k_value;
						best_word = inner_key;
						next_word = best_word;
					}
//					cout << "After inner lookup, next_word is: " << next_word << endl;
				}
//				cout << "Digit of Pi : " << j << " | Word selected: "
//						<< best_word << endl;
				outer_key += " " + next_word;
				output += " " + next_word;
				inner_keys->clear();
			}
		}
	}
	delete inner_keys;
	inner_keys = NULL;
	return output;
}

