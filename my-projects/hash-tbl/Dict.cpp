/*
 * Dict.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: Dan
 */

#include "Dict.h"

Dict::Dict() {
	//cout << "Default Constructor." << endl;
	//hash_tbl[""][""] = 0;
	hash_tbl = new unordered_map<string, unordered_map<string, int> >;
	delim_outer = "~";
	delim_inner = "|";
}

Dict::~Dict() {
	//cout << "Default Destructor." << endl;
	// clean up
	delete hash_tbl;
	hash_tbl = NULL;
	//if (!hash_tbl) {
	//	cout << "Pointer deleted and memory freed" << endl;
}

void Dict::print() {
	cout << endl;
	// iterate over outer and inner keys
	for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
		for (it2 = (*hash_tbl)[it1->first].begin();
				it2 != (*hash_tbl)[it1->first].end(); it2++) {
			cout << "{ " << it1->first << " : { " << it2->first << " : "
					<< it2->second << " } }" << endl;
		}
	}
	cout << endl;
	return;
}

void Dict::add(string word1, string word2, int nseen) {
	//
	// ADDING ENTRIES
	//
	// 3 Cases: new outer key
	//			existing outer, new inner
	//			existing outer, existing inner
	//
	cout << " ... " << flush;

	// dict is empty so must be the first entry, just add it.

	if ((*hash_tbl).size() == 0) {
		//cout << "New key : First Entry: " << word1 << endl;
		unordered_map<string, int> data_to_add = { { word2, nseen } };
		(*hash_tbl)[word1] = data_to_add;

	} else {
		// check if word1 in outer keys
		int outer_counter = 0;
		for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
			//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl.size(): " << hash_tbl.size() << endl;
			//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE outer_counter: " << outer_counter << endl;
			//cout << "Checking Outer Key: " << it1->first << endl;
			if (it1->first == word1) {
				// DUPLICATE OUTER KEY
				//cout << "... Outer Keys match" << endl;

				// Check if word2 in inner keys
				int inner_counter = 0;
				for (it2 = (*hash_tbl)[it1->first].begin(); // it1->first is key string, hash_tbl[it1->first] is the inner umap
						it2 != (*hash_tbl)[it1->first].end(); it2++) {

					//cout << "{ " << it1->first << " : { " << it2->first << " : " << it2->second << " } }" << endl;
					//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl[it1->first].size(): " << hash_tbl[it1->first].size() << endl;
					//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE inner_counter: " << inner_counter << endl;
					//cout << "Checking Inner Key: " << it2->first << endl;

					// INNER KEY MATCHES - UPDATE THE MAP

					if (it2->first == word2) {
						//cout << "... ... Inner keys match" << endl;
						// update the count we hold by count we provided
						it2->second += nseen;

					} else if (inner_counter
							== (int) (*hash_tbl)[it1->first].size() - 1) { // Checked all, sure new inner key

							// NEW INNER KEY - Insert a new pair(s,i) into umap of outer key {k : {s:i} }
						//cout << "... ... New Inner Key" << endl;

						// insert word2:nseen into dict[outer_key] = {}

						(*hash_tbl)[it1->first].insert(
								pair<string, int>(word2, nseen));

						break;
					}
					inner_counter++;
				}
				break;
			} else if (outer_counter == (int) hash_tbl->size() - 1) { // Checked, sure new outer key

			// NEW OUTER KEY - Create a new umap<s,i> and add k : {s,i} to our outer umap
			//cout << "New key : " << word1 << endl;

				unordered_map<string, int> data_to_add = { { word2, nseen } };
				(*hash_tbl)[word1] = data_to_add;
				break;
			}
			outer_counter++;
		}
	}

	return;

}

void Dict::save() {
	// https://stackoverflow.com/questions/8121428/c-serializing-a-stdmap-to-a-file
	//save our dict to disk
	// each o member (outer key) on a new line
	// special character to split each o member
	// each i member (inner key) on a new line
	// value on next line
	// special character to split each i member

	cout << "Saving Data." << endl;

	ofstream myf;
	myf.open("data/data.dict");

	for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
		myf << delim_outer;
		myf << "\n";
		myf << it1->first;
		for (it2 = (*hash_tbl)[it1->first].begin();
				it2 != (*hash_tbl)[it1->first].end(); it2++) {
			myf << "\n";
			myf << it2->first;
			myf << "\n";
			myf << it2->second;
			myf << "\n";
			myf << delim_inner;
		}
		myf << "\n";
	}
	myf.close();
	return;
}

void Dict::load() {
	// load our dict from disk and re-create it in memory
	cout << "Loading Data." << endl;
	cout << "Adding entries: " << flush;

	string x;
	string outer_key = "";
	string inner_key = "";
	string previous_line = "";
	int value = 0;

	ifstream myf;
	myf.open("data/data.dict");

	while (myf >> x) {
		if (previous_line != "") {
			// if it is, we're at the first line of file
			if (previous_line == "~") {
				// new outer key
				// so new chunk of inner keys comming
				// therefore reset all
				outer_key = x;
				inner_key = "";
				value = 0;
			} else if (previous_line == "|") {
				// new inner key
				inner_key = x;
			} else {
				// prev line is not a special char
				// if we are now looking at an int, then go ahead and add
				// otherwise we must be looking at an inner key
				// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

				stringstream check;
				check << x;
				check >> value;
				if (check.good()) {
					// not an int, a string ==> inner key
					inner_key = x;
				} else if (value == 0 && x[0] != 0) {
					// not an int, a string ==> inner key
					inner_key = x;
				} else {
					// we are looking at an int
					// ==> safe to add entry
					add(outer_key, inner_key, value);
					value = 0;
				}
			}
		}
		previous_line = x;
	}
	cout << endl;
}

string Dict::nextWord() {
	// Given an input string, return the next word based on frequency
	// Loop through the nested array, check all values, return key of highest value

	return "";

}

void Dict::addFile(string fname) {

	stringstream ss;
	ss << "data/text-in/";
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

	for (string line; getline(myf, line);) {
		cout << line << endl;
		cout << "\n" << endl;
		start = 0;
		end = line.find(delim);
		while (end != (int) string::npos) {
			// cout << line.substr(start, end - start) << endl;
			word = line.substr(start, end - start);
			//cout << "END OF WORD ~~~~~~~~ " << word.back() << endl;
			if (word.back() == fullstop) {
				sentance += word.substr(0,word.size()-1) + " ";
				cout << sentance << endl;
				//cout << "\n" << endl;
				sentance.clear();
			} else if (word.back() == comma) {
				sentance += word.substr(0,word.size()-1) + " ";
			} else {
				sentance += word + " ";
			}
			start = end + delim.length();
			end = line.find(delim, start);

		}
		sentance += line.substr(start, end - start); // also need to add the last word, becuae while loop wont run again and add it
		cout << sentance << endl; // the last complete sentance, becuase while loop condition is broken
		break; // only work on the first line in text file for now. Don't forget to delete!

	}
	myf.close();
	return;
}
