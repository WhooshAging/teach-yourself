// convert from celcius to fahrenheit
// f = (9c/5) + 32

#include <iostream>

using namespace std;

float cToF(float); // prototype

main() {
  
  cout << "Enter temperature in Celcius: " << flush;
  float c;
  cin >> c;
  cout << c << " Celcius is " << cToF(c) << " Fahrenheit." << endl;
  
  return 0;
}

float cToF(float c) {
	return (9 * c / 5.0) + 32;
}