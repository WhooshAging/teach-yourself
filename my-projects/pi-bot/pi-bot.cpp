#include "PiBot.h"

void learnLots(PiBot *, int);

int main() {

	bool learn = true;
	int learn_n = 5;
	const int how_many_phrases = 25;

	cout << "Bot Start" << endl;
	PiBot *bot = new PiBot();
	//cout << "Load Dict and Corpus, print summary." << endl;
	bot->loadCorpus();

	bot->loadDict();

	cout << "CORPUS SUMMARY" << endl;
	bot->printCorpusSummary();

	if (learn == true) {
		learnLots(bot, learn_n);
		bot->saveCorpus();
		bot->saveDict();
	}

	char my_pi[] = "31415926";
	int n_digits = sizeof(my_pi);
	const int n_to_gen = how_many_phrases;
	cout << endl;

	string phrase;
	string word;
	bool first;

	for (int i = 0; i < n_to_gen; i++) {
		first = true;
		//phrase = bot->randomPhrase(n_digits, my_pi);
		//cout << "Random phrase: \t" << phrase << endl;
		//cout << " ~~~~~~~~~~~~~~~ " << endl;
		phrase = bot->genPhrase(n_digits, my_pi);

		istringstream iss(phrase);

		cout << "Seed: [" << flush;
		while (iss >> word) {
			if (first) {
				cout << word << "] \n " << flush;
				first = false;
			}

			cout << "Generated phrase: \t" << phrase << endl;
		}
		//cout << endl;
	}
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

void learnLots(PiBot *bot, int n) {
//	cout << "Working on file #: " << flush;
	for (int i = 1; i < n + 1; i++) {
//		cout << i << " " << flush;
		stringstream ss;
		ss << i;
		bot->addFile(ss.str());

	}

	return;
}
