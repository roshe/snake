#Makefile for Snake. Hopefully this won't go TOO badly.

Snake: main.o Snake.o
	g++ -Wall -pedantic -lncurses -o Snake main.o Snake.o

main.o: main.cpp Snake.h
	g++ -Wall -pedantic -c main.cpp

Snake.o: Snake.cpp Snake.h
	g++ -Wall -pedantic -c  Snake.cpp

clean:
	rm *o Snake
