# Makefile for Elevators
CXXFLAGS = 

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: controller.o view.o elevator.o select_floor.o
	$(CXX) $(CXXFLAGS) controller.o view.o elevator.o select_floor.o
controller.o: controller.cpp globals.h view.h elevator.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp
view.o: view.cpp view.h globals.h view.h elevator.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c view.cpp
elevator.o: elevator.cpp elevator.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c elevator.cpp
select_floor.o: select_floor.cpp select_floor.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c select_floor.cpp
clean:
	rm -f *.o a.out
