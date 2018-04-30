/*
 * PiBot.h
 *
 *  Created on: Apr 29, 2018
 *      Author: Cherie
 */

#include "Dict.h"
#include "Corpus.h"


#ifndef PIBOT_H_
#define PIBOT_H_

class PiBot {
public:
	PiBot();
	void addEntry(string,string,int);
	void printDict() const;
	void printCorpusSummary();
	void loadCorpus();
	void saveCorpus();
	void loadDict();
	void saveDict();
	void addFile(string);
	string randomPhrase(int, char []);
	string genPhrase(int, char []);
	virtual ~PiBot();
private:
	Corpus *p_corpus;
	Dict *words;
	int n_buckets;
	string toLower(string);
	string cleanWord(string);
};

#endif /* PIBOT_H_ */
