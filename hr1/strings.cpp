

#include <iostream>

using namespace std;

main() {

  string hello = "Hello";
  
  cout << hello << endl;
  
  for (int i = 0; i < hello.length(); i++) {
    cout << hello[i] << endl;
  }
  
  string your_name;
  
  cout << "Enter your name: " << flush;
  cin >> your_name;
  
  hello+=" " + your_name;
  
  cout << hello << endl;
  
  
  return 0;
}