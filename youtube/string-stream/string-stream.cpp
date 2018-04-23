#include <iostream>
#include <sstream>

using namespace std;


int main() {
	cout << endl;
	cout << "Enter your name: " << flush;
	string u_name;
	cin >> u_name;
	cout << "Enter your age: " << flush;
	int age;
	cin >> age;

	cout << "Wouldn't it be nice to print your name (string) with your age(int) as a single string ala Python?" << endl;
	cout << "This is achieved by an #include <sstream>. And use of a stringstream object, which we put << things to." << endl;

	stringstream ss;
	ss << "Your name is: ";
	ss << u_name;
	ss << " | Your age is: ";
	ss << age;

	cout << ss.str() << endl;

	return 0;
}
