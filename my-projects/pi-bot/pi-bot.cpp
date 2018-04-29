

#include "PiBot.h"

int main() {
	cout << "Bot Start" << endl;
	PiBot *bot = new PiBot();
	cout << "Load Dict and Corpus, print summary." << endl;
	bot->loadCorpus();
	bot->printCorpusSummary();
	bot->loadDict();
	bot->printDict();
//	cout << "Add entry: test, was, 1" << endl;
//	bot->addEntry("Test","was",1);
//	bot->printDict();
//	cout << "Add text file texxtin" << endl;
//	bot->addFile("textin");
//	bot->printCorpusSummary();
//	bot->printDict();
//	cout << "Save corpus and dict" << endl;
//	bot->saveCorpus();
//	bot->saveDict();
	cout << "Bot is finished. Shutting down." << endl;
	delete bot;

	return 0;
}
