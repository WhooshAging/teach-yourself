/*
 * Animal.cpp
 *
 *  Created on: Apr 23, 2018
 *      Author: Cherie
 */

#include <iostream>
#include <sstream>
#include "Animal.h"

using namespace std;

Animal::Animal(string a_typein, string namein, string greetingin, int agein) {
	a_type = a_typein;
	name = namein;
	greeting = greetingin;
	age = agein;

}

void Animal::status() const {
	stringstream ss;
	ss << greeting;
	ss << "! My name is ";
	ss << name;
	ss << " and I am a ";
	ss << a_type;
	ss << ". I am ";
	ss << age;
	ss << " years old.";
	cout << ss.str() << endl;
	return;
}

Animal::~Animal() {
	// TODO Auto-generated destructor stub
}

