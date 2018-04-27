#include <iostream>
#include <sstream>
using namespace std;


int main()
{
      string s;

      s = "hello";

	  stringstream ss;
	  ss << s;

	  float num = 0;

	  ss >> num;

	  if(ss.good()) {
		  cout << "No Valid Number" << endl;
	  }
	  else if(num == 0 && s[0] != 0) {
		  cout << "No Valid Number" << endl;
	  }
	  else {
		cout << num << endl;
	  }
}
