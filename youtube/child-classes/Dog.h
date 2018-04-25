/*
 * Dog.h
 *
 *  Created on: Apr 24, 2018
 *      Author: Cherie
 */
#include "Animal.h"

#ifndef DOG_H_
#define DOG_H_

class Dog : public Animal {
private:
	const int n_legs = 4;

public:
	Dog();
	virtual ~Dog();
	void chaseTail() const;
	void fetch() const;
	int getLegs() const;
};



//in-place sub-classing
// makes sense for puppy to be in the Dog file right?

class Puppy : public Dog {
public:
	void lookCute() const;

};

#endif /* DOG_H_ */
