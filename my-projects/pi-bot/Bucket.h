/*
 * Bucket.h
 *
 *  Created on: Apr 25, 2018
 *      Author: Cherie
 */

#include <iostream>
#include <vector>

using namespace std;

#ifndef BUCKET_H_
#define BUCKET_H_



class Bucket {
private:
	int id;
	int how_many;
	vector<string> words;
	string toLower(string);

public:
	static int count;

	Bucket();
	void loadData();
	void saveData();
	void addWord(string);

	int getID() const;
	string getRandomWord() const;
	int getHowMany() const {return how_many;} ;


	virtual ~Bucket();
};

#endif /* BUCKET_H_ */
