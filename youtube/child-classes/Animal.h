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

private:
	int id;
	string name;
public:
	Animal();
	virtual ~Animal();
	static int count;
	void setName(string);
	string getName() const;
	int getID() const;
};

#endif /* ANIMAL_H_ */
