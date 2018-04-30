pi-bot: pi-bot.o PiBot.o Dict.o Corpus.o Bucket.o
	g++ -o pi-bot PiBot.o Dict.o Corpus.o Bucket.o

pi-bot.o : pi-bot.cpp
	g++ -c pi-bot.cpp

PiBot.o: PiBot.cpp
	g++ -c PiBot.cpp

Dict.o: Dict.cpp
	g++ -c Dict.cpp

Corpus.o: Corpus.cpp
	g++ -c Corpus.cpp

Bucket.o: Bucket.cpp
	g++ -c Bucket.cpp

all: pi-bot;

clean:
	rm -f pi-bot *.o