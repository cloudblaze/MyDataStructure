CXX			= g++
CXXFLAGS	= -g -Wall -std=c++11
LDFLAGS		= -lm

MAKEFLAGS	= -Rr

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

%: %.o
	$(CXX) $^ -o $@ $(LDFLAGS)

all: main

main: main.o TestStack.o

.PHONY: clean

clean:
	rm -f main *.o