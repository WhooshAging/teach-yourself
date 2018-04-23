
#include <iostream>

using namespace std;

void usePointer( int* p) {
	cout << "2. Value of n at start of func is:\t" << *p << endl;
	*p = 0;
	cout << "3. Value of n at end of func is:\t" << *p << endl;
	return;
}

int main() {
	int n = 10;
	int* p_n = &n;

	cout << "Using memory address directly to change a variabe.\n" << endl;
	cout << "1. Value of n at start of prog is:\t" << n << endl;

	usePointer(p_n);

	cout << "4. Value of n at end of prog is:\t" << n << endl;

	return 0;
}
