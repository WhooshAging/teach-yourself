/*
 * Animal.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Cherie
 */

#include <iostream>
#include "Animal.h"

using namespace std;

int Animal::count = 0;

Animal::Animal(string namein) {
	cout << "Name provided constructor called." << endl;
	name = namein;
	id = ++count;

}



Animal::~Animal() {
	cout << "Destructor called. " << name << " has been killed." << endl;
}

void Animal::speak() {
	cout << "My name is " << name << "." << endl;
	cout << "My ID is: " << id << endl;

	return;
}

void Animal::setName(string namein) {
	name = namein;
	return;
}
