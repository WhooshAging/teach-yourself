/*
 * Cat.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: Cherie
 */

#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat(string namein, int livesin) {
	cout << "Cat Created" << endl;
	lives = livesin;
	happy = true;
	name = namein;
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
	cout << "Name\t" << name << endl;
	if (happy) {
    	cout << "Happy\t" << "True" << endl;
	} else if (!happy) {
		cout << "Happy\t" << "False" << endl;
	}
	cout << "Lives\t" << lives << endl;
	cout << endl;
}
