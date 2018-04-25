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
// lookup how to restart a map iterator!
// re-write everyting as funcs
// then ultimately as a class
// more?


#include <iostream>
#include <unordered_map> // to make a Python dict-like thing
#include <vector>

using namespace std;

int main() {

	unordered_map<string, unordered_map<string, int> > hash_tbl;

	// set some examples
	hash_tbl["I"]["am"] = 1;
	hash_tbl["a"]["car"] = 2;
	hash_tbl["he"]["is"] = 4;

	//cout << hash_tbl.size() << endl;

	// Loop through first u_map

	string keys[hash_tbl.size()];

	// https://stackoverflow.com/questions/26281979/c-loop-through-map

	/* ~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+ START Working code examples

	 unordered_map<string, unordered_map<string, int> >::iterator it;
	 for (it = hash_tbl.begin(); it != hash_tbl.end(); it++, i++) {
	 cout << "Key read from map: " << it->first << endl; // prints keys
	 keys[i] = it->first; // saves them in our string array
	 }

	 // We now have normal array we can loop over

	 for (unsigned int i = 0; i < sizeof(keys) / sizeof(string); i++) {
	 cout << "Key read from array: " << flush;
	 cout << keys[i] << endl;
	 }

	 // Keys for first map return u_map<str,int>
	 // Same technique to get those keys

	 unordered_map<string, int>::iterator it2;
	 for (unsigned int i = 0; i < sizeof(keys) / sizeof(string); i++) {
	 // hash_tbl[key] gives another map<str,int>
	 // how to deal with this?

	 for (it2 = hash_tbl[keys[i]].begin(); it2 != hash_tbl[keys[i]].end();
	 it2++) {
	 cout << "Key read from 2nd map: " << it2->first << endl; // prints keys
	 cout << "Value read from 2nd map: " << it2->second << endl; // prints values
	 }
	 }

	 ~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+ END Working code examples
	 */


	// EXAMPLE CODE FOLLOWS - READY TO BE MADE TO FUNCS
	// SEE COMMENTS

	// show keys before we make a change
	// should look like
	// hash_tbl["I"]["am"] = 1;
	// hash_tbl["a"]["car"] = 2;
	// hash_tbl["he"]["is"] = 4;

	cout << "Programe Start" << endl;

	// ITERATE OUTER KEYS
	//
	// Iterate through our outer keys k { k : ... }
	// And print them
	cout << "Iterate Outer Keys: " << flush;

	unordered_map<string, unordered_map<string, int> >::iterator it1_z;
	for (it1_z = hash_tbl.begin(); it1_z != hash_tbl.end(); it1_z++) {
		cout << it1_z->first << flush; // first gives key, string here, second gives value, another umap here.
		cout << " " << flush;
	}
	cout << endl;

	// ITERATE INNER KEYS
	//
	// Iterate inner keys k and innner values v { ... : {k:v} }
	//
	cout << "Iterate inner and outer keys: " << endl;

	unordered_map<string, unordered_map<string, int> >::iterator it1_j;
	unordered_map<string, int>::iterator it2_j;

	for (it1_j = hash_tbl.begin(); it1_j != hash_tbl.end(); it1_j++) {

		for (it2_j = hash_tbl[it1_j->first].begin();
				it2_j != hash_tbl[it1_j->first].end(); it2_j++) {

			//cout << "Key|value read from 2nd map: " << flush;
			//cout << it2_b->first << " | " << flush; // prints keys
			//cout << it2_b->second << endl; // prints values

			cout << "{ " << it1_j->first << " : { " << it2_j->first << " : "
					<< it2_j->second << " } }" << endl;
		}
	}
	cout << endl;


	// ADDING ENTRIES
	//
	// Example of adding things
	// First example adds a new outer key
	// NEED TO SET BELOW TO RUN THAT EXAMPLE it1_b->first == to_add
	// Second example adds a new inner key
	// it1_b->first == to_add2 for the second example
	//
	cout << "Adding Entries" << endl;

	string to_add = "she";
	string word2 = "likes";
	int nword2 = 7;

	string to_add2 = "he";
	string word2_2 = "was";
	int nword2_2 = 3;

	// ~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~+~ TODO
	//
	// Another iterator? Should learn how to reset
	// Should just declare two iterators at the start
	// Then use throughout
	//

	unordered_map<string, unordered_map<string, int> >::iterator it1_b;
	for (it1_b = hash_tbl.begin(); it1_b != hash_tbl.end(); it1_b++) {
		// cout << "Key read from map: " << it->first << endl;
		if (it1_b->first == to_add2) {


			// DUPLICATE OUTER KEY



			cout << "... Outer Keys match" << endl;
			// need to get the nested map
			// check if the word already exists
			// if not add it
			// if it does update the map

			unordered_map<string, int>::iterator it2_x;

			// search the through neseted maps
			for (it2_x = hash_tbl[it1_b->first].begin(); // it1_b->first is the outer key string, hash_tbl[it1_b->first] is the inner umap
					it2_x != hash_tbl[it1_b->first].end(); it2_x++) {
				//cout << "{ " << it1_d->first << " : { " << it2_b->first << " : " << it2_b->second << " } }" << endl;


				// INNER KEY MATCHES - UPDATE THE MAP


				if (it2_x->first == to_add2) {
					// inner keys match
					// need to update the held map
					cout << "... ... Inner keys match" << endl;







				} else {

					// NEW INNER KEY - Insert a new pair(s,i) into umap of outer key {k : {s:i} }
					//


					cout << "... ... New Inner Key" << endl;
					// need to insert into the map
					//unordered_map<string, int> data_to_add = { { word2, nword2 } };
					//hash_tbl[to_add] = data_to_add;

					hash_tbl[it1_b->first].insert( pair<string,int>(word2_2, nword2_2) );

					break;
				}
			}
			break;
		} else {


			// NEW OUTER KEY - Create a new umap<s,i> and add k : {s,i} to our outer umap


			cout << "... New key : " << to_add << endl;
			unordered_map<string, int> data_to_add = { { word2, nword2 } };
			hash_tbl[to_add] = data_to_add;
			break;
		}
	}

	// CHECK OUTER KEY WAS ADDED

	unordered_map<string, unordered_map<string, int> >::iterator it1_c;
	cout << "Outer keys read from map: " << flush;
	for (it1_c = hash_tbl.begin(); it1_c != hash_tbl.end(); it1_c++) {
		cout << it1_c->first << flush;
		cout << " " << flush;
	}
	cout << endl;

	// CHECK INNER KEY ADDED PROPERLY


	unordered_map<string, unordered_map<string, int> >::iterator it1_d;
	unordered_map<string, int>::iterator it2_b;

	for (it1_d = hash_tbl.begin(); it1_d != hash_tbl.end(); it1_d++) {

		for (it2_b = hash_tbl[it1_d->first].begin();
				it2_b != hash_tbl[it1_d->first].end(); it2_b++) {

			//cout << "Key|value read from 2nd map: " << flush;
			//cout << it2_b->first << " | " << flush; // prints keys
			//cout << it2_b->second << endl; // prints values

			cout << "{ " << it1_d->first << " : { " << it2_b->first << " : "
					<< it2_b->second << " } }" << endl;
		}
	}

	// DEMONSTRATE WORKING AS EXPECTED

	cout << endl;
	cout << "Output of hash_tbl[\"he\"][\"was\"] : " << hash_tbl["he"]["was"] << endl; // should be 3
	cout << "Output of hash_tbl[\"he\"][\"is\"] : " << hash_tbl["he"]["is"] << endl; // should be 4


	return 0;
}
