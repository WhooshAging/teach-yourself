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
#include <sstream>
#include <stdlib.h> // rand
#include <ctime> // to seed rang

using namespace std;

int main() {
	
	// seed rand func
	srand ( time(NULL) );

	// open and read our file
	ifstream my_file;
	my_file.open("data/src/google-10000-most-frequent.txt");
	if (!my_file) {
		cout << "Error loading file. Exiting." << endl;
		exit(1); // call system to stop, shit went bad son.
	} else {
		cout << "File loaded." << endl;
	}
	// read like cin

	string x;
	int total = 0;
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
		total++;
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
	
	
	// save the arrays so we can clean up
	// and generally 'do stuff with'
	
	ofstream myfile;
	// should be a func - duh!
	
	myfile.open ("data/1.txt");
	// save how many as first line
	myfile << (int)sizeof(words1)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words1)/sizeof(string); i++) {
		myfile << words1[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/2.txt");
	// save how many as first line
	myfile << (int)sizeof(words2)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words2)/sizeof(string); i++) {
		myfile << words2[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/3.txt");
	// save how many as first line
	myfile << (int)sizeof(words3)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words3)/sizeof(string); i++) {
		myfile << words3[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/4.txt");
	// save how many as first line
	myfile << (int)sizeof(words4)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words4)/sizeof(string); i++) {
		myfile << words4[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/5.txt");
	// save how many as first line
	myfile << (int)sizeof(words5)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words5)/sizeof(string); i++) {
		myfile << words5[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/6.txt");
	// save how many as first line
	myfile << (int)sizeof(words6)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words6)/sizeof(string); i++) {
		myfile << words6[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/7.txt");
	// save how many as first line
	myfile << (int)sizeof(words7)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words7)/sizeof(string); i++) {
		myfile << words7[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/8.txt");
	// save how many as first line
	myfile << (int)sizeof(words8)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words8)/sizeof(string); i++) {
		myfile << words8[i];
		myfile << "\n";
	}
	myfile.close();
	
	myfile.open ("data/9.txt");
	// save how many as first line
	myfile << (int)sizeof(words9)/sizeof(string);
	myfile << "\n";
	for (int i=0; i<(int)sizeof(words9)/sizeof(string); i++) {
		myfile << words9[i];
		myfile << "\n";
	}
	myfile.close();
	
	// phew !
	

	
	
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
	cout << "TOTAL (from file): " << total << endl;
	cout << "TOTAL (from arrays): " << sizeof(words1) / sizeof(string) + sizeof(words2) / sizeof(string) +
				sizeof(words3) / sizeof(string) + sizeof(words4) / sizeof(string) +
				sizeof(words5) / sizeof(string) + sizeof(words6) / sizeof(string) +
				sizeof(words7) / sizeof(string) + sizeof(words8) / sizeof(string) +
				sizeof(words9) / sizeof(string) + notused << endl;
	

	cout << endl;
	// Set what we want to use for pi
	const char PI[] = "31415926";

	//cout << "PI is: " << PI << endl;
	//cout << "sizeof(pi) = " << sizeof(PI) << endl;

	// loop over digits of pi
	// pick random words from the appropriate array

	int j, choice;
	stringstream ss;
	for (int i = 0; i < (int) sizeof(PI) - 1; i++) {
		if (i != 0) {
			ss << "\t";
		}
		// can only switch on an int
		// some magic required to convert from char to int e.g. '1' -> 1;
		j = PI[i] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		switch (j) {
		case 0:
			break;
		case 1:
			choice = rand() % (int) sizeof(words1) / sizeof(string);
			//cout << "Choice 0 of words1: " << words1[0] << endl;
			//cout << "Random choice of words1 " << words1[choice] << endl;
			ss << words1[choice];
			break;
		case 2:
			choice = rand() % (int) sizeof(words2) / sizeof(string);
			//cout << "Choice 0 of words2: " << words2[0] << endl;
			//cout << "Random choice of words2 " << words2[choice] << endl;
			ss << words2[choice];
			break;
		case 3:
			choice = rand() % (int) sizeof(words3) / sizeof(string);
			//cout << "Choice 0 of words3: " << words3[0] << endl;
			//cout << "Random choice of words3 " << words3[choice] << endl;
			ss << words3[choice];
			break;
		case 4:
			choice = rand() % (int) sizeof(words4) / sizeof(string);
			//cout << "Choice 0 of words4: " << words4[0] << endl;
			//cout << "Random choice of words4 " << words4[choice] << endl;
			ss << words4[choice];
			break;
		case 5:
			choice = rand() % (int) sizeof(words5) / sizeof(string);
			//cout << "Choice 0 of words5: " << words5[0] << endl;
			//cout << "Random choice of words5 " << words5[choice] << endl;
			ss << words5[choice];
			break;
		case 6:
			choice = rand() % (int) sizeof(words6) / sizeof(string);
			//cout << "Choice 0 of words6: " << words6[0] << endl;
			//cout << "Random choice of words6 " << words6[choice] << endl;
			ss << words6[choice];
			break;
		case 7:
			choice = rand() % (int) sizeof(words7) / sizeof(string);
			//cout << "Choice 0 of words7: " << words7[0] << endl;
			//cout << "Random choice of words7 " << words7[choice] << endl;
			ss << words7[choice];
			break;
		case 8:
			choice = rand() % (int) sizeof(words8) / sizeof(string);
			//cout << "Choice 0 of words8: " << words8[0] << endl;
			//cout << "Random choice of words8 " << words8[choice] << endl;
			ss << words8[choice];
			break;
		case 9:
			choice = rand() % (int) sizeof(words9) / sizeof(string);
			//cout << "Choice 0 of words9: " << words9[0] << endl;
			//cout << "Random choice of words9 " << words9[choice] << endl;
			ss << words9[choice];
			break;
		default:
			// no default case, just do nothing
			break;

		}
	}
	
	stringstream ss2;
	for (int i=0; i<(int)sizeof(PI); i++) {
		ss2 << PI[i];
		if (i == 0) {
			ss2 << ".";
		}
		if (PI[i] == '9') { // extra tab for longest word
			ss2 << "\t";
		}
		ss2 << "\t";
	}
	cout << ss2.str() << endl;
	cout << ss.str() << endl;

	return 0;
}
