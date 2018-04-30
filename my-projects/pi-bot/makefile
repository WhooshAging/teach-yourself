pi-bot: PiBot.o Dict.o Corpus.o Bucket.o
	g++ -o pi-bot PiBot.o Dict.o Corpus.o Bucket.o

PiBot.o: PiBot.cpp PiBot.h
	g++ -c PiBot.cpp

Dict.o: Dict.cpp Dict.h
	g++ -c Dict.cpp

Corpus.o: Corpus.cpp Corpus.h
	g++ -c Corpus.cpp

Bucket.o: Bucket.cpp Bucket.h
	g++ -c Bucket.cpp

all: pi-bot;

clean:
	rm -f pi-bot *.o