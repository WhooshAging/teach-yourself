#include <iostream>

using namespace std;

main() {
  int grade;
  cout << "Please enter a number from 1-100: " << flush;
  cin >> grade;
  if (grade >=80)
    cout << "Clever Boy" << endl;
    // cout << "Works?" << endl;	compound statement no work
  else
    cout << "DUNCE" << endl;
  
  // and another style of loop
  // isnt the above just so much better?
  // the below style is required for compound statements
  
  if (grade == 50) {
    cout << "Middle Ground" << endl;
  } else if (grade == 100) {
    cout << "Amazing" << endl;
  } else {
    cout << "Hmm not 50." << endl;
  }
  
  return 0;
}