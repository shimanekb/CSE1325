vpath %.h src test
vpath %.cpp src test
vpath %.o src test
vpath %.hpp test

OBJS := part_controller.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^
part_controller.o: part_controller.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

test: main_test.cpp part_controller_test.o
	$(CXX) $(CXXFLAGS) $^ 
part_controller_test.o: part_controller_test.cpp catch.hpp
	$(CXX) $(CXXFLAGS) -c $< $@ 
clean:
	rm -f src/*.o a.out test/*.o
