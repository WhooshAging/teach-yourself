/*
 * 	BUGS
 *
 *
 *	{ bought the sport with ent package in feb and have already taken 2 trips over  : { 300 : 1 } }
 *	{ bought the sport with ent package in feb and have already taken 2 trips over  : {  : 301 } }
 *	{ mileage about  : { 19 : 1 } }
 *	{ mileage about  : {  : 20 } }
 *	{ myself are owners of 5 lexus vehicles 2 es 2 gs  : { 1 : 1 } }
 *	{ myself are owners of 5 lexus vehicles 2 es 2 gs  : {  : 2 } }
 *	{ is not very strong and feels only very slightly better than my previous  : { 02 : 1 } }
 *	{ is not very strong and feels only very slightly better than my previous  : {  : 3 } }
 *	{ is not very strong and feels only very slightly better than my previous 02  : { mdx : 2 }
 *	etc.) => etc.
 *	{ - handling on par with best sport sedans very  : { quiet : 2 } }
 *	{ else. oh and the back-up camera does not work well if too much light is  : { shining : 2 }
 *	{  : {  : 1 } }
 *	{  : { car : 2 } }
 *	{  : { economy : 1 } }
 *	{  : { leader : 2 } }
 *	{  : { it : 4 } }
 *	knows... => knows..
 *	{ and i wish i could pair my phone to  : { it-- : 1 }
 *	{ mama. wish it had the power  : { lift : 1 } }
 *	{ - but slightly  : { better : 1 } }
 *
 *
 *
 *
 */




#include "PiBot.h"

void learnLots(PiBot *, int);

int main(int argc, char* argv[]) {

	bool learn = true;
	int learn_n = 20;
	int how_many_phrases = 50;
//
//	if (argc==1) {
//		learn = false;
//		learn_n = 0;
//		how_many_phrases = 25;
//	} else if (argc==2) {
//		learn = true;
//		learn_n
//	}

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
		bot->printDict();
		bot->printCorpusSummary();
	}
	bot->printDict();
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

void learnLots(PiBot *bot, int n) {

//	cout << "Working on file #: " << flush;
	for (int i = 1; i < n + 1; i++) {
//		cout << i << " " << flush;
		cout << setw(8) << "File # : " << setw(2) << i << " " << flush;
		stringstream ss;
		ss << i;
		bot->addFile(ss.str());

	}

	return;
}
