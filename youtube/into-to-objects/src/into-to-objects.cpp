//============================================================================
// Name        : into-to-objects.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cat.h"

using namespace std;

int main() {
	cout << "Starting Programme ..." << endl;

	{
	Cat cat("Bob",9);
	cat.status();
	}
	Cat cat("wew",2);
	cat.status();


	cout << "Ending Programme ..." << endl;
	return 0;
}
