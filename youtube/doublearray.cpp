// double array init and looping "challenge"

#include <iostream>

using namespace std;

void showArray(int*,int); //prototype the func the * means a pass a pointer of the object

main() {

	int values[10];
  
  //cout << endl;
	//cout << sizeof(values) << endl; // returns size ** in MEM**
	//cout << sizeof(int) << endl; // returns size in mem

	// so the number of elements in our array ("length") is sizeof array / sizeof data type

	// initialise the array
	// if we don't we will get nonsense when indexing the array
	// note no "Index Out Of Range" errors !!!
  
  cout << endl;
  cout << "Initialising an array by specifying a size and looping over it." << endl;
  
  for (int i=0; i < sizeof(values)/sizeof(int);i++){
  	values[i] = 0;
  }

  // now if we loop and display we get what we expect
  // rewrote this as a func

  showArray(values,sizeof(values));

  // instead of the init above, we could do

  cout << "Initialising an array with {}" << endl;

  int vals[10] = {};

  showArray(vals,sizeof(values));
  
  // and now let's do it for a double array
  // [2][3] is 2 rows, 3 columns
  // Arrays like matrices - rows and then columns

  string animals[2][3] = {
  	{"Duck","Chicken","Cow"},
  	{"Quck","Bock","Moo"}
  };
  
  // remmeber C++ gives sizes of actual things in memory in bytes ...
  // I don't think that is accurate, but I know what I mean ... oops
  
  cout << "Size of [2][3] array of strings: " << sizeof(animals) << endl;
  cout << "Size of string: " << sizeof(string) << endl;
  cout << "Size of each row: " << sizeof(animals[0]) << endl;
  cout << "Therefore there are " << sizeof(animals)/sizeof(animals[0]) << " rows." << endl;
  cout << "Therefore there are " << sizeof(animals[0])/sizeof(string) << " cols." << endl;

  // Now let's try and loop over the 2D array and print it
  cout << "\nLooping over our 2D array we have the following entries:\n" << endl;
  for (int i=0;i<sizeof(animals)/sizeof(animals[0]) ;i++) {
    for (int j=0;j<sizeof(animals[0])/sizeof(string);j++) {
    	cout << animals[i][j] << endl;
    }
  }
  
  // Now let's try and loop over the 2D array and print it
  cout << "\nNow let's loop and print the array as structured: \n" << endl;
  for (int i=0;i<sizeof(animals)/sizeof(animals[0]) ;i++) {
    for (int j=0;j<sizeof(animals[0])/sizeof(string);j++) {
    	cout << animals[i][j] << " " << flush;
    }
  cout << endl;
  }
  
  
  

	return 0;
}


// func to just loop over an array and print elemtns.
// can't pass the actual array
// can instead pass a pointer as a name
// becuase we can't pass the actual array we must pass its size as a param


void showArray(int my_array[], int size) {
  for (int i=0; i < size/sizeof(int);i++){
  	cout << "Index: " << i << " | Value: " << my_array[i] << endl;
  }
  cout << endl;
  
}