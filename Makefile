CC=g++
INCDIRS=-I.
OPT=-O0
FLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)
RAYLIB=-lraylib
CPPFILES=src/*.cpp
OBJECTS=obj/*.o

BINARY=bin/r1

r1: $(CPPFILES)
	$(CC) $(CPPFILES) $(RAYLIB) -o $(BINARY)


clean:
	rm -rf $(BINARY)
