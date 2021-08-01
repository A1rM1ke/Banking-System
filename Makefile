sourcefiles = main.cpp

all: compile run

run:
	./program.out

compile:
	g++-11 -std=c++11 -Wall -o program.out $(sourcefiles)