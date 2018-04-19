#include <iostream>

using namespace std;

int main() {
  
  cout << "The size of an integer:\t\t";
  cout << sizeof(int) << " bytes\n";
  cout << "The size of a short integer:\t";
  cout << sizeof(short) << " bytes\n";
  cout << "The size of a long integer:\t";
  cout << sizeof(long) << " bytes\n";
  cout << "The size of a character:\t";
  cout << sizeof(char) << " bytes\n";
  cout << "The size of a boolean:\t\t";
  cout << sizeof(bool) << " bytes\n";
  cout << "The size of a float:\t\t";
  cout << sizeof(float) << " bytes\n";
  cout << "The size of a double float:\t";
  cout << sizeof(double) << " bytes\n";
  cout << "The size of a long long int:\t";
  cout << sizeof(long long int) << " bytes\n";
  
  cout << "The size of an unsigned short:\t";
  cout << sizeof(unsigned short) << " bytes" << endl;
  
  cout << "The size of an unsigned long:\t";
  cout << sizeof(unsigned long) << " bytes" << endl;
  
  return 0;
}