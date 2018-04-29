/*
 * hash-tb.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Dan
 *
 * Nested Dict
 * { string : { string : int } }
 * Uses Unordered Maps
 * Used to store text connections
 * { word : { word that follows : count } }
 * { word + next : { word that follows : count } }
 * { word + next + next : { word that follows : count } }
 *
 */
#include "Dict.h"

int main() {
	cout << "Programe Start" << endl;



	Dict *words = new Dict();

	words->addFile("textin");

	delete words;
	words = NULL;



















/*
 *
 * TESTING
  	Dict *words = new Dict();
	cout << "Adding entries: " << flush;
	dict->add("she", "likes", 7);
	dict->add("she", "eats", 2);
	dict->add("she", "eats", 5);
	dict->add("she", "loves", 1);
	cout << endl;
	dict->print();
	dict->save();
	delete dict;

	Dict *dict2 = new Dict();
	dict2->print();
	dict2->load();
	dict2->print();
	delete dict2;
 *
 *
*/
	return 0;
}
