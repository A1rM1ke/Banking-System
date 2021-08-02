sourcefiles = main.cpp application.cpp
CC = g++-11
CFLAGS = -std=c++17 -Wall -o
OUTPUT = program.out

all: compile run

run:
	./$(OUTPUT)

compile:
	$(CC) $(CFLAGS) $(OUTPUT) $(sourcefiles)
