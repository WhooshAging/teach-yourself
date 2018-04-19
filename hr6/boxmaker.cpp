// Programme to print to screen a rectangle using a user inputted char
#include <iostream>
using namespace std;

main() {
  cout << "\nWelcome to BoxDraw-er(TM)(R).\n" << endl;
  cout << "Enter a single character to use to display the rectangle: " << flush;
  char choice;
  cin >> choice;
  int rows,cols;
  cout << "Width? " << flush;
  cin >> cols;
  cout << "Height? " << flush;
  cin >> rows;
  cout << endl;

  // draw the rectangle
  // print char col times for every row

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << choice;
    }
    cout << endl; // we've completed a row, so move down 1 to the next row
  }
  cout << endl;
  return 0;
}