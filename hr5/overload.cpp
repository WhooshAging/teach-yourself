// calcualte average of 2 ints or 2 floats with an overloaded func

#include <iostream>

using namespace std;

// prototypes
int average(int, int);
float average(float, float);
long average(long,long);

main() {
  int i1 = 3;
  int i2 = 67;
  float f1 = 12.3;
  float f2 = 18.75;
  long l1 = 500;
  long l2 = 5485;

  cout << "Average of 2 ints " << i1 << " and " << i2 << " : " << average(i1,i2) << endl;
  cout << "Average of 2 floats " << f1 << " and " << f2 << " : " << average(f1,f2) << endl;
  cout << "Average of 2 longs " << l1 << " and " << l2 << " : " << average(l1,l2) << endl;
  
  return 0;
}

// the actual func defs

int average(int a, int b) {
	return (a+b)/2;
}

float average(float a, float b) {
	return (a+b)/2;
}

long average(long a, long b) {
	return (a+b)/2;
}