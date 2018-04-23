// const is important in many ways, apparently
// vital tool to preent bugs

#include <iostream>
#include <sstream>

#include "Animal.h"

using namespace std;

int main() {

	cout << "Declaring const methods." << endl;

	Animal man("Human", "Dan", "Hi", 34);
	Animal cow("Cow", "Bob", "Moo", 7);
	Animal cat("Cat", "Alice", "Meaow", 2);
	man.status();
	cow.status();
	cat.status();

	cout << endl;

	cout << "Const vars and pointers." << endl;
	cout << endl;
	const int VALUE = 10;
	cout << "Declare const int VALUE = 10;" << endl;
	cout << "value += 1 fails!" << endl;
	cout << "Setting a point to an already const fails if like this: int *p_value = &value;" << endl;
	cout << "But it works like this: int const *p_value = &value;" << endl;
	int const *p_value = &VALUE;
	cout << "pointer to value: " << p_value << " is " << *p_value << endl;
	cout << endl;

	int N = 100;
	cout << "Decalre int N = 100;" << endl;
	int *p_n = &N;
	cout <<"Get pointer as expected with int *p_n = &N; " << p_n << " " << *p_n << endl;
	const int *p_n2 = &N;
	cout <<"Get a pointer to an int, which is const as far as the pointer is concerned "
			"const int *p_n = &N; " << p_n2 << " " << *p_n2 << endl;
	cout << "So this will fail (changing value pointer points to *p_n2 = 0;" << endl;
	N = 0;
	cout << "But this works N = 0; " << *p_n2 << endl;
	cout << endl;

	N = 100;
	int * const p_n3 = &N;
	cout << "Set a constant pointer to an int with int * const p_n3 = &N;" << endl;
	cout << "p_n3 points to " << *p_n3 << endl;
	cout << "So this will fail: p_n3++;" << endl;
	*p_n3 = 0;
	cout << "But *p_n3 = 0; works : " << p_n3 << " " << *p_n3 << endl;
	cout << endl;


	N = 100;
	cout << "Let's set a const pointer to a const int, so neither can be changed." << endl;
	cout << "N set back to " << N << endl;
	const int * const p_n4 = &N;
	cout << "Our pointer: " << p_n4 << " " << *p_n4 << endl;
	cout << "*p_n4 = 0; fails." << endl;
	cout << "So does *p_n4--; " << endl;
	N = 0;
	cout << "But of course N = 0; will work as expected. " << N << endl;

	return 0;
}
