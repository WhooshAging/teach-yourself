// Demonstrates break
// Displays first 10 multiples (in a shit way tbh)

#include <iostream>
using namespace std;

main() {
  cout << endl;
  cout << "Find multiples of: " << flush;
  int n;
  cin >> n;
  cout <<"How many multiples would you like? " << flush;
  int how_many;
  cin >> how_many;
  cout << endl;

  int counter = 1;
  int multiples = 0;
  while (true) {
    if (counter % n == 0) {
      cout << counter << endl;
      multiples++;
    }
    counter++;
    if (multiples == how_many){
      break;
    }
  }

  cout << endl;
  return 0;
}