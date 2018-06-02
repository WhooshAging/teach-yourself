/*
 * 	BUGS
 *
 *
 *	knows... => knows..
 * impressive...lots => .l
 *	on...The => .t
 *	Acura/Honda ==> rejected, too long
 *	h/o => ho
 *	on...The => .t
 *	4X4's => xs
 * 90's ==> s
 *
 *
 *
 *
 */

#include <iomanip>
#include "PiBot.h"

void learnLots(PiBot *, int, bool &);

int main(int argc, char* argv[]) {

	bool learn = true;
	bool istest = true;


	int learn_n = 5;
	int how_many_phrases = 100;
//
//	if (argc==1) {
//		learn = false;
//		learn_n = 0;
//		how_many_phrases = 25;
//	} else if (argc==2) {
//		learn = true;
//		learn_n
//	}

	//cout << "Bot Start" << endl;
	PiBot *bot = new PiBot();
	//cout << "Load Dict and Corpus, print summary." << endl;
	bot->loadCorpus();

	bot->loadDict();

	cout << "CORPUS SUMMARY" << endl;
	bot->printCorpusSummary();

	if (learn == true) {
		learnLots(bot, learn_n, istest);
		bot->saveCorpus();
		bot->saveDict();
		//bot->printDict();
		bot->printCorpusSummary();
	}
//	bot->printDict();
	char my_pi[] = "31415926";
	int n_digits = sizeof(my_pi);
	const int n_to_gen = how_many_phrases;
	cout << endl;

	string phrase;
	string word;
	const int W = 15;
	cout << setw(W) << left << "3" << setw(W) << left << "1" << setw(W) << left << "4" << setw(W) << left <<
			"1" << setw(W) << left << "5" << setw(W) << left << "9" << setw(W) << left << "2" <<
			setw(W) << "6" << endl;
	for (int i=0; i<(n_digits-1) * W; i++) {
		cout << "-" << flush;
	}
	cout << endl;

	for (int i = 0; i < n_to_gen; i++) {
		//phrase = bot->randomPhrase(n_digits, my_pi);
		//cout << "Random phrase: \t" << phrase << endl;
		//cout << " ~~~~~~~~~~~~~~~ " << endl;
		phrase = bot->genPhrase(n_digits, my_pi);
//		cout << " TRACE PHRASE IS: " << phrase << endl;
		  for (string::iterator it=phrase.begin(); it!=phrase.end(); it++) {
			  if (*it == '[') {
				  word += *it;
			  } else if (*it == ']') {
				  word += *it;
				  if (it+1 == phrase.end()) {
				  cout << left << setw(W) << word << flush;
				  word.clear();
				  }
			  } else if (*it == ' ') {
				  cout << left << setw(W) << word << flush;
				  word.clear();
			  } else {
				  word += *it;
			  }
		  }
		  cout << endl;
	}
	cout << endl;

	cout << "\nBot is finished. Shutting down." << endl;

	/*
	 cout << "Bot Start" << endl;
	 PiBot *bot = new PiBot();
	 //cout << "Load Dict and Corpus, print summary." << endl;
	 bot->loadCorpus();
	 cout << "CORPUS SUMMARY" << endl;
	 bot->printCorpusSummary();
	 bot->loadDict();
	 //cout << "DICT SUMMARY" << endl;
	 //bot->printDict();
	 cout << "Add entry: test, was, 1" << endl;
	 //	bot->addEntry("Test","was",1);
	 //	bot->printDict();
	 //	cout << "Add text file texxtin" << endl;
	 bot->addFile("textin");
	 bot->printCorpusSummary();
	 bot->printDict();
	 cout << "Save corpus and dict" << endl;
	 bot->saveCorpus();
	 bot->saveDict();
	 */

	delete bot;
	return 0;
}

void learnLots(PiBot *bot, int n, bool &testflag) {

	if (testflag == true) {
		bot->addFile("testing");
	} else {

//	cout << "Working on file #: " << flush;
	for (int i = 0; i <= n ; i++) {
//		cout << i << " " << flush;
		cout << "\n" << "File # : " << i << "\n" << endl;
		stringstream ss;
		ss << i;
		bot->addFile(ss.str());

	}
	}
	return;
}
