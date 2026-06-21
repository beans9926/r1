CC=g++
INCDIRS=-I. -Iinclude
LIBDIRS=-Llib
OPT=-O0
FLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)
RAYLIB=-lraylib -lopengl32 -lgdi32 -lwinmm
CPPFILES=src/*.cpp

BINARY=bin/r1

r1: $(CPPFILES)
	mkdir -p bin
	$(CC) $(FLAGS) $(CPPFILES) $(LIBDIRS) $(RAYLIB) -o $(BINARY)


clean:
	rm -rf $(BINARY)
