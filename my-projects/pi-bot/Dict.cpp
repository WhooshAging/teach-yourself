/*
 * Dict.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: Dan
 */
#include <iomanip> // setw - fix width for cout
#include "Dict.h"

Dict::Dict() {
	cout << "Creating Dict." << endl;
	//hash_tbl[""][""] = 0;
	hash_tbl = new unordered_map<string, unordered_map<string, int> >;
	delim_outer = "~";
	delim_inner = "|";
}

Dict::~Dict() {
	cout << "Destroying Dict" << endl;
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
	//cout << " ... " << endl;
	//word1 = toLower(word1);
	//word2 = toLower(word2);

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
	//cout << "Loading Data." << endl;



	string x;
	string outer_key = "";
	string inner_key = "";
	string previous_line = "";
	int value = 0;

	ifstream myf;
	myf.open("data/data.dict");

	int counter = 0;
	cout << "Building Dictionary ." << flush;
	for (string line; getline(myf, line);) {


		if (counter % 10000 == 0) {
			cout << "." << flush;
		}
/*
		if (counter % 9000 == 0) {
			cout << setw(11) << "\\\\" << flush;
		}
		if (counter % 9000 == 1000) {
			cout << setw(11) << "||" << flush;
		}
		if (counter % 9000 == 2000) {
			cout << setw(11) << "//" << flush;
		}
		if (counter % 9000 == 3000) {
			cout << setw(11) << "==" << flush;
		}
		if (counter % 9000 == 5000) {
			cout << setw(11) << "\\\\" << flush;
		}
		if (counter % 9000 == 6000) {
			cout << setw(11) << "||" << flush;
		}
		if (counter % 9000 == 7000) {
			cout << setw(11) << "//" << flush;
		}
		if (counter % 9000 == 8000) {
			cout << setw(11) << "==" << flush;
		}
*/
		if (previous_line != "") {
			// if it is, we're at the first line of file
			if (previous_line == "~") {
				// new outer key
				// so new chunk of inner keys comming
				// therefore reset all
				outer_key = line;
				inner_key = "";
				value = 0;
			} else if (previous_line == "|") {
				// new inner key
				inner_key = line;
			} else {
				// prev line is not a special char
				// if we are now looking at an int, then go ahead and add
				// otherwise we must be looking at an inner key
				// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

				stringstream check;
				check << line;
				check >> value;
				if (check.good()) {
					// not an int, a string ==> inner key
					inner_key = line;
				} else if (value == 0 && line[0] != 0) {
					// not an int, a string ==> inner key
					inner_key = line;
				} else {
					// we are looking at an int
					// ==> safe to add entry
					add(outer_key, inner_key, value);
					value = 0;
				}
			}
		}
		previous_line = line;
		counter++;
	}
	cout << endl;
}

string Dict::nextWord(string wordin) {
	// Given an input string, return the next word based on frequency
	// Loop through the nested array, check all values, return key of highest value
	int best = 0;
	string output;

	for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
		if (it1->first == wordin) {
			for (it2 = (*hash_tbl)[it1->first].begin();
					it2 != (*hash_tbl)[it1->first].end(); it2++) {
				if (it2->second > best) {
					output = it2->first;
					best = it2->second;
				}
			}
		}
	}

	return output;

}

void Dict::lookupOuter(string key, vector<string> *inner_keys) {
//	cout << "Start of Dict lookupOuter. Outer key searching for is: " << key << endl;
	for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
		//cout << "it1->first" << it1->first << endl;
		if (it1->first == key) {
//			cout << "Dict lookupOuter - provided key matches a key in our dict" << endl;
			for (it2 = (*hash_tbl)[it1->first].begin();
					it2 != (*hash_tbl)[it1->first].end(); it2++) {
//				cout << "Dict lookup outer. Pushing: " << it2->first << " to vector by pointer." << endl;
				inner_keys->push_back(it2->first);
			}
		}
	}

	return;
}

int Dict::lookupInner(string outer, string inner) {
//	cout << "Start of Dict lookupInner" << endl;
//	cout << "Lookin for outer key: " << outer + "]" << endl;
//	cout << "Looking for inner key: " << inner + "]" << endl;
	for (it1 = hash_tbl->begin(); it1 != hash_tbl->end(); it1++) {
//		cout << "Checking against key in db: " << it1->first << endl;
		if (it1->first == outer) {
//			cout << "Outer keys match: " << outer << " | " << it1->first << endl;
			for (it2 = (*hash_tbl)[it1->first].begin();
					it2 != (*hash_tbl)[it1->first].end(); it2++) {
				if (it2->first == inner) {
//					cout << "Inner keys match. " << inner << " | " << it2->first << endl;
//					cout << "Value to return is: " << it2->second << endl;
					return it2->second;
				}
			}
		}
	}
	return 0; // what if we don't find an inner key? return 0 makes sense? 0 won't ever be in our data.
}
