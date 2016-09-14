# Makefile for Elevators
CXXFLAGS = -std=c++14

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: test_elevator.cpp controller.o view.o elevator.o select_floor.o
	$(CXX) $(CXXFLAGS) test_elevator.cpp controller.o view.o elevator.o select_floor.o
controller.o: controller.cpp globals.h view.h elevator.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp
test_elevator.o: test_elevator.cpp elevator.h
	$(CXX) $(CXXFLAGS) -w -c test_elevator.cpp
elevator.o: elevator.cpp elevator.h
	$(CXX) $(CXXFLAGS) -w -c elevator.cpp
clean:
	rm -f *.o a.out
