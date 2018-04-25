/*
 * Dog.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Cherie
 */

#include "Dog.h"

Dog::Dog() {
	// TODO Auto-generated constructor stub

}

Dog::~Dog() {
	// TODO Auto-generated destructor stub
}

void Dog::chaseTail() const {
	cout << "Woof! Such fun!" << endl;
	return;
}

void Dog::fetch() const {
	cout << "You need to throw something before I can fetch it." << endl;
	return;
}


//in-place sub-classing
// makes sense for puppy to be in the Dog file right?

void Puppy::lookCute() const {
	cout << "I'm looking cute for treats, human." << endl;
	return;
}
int Dog::getLegs() const {return n_legs;}
