DFLAGS	= -DDEBUG_INFO

CXX			= g++
CXXFLAGS	= -g -Wall -std=c++11 $(DFLAGS)
LDFLAGS		= -lm

MAKEFLAGS	= -Rr -B

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

%: %.o
	$(CXX) $^ -o $@ $(LDFLAGS)

TestModules	= TestVector.o TestLinkVector.o TestStack.o TestQueue.o

all: clear_screen main demo exec

main: main.o $(TestModules)

.PHONY: clear_screen exec clean

clear_screen:
	clear

exec:
	./main

clean:
	rm -f main demo *.o