#include <iostream>
#include <sstream>
using namespace std;

void mutate(char &);
void mutate(string &);

int main() {

	char text[] = "Hello";

	//cout << sizeof(text) << endl;
	//cout << text[1] << endl;

	stringstream ss;
	cout << "Looping over char array" << endl;
	cout << "index\tentry\tint" << endl;
	for (int i=0; i<(int)sizeof(text); i++) {
		ss << i;
		ss << "\t";
		ss << text[i];
		ss << "\t";
		ss << int(text[i]);
		ss << "\n";
	}
	cout << ss.str() << endl;
	cout << "int of last char of string array is a 0. We can use that" << endl;

	cout << "Text array is: " << flush;
	int k = 0;
	while (true) {

		if (text[k] == 0) {
			break;
		}
		cout << text[k] << flush;
		k++;
		}

	cout << endl;
	cout << "We now know how to change the values of an array with array notation" << endl;

	for (int i=0; i<(int)sizeof(text);i++) {
		// be careful with what index to loop over
		// sizeof gives all the elements - 6 including lastt '0' entry
		// we only want to index to 5
		// but we actually only want to index to 4 becuase of the last '0' char
		if (i ==  (int)sizeof(text) - 2 - i  ) {
			break;
		}
		char temp = text[i];
		text[i] = text[(int)sizeof(text) - 2 - i];
		text[(int)sizeof(text) - 2 - i] = temp;
//		cout << i << "\t i \t value: " << text[i] << endl;
//		cout << (int)sizeof(text) - 2 - i  << "\t expr \t value: " << text[(int)sizeof(text) - 2 - i] << endl;

	}
	cout << "Text array is: " << text << endl;
	cout << endl;


	cout << "And now with pointers?" << endl;

	// there is a difference between char text[] = "Hello"
	// and mine[] = { 'a','b','c','\0' } in terms of pointers
	// the first returns all the chars
	// the second returns just the first
	// why?

	// BECAUSE I AM FORGETTING TO DEREFERENCE!
	// cout << *p_start << endl !!

	char* p_start = text;
	char* p_end = text + (int)sizeof(text) - 1; // -1 beause we are accessing memory with cout
	cout << "First: " << *p_start << endl;
	cout << "Last: " << *p_end << endl; // gives the terminator symbol
	cout << "Penultimate: " << *(p_end - 1) << endl; // give the final char
	cout << "Do a loop with pointer." << endl;
	p_end = text + (int)sizeof(text); //re-def to be 1 off end of array, OK as it's a break condition
	while (true) {
		if (p_start == p_end) {
			break;
		}
		cout << *p_start << flush;
		p_start++;
	}
	cout << endl;
	cout << "Reverse again but with pointer." << endl;
	p_start = text;
	char *p_middle = text + (int)(sizeof(text)/2 - 1);
	k = 0;
	while (p_start <= p_middle) {

		*(p_end - 1) = *p_start; // final null char becomes current
		*p_start = *(p_end - k - 2); // current becomes current last char
		*(p_end - k - 2) = *(p_end - 1); // current last char becomes final array entry
		p_start++;
		k++;

	}
	*(p_end - 1) = '\0'; // reset final array entry to null terminator
	cout << text << endl;

	// replace the chars to make a new word
	cout << "Loop and change chars using switch case." << endl;
	for (int i=0; i<(int)sizeof(text)-1;i++) {
		switch(i) {
		case 0:
			text[i] = 'W';
			break;
		case 1:
			text[i] = 'o';
			break;
		case 2:
			text[i] = 'r';
			break;
		case 3:
			text[i] = 'l';
			break;
		case 4:
			text[i] = 'd';
			break;
		default:
			break;

		}
	}
	cout << text << endl;

	// using a reference to a variable to change it

	char text2[] = "Spam";
	cout << endl;
	cout << "New text array: " << text2 << endl;
    mutate(text2[3]);
    cout << "After mutate func has returned text2 is: " << text2 << endl;

    // maybe a bad exampple becuase array[i] is a reference anyway? not sure on that

    string my_string = "Spam";
    cout << endl;
    cout << "Passing a var ref to a func to change it's value: " << my_string << endl;

    mutate(my_string);

    cout << "my_string after mutate has returned: " << my_string << endl;

	return 0;
}

void mutate(char &p_char) {
	cout << "Start of mutate func p_char is: " << p_char << endl;
	p_char = 'b';
	cout << "End of mutate func p_char is: " << p_char << endl;

	return;
}

void mutate(string &my_ref) {
	cout << "Start of mutate func string is: " << my_ref << endl;
	my_ref = "Spam eggs and ham.";
	cout << "End of mutate func string is: " << my_ref << endl;
	return;
}
