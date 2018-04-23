
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	const int N_ELEMENTS = 5;
	string my_array[N_ELEMENTS] = { "Spam", "Eggs", "Spam", "And", "Ham" };

	stringstream ss;
	ss << "Normal for loop:\t\t";
	for (int i=0; i<N_ELEMENTS; i++) {
		ss << my_array[i] + " ";
	}
	cout << ss.str() << endl;

	stringstream ss2;
	ss2 << "For loop incrementing pointer:\t";
	string* p_my_array = my_array;
	for (int i=0; i<N_ELEMENTS; i++, p_my_array++) {
		ss2 << *p_my_array + " ";
	}
	cout << ss2.str() << endl;

	stringstream ss3;
	ss3 << "While loop comparing pointers:\t";
	string* p_start = my_array;
	string* p_end = &(my_array[N_ELEMENTS-1]);
	while (true) {
		ss3 << *p_start + " ";
		if (p_start == p_end) {
			break;
		}
		p_start++;
	}
	cout << ss3.str() << endl;

	stringstream ss4;
	ss4 << "While loop subtract pointers:\t";
	string* p_f = my_array;
	string* off_array = &(my_array[N_ELEMENTS]);
	while (p_f != off_array) {
		ss4 << *p_f + " ";
		p_f++;
	}
	cout << ss4.str() << endl;

	cout << endl;
	cout << "Pointer Arithmetic" << endl;
	string* first = my_array;
	cout << *first << endl;
	cout << "Fourth element: " << *(first+3) << endl;

	cout << "Number of elements by subtracting pointers: " << off_array - first << endl;
	string* p_mid = first + (N_ELEMENTS/2);
	cout << "Middle of array: " << *p_mid << endl;


	return 0;
}

