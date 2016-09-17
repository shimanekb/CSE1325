# Makefile for Elevators
CXXFLAGS = -std=c++14 -w -c

all: publication.o

debug: CXXFLAGS += -g

rebuild: clean publication.o
publication.o: publication.cpp
	$(CXX) $(CXXFLAGS) publication.cpp
clean:
	rm -f *.o a.out
