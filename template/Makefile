vpath %.h src test
vpath %.cpp src test
vpath %.o src test
vpath %.hpp test

OBJS := test.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

test: main_test.cpp test_test.o test.o
	$(CXX) $(CXXFLAGS) $^ 
test_test.o: test_test.cpp test.h catch.hpp
	$(CXX) $(CXXFLAGS) -c $< $@ 
clean:
	rm -f src/*.o a.out test/*.o
