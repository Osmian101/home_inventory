CC=g++
CFLAGS=-I.
make: main.cpp
	$(CC) -Wall -Wextra main.cpp $(CFLAGS) 
