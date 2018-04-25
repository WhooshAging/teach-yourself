/*
 * Animal.h
 *
 *  Created on: Apr 24, 2018
 *      Author: Cherie
 */

#include <iostream>

using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
public:
	Animal() {name = "None", id=++count, cout << "Default constructor called. My name is " << name << endl;};
	Animal(string namein);
	virtual ~Animal();

	static int count;
	void speak();
	void setName(string);
private:
	int id;
	string name;
};

#endif /* ANIMAL_H_ */
