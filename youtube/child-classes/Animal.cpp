/*
 * Animal.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Cherie
 */

#include <iostream>
#include "Animal.h"
using namespace std;


// init class count var

int Animal::count = 0;

Animal::Animal() {
	cout << "Default construtor called." << endl;
	id = ++count;

}

Animal::~Animal() {
	cout << "Default destructor called." << endl;
}

void Animal::setName(string name) {
	this->name = name;
	return;
}

string Animal::getName() const {
	return name;
}
int Animal::getID() const {
	return id;
}
