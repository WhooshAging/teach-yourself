/*
 * Person.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Cherie
 */

#include <iostream>
#include <sstream>
#include "Person.h"

using namespace std;

Person::Person(string name, int age) {
	this-> name = name;
	this-> age = age;

}

Person::~Person() {
	// TODO Auto-generated destructor stub
}


void Person::status() {
	stringstream ss;
	ss << "My name is ";
	ss << name;
	ss << " and I am ";
	ss << age;
	ss << " years old.";
	cout << endl;
	cout << ss.str() << endl;

	return;
}
