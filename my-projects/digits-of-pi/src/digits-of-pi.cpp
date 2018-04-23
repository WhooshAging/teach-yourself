//============================================================================
// Name        : digits-of-pi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : How I wish I could calculate Pi ... (3.141592 ... )
//				 Load of large corpus of text
//				 Build arrays of word lengths from 1-9
//				 Build new phrases to be used to remember digits of PI
//               Uses ML to pick sensible next words
//				 Twitter Bot? Tweets new phrases, replies to tweets specifying a word or # digits?
//============================================================================

#include <iostream>
#include <fstream>


using namespace std;

int main() {

	// Set what we want to use for pi
	const double PI = 3.1415926;
	// open and read our file
	ifstream my_file;
	my_file.open("data/google-10000-most-frequent.txt");
	if (!my_file) {
		cout << "Error loading file. Exiting." << endl;
		exit(1); // call system to stop, shit went bad son.
	} else {
		cout << "File loaded." << endl;
	}
	// read like cin

	string x;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int count7 = 0;
	int count8 = 0;
	int count9 = 0;
	int notused = 0;
	int length = 0;

	while (my_file >> x) {
		//cout << x << endl;
		length = x.size();
		//cout << length << endl;
		switch (length) {
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
			break;
		case 5:
			count5++;
			break;
		case 6:
			count6++;
			break;
		case 7:
			count7++;
			break;
		case 8:
			count8++;
			break;
		case 9:
			count9++;
			break;
		default:
			notused++;
		}
	}

	// make arrays by word lenght, now we know how many of each we have
	// but requires another loop over the file in order to assign to arrays
	// anyway around this?

	string words1[count1] = { };
	string words2[count2] = { };
	string words3[count3] = { };
	string words4[count4] = { };
	string words5[count5] = { };
	string words6[count6] = { };
	string words7[count7] = { };
	string words8[count8] = { };
	string words9[count9] = { };

	// now we are EOF so need to reset
	// and seek to beginning of file
	// before we loop again

	my_file.clear();
	my_file.seekg(0, ios::beg);

	x = "";
	count1 = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;
	count5 = 0;
	count6 = 0;
	count7 = 0;
	count8 = 0;
	count9 = 0;
	notused = 0;
	length = 0;

	while (my_file >> x) {
		//cout << x << endl;
		length = x.size();
		//cout << length << endl;
		switch (length) {
		case 1:
			words1[count1] = x;
			count1++;
			break;
		case 2:
			words2[count2] = x;
			count2++;
			break;
		case 3:
			words3[count3] = x;
			count3++;
			break;
		case 4:
			words4[count4] = x;
			count4++;
			break;
		case 5:
			words5[count5] = x;
			count5++;
			break;
		case 6:
			words6[count6] = x;
			count6++;
			break;
		case 7:
			words7[count7] = x;
			count7++;
			break;
		case 8:
			words8[count8] = x;
			count8++;
			break;
		case 9:
			words9[count9] = x;
			count9++;
			break;
		default:
			notused++;
		}
	}

	my_file.close(); // don't forget or bad things will happen

	cout << "Results of building arrays:" << endl;
	cout << "# Letters \t # Items in Array \t First Entry" << endl;
	cout << "1   \t\t " << sizeof(words1) / sizeof(string) << "    \t\t\t "
			<< words1[0] << endl;
	cout << "2   \t\t " << sizeof(words2) / sizeof(string) << "    \t\t "
			<< words2[0] << endl;
	cout << "3   \t\t " << sizeof(words3) / sizeof(string) << "    \t\t "
			<< words3[0] << endl;
	cout << "4   \t\t " << sizeof(words4) / sizeof(string) << "    \t\t "
			<< words4[0] << endl;
	cout << "5   \t\t " << sizeof(words5) / sizeof(string) << "    \t\t "
			<< words5[0] << endl;
	cout << "6   \t\t " << sizeof(words6) / sizeof(string) << "    \t\t "
			<< words6[0] << endl;
	cout << "7   \t\t " << sizeof(words7) / sizeof(string) << "    \t\t "
			<< words7[0] << endl;
	cout << "8   \t\t " << sizeof(words8) / sizeof(string) << "    \t\t "
			<< words8[0] << endl;
	cout << "9   \t\t " << sizeof(words9) / sizeof(string) << "    \t\t "
			<< words9[0] << endl;
	cout << "10+ \t\t " << "N/A " << "(" << notused << ") skipped" << "   \t\t "
			<< "N/A" << endl;

	cout << endl;

	cout << "PI is: " << PI << endl;

	return 0;
}
