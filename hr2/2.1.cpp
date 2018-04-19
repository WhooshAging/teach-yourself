
#include <iostream>

using namespace std;

int add(int x, int y) {
  // takes in two ints and returns their sum
  cout << "Preparing fingers and toes ..." << endl;
  return (x+y);

}

main() {
  // Always called in C++. Here we will call our add func.
  cout << "What is 10 + 2387?" << endl;
  int res = add(10,2387);
  cout << "The answer is: " << flush;
  cout << res << endl;
  int first;
  int second;
  cout << "Enter an integer: " << flush;
  cin >> first;
  cout << "And another: " << flush;
  cin >> second;
  res = add(first,second);
  cout << "Their sum is: " << res << endl;
  return 0;
  
}