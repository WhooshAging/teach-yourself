

#include <iostream>

using namespace std;

main() {

  int n_cats = 5;
  int n_dogs = 0;
  
  cout << "I own " << n_cats  << " cats." << endl;
  cout << "I own " << n_dogs << " dogs.\n" << endl;
  cout << "So I have " << n_dogs + n_cats << " total pets." << endl;
  
  cout << "I just bought 10 cats and 5 dogs!" << endl;
  
  n_cats+=10;
  n_dogs+=5;
  
  cout << "I now have " << n_dogs + n_cats << " total pets." << endl;



  return 0;
}