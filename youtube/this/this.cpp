/*
 * construct-params.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Cherie
 */

#include <iostream>
#include "Person.h"

using namespace std;

int main() {
	Person p1;
	p1.status();
	cout << "My memory location is: " << &p1 << endl;

	Person p2("Just name.");
	p2.status();
	cout << "My memory location is: " << &p2 << endl;

	Person p3("Name and age.",35);
	p3.status();
	cout << "My memory location is: " << &p3 << endl;


	return 0;
}
