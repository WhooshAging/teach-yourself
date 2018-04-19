// Programme to determine if a given input year is a leap year

/* 

Leap years follow some rules:

366 days instead of 365
If year is divisible by 4 it is a leap year
Unless also divisible by 100, then it isn't
Unless also divisble by 400, then it is a leap year after all.

*/


#include <iostream>

using namespace std;

bool isLeapYear(int); // prototype a function, so we can call it before we define it

main() {
  
  cout << "Please enter a year to check: " << flush;
  int year;
  cin >> year;
  
  bool res = isLeapYear(year);

  if (res) { // resolves to true if res is true and false otherwise
  	cout << year << " is a leap year." << endl;
  } else {
    cout << year << " is not a leap year." << endl;
  }

  return 0;
}

bool isLeapYear(int year) {
	// implement the above rules of what a leap year is
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				// all three are true so it is a leap year
				return true;
			} else {
				return false; // divis by 4 and 100 but not 400 --> not leap year
			}
		} else {
			return true; // divis by 4 but not 100 --> leap year
		}
	} else {
		return false; // not divis by 4 --> not leap
	}
}

