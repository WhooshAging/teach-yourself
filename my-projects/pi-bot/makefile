pi-bot: Bucket.o Corpus.o Dict.o PiBot.o pi-bot.o
	g++ -o pi-bot Bucket.o Corpus.o Dict.o PiBot.o pi-bot.o

Bucket.o: Bucket.cpp Bucket.h
	g++ -c Bucket.cpp

Corpus.o: Corpus.cpp Corpus.h
	g++ -c Corpus.cpp

Dict.o: Dict.cpp Dict.h
	g++ -c Dict.cpp

PiBot.o: PiBot.cpp PiBot.h
	g++ -c PiBot.cpp

pi-bot.o: pi-bot.cpp
	g++ -c pi-bot.cpp

all: pi-bot;

clean:
	rm -f pi-bot *.o


