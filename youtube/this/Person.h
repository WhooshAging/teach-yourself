/*
 * Person.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Cherie
 */

#include <iostream>

using namespace std;

#ifndef PERSON_H_
#define PERSON_H_

class Person {
private:
	int age;
	string name;
public:
	Person() { name = "blank"; age = 0; };
    Person(string namein) { name = namein; age = 0; };
	Person(string, int);
	virtual ~Person();
	void status();
};

#endif /* PERSON_H_ */
