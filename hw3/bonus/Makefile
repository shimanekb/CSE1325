# Makefile for Elevators
CXXFLAGS = -std=c++14

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: test_elevator.o elevator.o 	
	$(CXX) $(CXXFLAGS) test_elevator.o elevator.o
test_elevator.o: test_elevator.cpp elevator.h
	$(CXX) $(CXXFLAGS) -w -c test_elevator.cpp
elevator.o: elevator.cpp elevator.h
	$(CXX) $(CXXFLAGS) -w -c elevator.cpp
clean:
	rm -f *.o a.out
