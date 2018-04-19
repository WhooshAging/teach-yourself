// simple programme looking at switch instead of if if if if ...

#include <iostream>

using namespace std;

int displayMenu();
void processMenuChoice(int);

int main() {
  
  
  cout << "Hello world." << endl;
  
  int choice;
  choice = displayMenu();
  processMenuChoice(choice);
  
  return 0;
}

int displayMenu() {
  cout << endl;
  cout << "1.\tSpam." << endl;
  cout << "2.\tEggs." << endl;
  cout << "3.\tHam." << endl;
  cout << "4.\tAnd Spam." << endl;
  int choice;
  cout << "\nPlease make your choice: " << flush;
  cin >> choice;
  
  
  
  return choice;
}




void processMenuChoice(int choice) {
  cout << endl;
  switch(choice) {
    
    case 1:
      cout << "1xSPAM" << endl;
      break;
    case 2:
      cout << "2xEGGS" << endl;
      break;
    case 3:
      cout << "3xHAM" << endl;
      break;
    case 4:
      cout << "4xAND SPAM" << endl;
      break;
    default:
      cout << "What was that?" << endl;
    
  }
  
  return;
}