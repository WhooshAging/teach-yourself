#include "PiBot.h"


void learnLots(PiBot *);

int main() {

	cout << "Bot Start" << endl;
	PiBot *bot = new PiBot();
	//cout << "Load Dict and Corpus, print summary." << endl;
	bot->loadCorpus();
	cout << "CORPUS SUMMARY" << endl;
	bot->printCorpusSummary();
	bot->loadDict();
	learnLots(bot);
	char my_pi[] = "31415926";
	int n_digits = sizeof(my_pi);
	int n_to_gen = 10;
	cout << endl;
	string phrase;
	for (int i = 0; i < n_to_gen; i++) {
		phrase = bot->randomPhrase(n_digits, my_pi);
		cout << "Random phrase: \t" << phrase << endl;

		phrase = bot->genPhrase(n_digits, my_pi);
		cout << "Generated phrase: \t" << phrase << endl;
		cout << endl;
	}
	cout << "Bot is finished. Shutting down." << endl;
	 bot->saveCorpus();
	 bot->saveDict();



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


void learnLots(PiBot *bot) {
	cout << "Working on file #: " << flush;
	for (int i=1; i<11; i++) {
		cout << i << " " << flush;
		stringstream ss;
		ss << i;
		bot->addFile(ss.str());

	}



	return;
}
