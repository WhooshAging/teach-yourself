/*
 * hash-tb.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Cherie
 */

// read a load of text
// split by words
// build a hash table of a sliding window
// what a python dict-like thing. using python notation we want:
// so { 1 word : { word the follows : count } }
// { 1 word + next : { word that follows : count } }
// { 1 word + next + next : { word that follows : count } }
// etc
// { string : {string : int} }
//
//
//
//
//
// TO DO
// re-write everyting as funcs
// then ultimately as a class
// more?

#include <iostream>
#include <unordered_map> // to make a Python dict-like thing

using namespace std;

class Dict {
private:
	unordered_map<string, unordered_map<string, int> > hash_tbl;
	// set our iterators, one for each umap we have
	unordered_map<string, unordered_map<string, int> >::iterator it1;
	unordered_map<string, int>::iterator it2;


public:
	Dict() {
		cout << "Default Constructor." << endl;
		hash_tbl[""][""] = 0;

	}
	~Dict() {
		cout << "Default Destructor." << endl;

	}

	void printDict() {
		/*	HOW TO ITTERATE OVER OUTER KEYS

		 //
		 // ITERATE OUTER KEYS
		 //
		 // Iterate through our outer keys k { k : ... }
		 //
		 cout << "Iterate Outer Keys: " << flush;

		 for (it1 = hash_tbl.begin(); it1 != hash_tbl.end(); it1++) {
		 cout << it1->first << flush; // first gives key(string), second gives value (umap)
		 cout << " " << flush;
		 }
		 cout << endl;

		 */

		//
		// ITERATE INNER AND OUTER KEYS
		//
		// Iterate inner keys k and innner values v { ... : {k:v} }
		//
		cout << "Iterate inner and outer keys: " << endl;

		for (it1 = hash_tbl.begin(); it1 != hash_tbl.end(); it1++) {

			for (it2 = hash_tbl[it1->first].begin();
					it2 != hash_tbl[it1->first].end(); it2++) {

				//cout << "Key|value read from 2nd map: " << flush;
				//cout << it2->first << " | " << flush; // prints keys
				//cout << it2->second << endl; // prints values

				cout << "{ " << it1->first << " : { " << it2->first << " : "
						<< it2->second << " } }" << endl;
			}
		}
		cout << endl;
		return;
	}

	void addEntry() {
		//
		// ADDING ENTRIES
		//
		// 3 Cases: new outer key
		//			existing outer, new inner
		//			existing outer, existing inner
		//
		cout << "Adding Entries" << endl;
		//
	//	/*
		// Example 1: New Outer Key
		string word1 = "she";
		string word2 = "likes";
		int nseen = 7;
	//	*/

		/*
		 // Example 2: Existing Outer Key, New Inner Key
		 string word1 = "he";
		 string word2 = "was";
		 int nseen = 3;
		 */

		/*
		 // Example 3: Existing Outer and Inner Keys
		 string word1 = "a";
		 string word2 = "car";
		 int nseen = 3;
		 */

		//unordered_map<string, unordered_map<string, int> >::iterator it1;
		//unordered_map<string, int>::iterator it2;

		// if we don't have a dict yet, it must be the first entry
		// so add it

		cout << "hash_tbl.size() = " << hash_tbl.size() << endl;

		// hash_tbl.size() is currently one becuase we had to init with a dummary entry " " " " 0
		// we should change this behaviour

		// Going to just check if it exists and delete it ...

		if (hash_tbl.size() == 1) {
			cout << "New key : First Entry: " << word1 << endl;

			unordered_map<string, int> data_to_add = { { word2, nseen } };
			hash_tbl[word1] = data_to_add;

		} else {

			// check if word1 in outer keys
			int outer_counter = 0;
			for (it1 = hash_tbl.begin(); it1 != hash_tbl.end(); it1++) {
				//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl.size(): " << hash_tbl.size() << endl;
				//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE outer_counter: " << outer_counter << endl;
				//cout << "Checking Outer Key: " << it1->first << endl;
				if (it1->first == word1) {
					// DUPLICATE OUTER KEY
					cout << "... Outer Keys match" << endl;

					// Check if word2 in inner keys
					int inner_counter = 0;
					for (it2 = hash_tbl[it1->first].begin(); // it1->first is key string, hash_tbl[it1->first] is the inner umap
							it2 != hash_tbl[it1->first].end(); it2++) {

						//cout << "{ " << it1->first << " : { " << it2->first << " : " << it2->second << " } }" << endl;
						//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl[it1->first].size(): " << hash_tbl[it1->first].size() << endl;
						//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE inner_counter: " << inner_counter << endl;
						//cout << "Checking Inner Key: " << it2->first << endl;

						// INNER KEY MATCHES - UPDATE THE MAP

						if (it2->first == word2) {
							cout << "... ... Inner keys match" << endl;
							// update the count we hold by count we provided
							it2->second += nseen;

						} else if (inner_counter
								== (int) hash_tbl[it1->first].size() - 1) { // Checked all, sure new inner key

								// NEW INNER KEY - Insert a new pair(s,i) into umap of outer key {k : {s:i} }
							cout << "... ... New Inner Key" << endl;

							// insert word2:nseen into dict[outer_key] = {}

							hash_tbl[it1->first].insert(
									pair<string, int>(word2, nseen));

							break;
						}
						inner_counter++;
					}
					break;
				} else if (outer_counter == (int) hash_tbl.size() - 1) { // Checked, sure new outer key

				// NEW OUTER KEY - Create a new umap<s,i> and add k : {s,i} to our outer umap
					cout << "New key : " << word1 << endl;

					unordered_map<string, int> data_to_add = { { word2, nseen } };
					hash_tbl[word1] = data_to_add;
					break;
				}
				outer_counter++;
			}
		}
		cout << endl;
		return;

	}

};

int main() {
	// https://stackoverflow.com/questions/26281979/c-loop-through-map

	unordered_map<string, unordered_map<string, int> > hash_tbl;

	// set some examples
	//hash_tbl["I"]["am"] = 1;
	//hash_tbl["a"]["car"] = 2;
	//hash_tbl["he"]["is"] = 4;

	// set our iterators, one for each umap we have
	unordered_map<string, unordered_map<string, int> >::iterator it1;
	unordered_map<string, int>::iterator it2;

	// EXAMPLE CODE FOLLOWS - READY TO BE MADE TO FUNCS
	// SEE COMMENTS
	cout << "Programe Start" << endl;

	Dict *dict = new Dict();
	dict->printDict();
	dict->addEntry();
	dict->printDict();
	delete dict;




	/* *******************************************************************************************************************





	//
	// ADDING ENTRIES
	//
	// 3 Cases: new outer key
	//			existing outer, new inner
	//			existing outer, existing inner
	//
	cout << "Adding Entries" << endl;
	//
//
	// Example 1: New Outer Key
	string word1 = "she";
	string word2 = "likes";
	int nseen = 7;
//

//
	 // Example 2: Existing Outer Key, New Inner Key
	 string word1 = "he";
	 string word2 = "was";
	 int nseen = 3;
//

//
	 // Example 3: Existing Outer and Inner Keys
	 string word1 = "a";
	 string word2 = "car";
	 int nseen = 3;
//

	//unordered_map<string, unordered_map<string, int> >::iterator it1;
	//unordered_map<string, int>::iterator it2;

	// if we don't have a dict yet, it must be the first entry
	// so add it
	if (hash_tbl.size() == 0) {
		cout << "New key : First Entry: " << word1 << endl;

		unordered_map<string, int> data_to_add = { { word2, nseen } };
		hash_tbl[word1] = data_to_add;

	} else {

		// check if word1 in outer keys
		int outer_counter = 0;
		for (it1 = hash_tbl.begin(); it1 != hash_tbl.end(); it1++) {
			//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl.size(): " << hash_tbl.size() << endl;
			//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE outer_counter: " << outer_counter << endl;
			//cout << "Checking Outer Key: " << it1->first << endl;
			if (it1->first == word1) {
				// DUPLICATE OUTER KEY
				cout << "... Outer Keys match" << endl;

				// Check if word2 in inner keys
				int inner_counter = 0;
				for (it2 = hash_tbl[it1->first].begin(); // it1->first is key string, hash_tbl[it1->first] is the inner umap
						it2 != hash_tbl[it1->first].end(); it2++) {

					//cout << "{ " << it1->first << " : { " << it2->first << " : " << it2->second << " } }" << endl;
					//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE hash_tbl[it1->first].size(): " << hash_tbl[it1->first].size() << endl;
					//cout << "~~~~~~~~~~~~~~~~~~~~~~~ TRACE inner_counter: " << inner_counter << endl;
					//cout << "Checking Inner Key: " << it2->first << endl;

					// INNER KEY MATCHES - UPDATE THE MAP

					if (it2->first == word2) {
						cout << "... ... Inner keys match" << endl;
						// update the count we hold by count we provided
						it2->second += nseen;

					} else if (inner_counter
							== (int) hash_tbl[it1->first].size() - 1) { // Checked all, sure new inner key

							// NEW INNER KEY - Insert a new pair(s,i) into umap of outer key {k : {s:i} }
						cout << "... ... New Inner Key" << endl;

						// insert word2:nseen into dict[outer_key] = {}

						hash_tbl[it1->first].insert(
								pair<string, int>(word2, nseen));

						break;
					}
					inner_counter++;
				}
				break;
			} else if (outer_counter == (int) hash_tbl.size() - 1) { // Checked, sure new outer key

			// NEW OUTER KEY - Create a new umap<s,i> and add k : {s,i} to our outer umap
				cout << "New key : " << word1 << endl;

				unordered_map<string, int> data_to_add = { { word2, nseen } };
				hash_tbl[word1] = data_to_add;
				break;
			}
			outer_counter++;
		}
	}
	cout << endl;




	*********************************************************************************************************** */



	/* ***********************************************************************************************

	// CHECK OUTER KEY WAS ADDED

	// CHECK INNER AND OUTER KEYs ADDED PROPERLY

	for (it1 = hash_tbl.begin(); it1 != hash_tbl.end(); it1++) {
		for (it2 = hash_tbl[it1->first].begin();
				it2 != hash_tbl[it1->first].end(); it2++) {
			cout << "{ " << it1->first << " : { " << it2->first << " : "
					<< it2->second << " } }" << endl;
		}
	}

	// DEMONSTRATE WORKING AS EXPECTED

	cout << endl;
	cout << "Output of hash_tbl[\"he\"][\"was\"] : " << hash_tbl["he"]["was"]
			<< endl; // should be 3
	cout << "Output of hash_tbl[\"he\"][\"is\"] : " << hash_tbl["he"]["is"]
			<< endl; // should be 4





 *************************************************************************************************************** */


	return 0;
}
