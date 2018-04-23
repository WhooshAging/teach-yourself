/*
 * Animal.h
 *
 *  Created on: Apr 23, 2018
 *      Author: Cherie
 */

#include <iostream>

using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
private:
	string a_type;
	string name;
	string greeting;
	int age;

public:
	Animal();
	Animal(string, string, string, int);
	virtual ~Animal();
	void status() const;
};

#endif /* ANIMAL_H_ */
