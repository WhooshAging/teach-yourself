/*
 * Cat.h
 *
 *  Created on: Apr 20, 2018
 *      Author: Cherie
 */

#include <iostream>
using namespace std;

#ifndef CAT_H_
#define CAT_H_

class Cat {
private:
	bool happy;
	int lives;
	string name;

public:
	Cat(string, int);
	~Cat();
	void speak();
	void status();
};

#endif /* CAT_H_ */
