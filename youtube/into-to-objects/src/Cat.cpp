/*
 * Cat.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: Cherie
 */

#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat() {
	cout << "Cat Created" << endl;
	lives = 9;
	happy = true;
}

Cat::~Cat() {
	cout << "Cat destroyed." << endl;
}


void Cat::speak() {
	cout << "MEOW!" << endl;
}

void Cat::status() {

	cout << endl;
	speak();

	cout << "Happy\t" << happy << endl;
	cout << "Lives\t" << lives << endl;
	cout << endl;
}
