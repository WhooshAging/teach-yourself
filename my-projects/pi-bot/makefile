pi-bot: pi-bot.o PiBot.o Dict.o Corpus.o Bucket.o
	g++ -o pi-bot PiBot.o Dict.o Corpus.o Bucket.o

<<<<<<< HEAD
=======
pi-bot.o : pi-bot.cpp
	g++ -c pi-bot.cpp

>>>>>>> a99182c2f0b3298ff00def39ac7c16bba0ec420d
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
