// A program to find all multiples of a given integer up to a given target n

#include <iostream>

using namespace std;

int main() {
  cout << "\nFind multiples of: " << flush;
  int m;
  cin >> m;
  cout << "Up to: " << flush;
  int n;
  cin >> n;
  cout << endl;
  
  int counter = 1; // start from one becuase 0 % m = 0 always, but 0 is not a multiple of m!
  while (counter <= n) {
  	if (counter % m == 0) {
  	  // it's a multiple, print it
  	  cout << counter << " ";
  	}
  	counter++;
  }
  cout << endl;
  return 0;
}
