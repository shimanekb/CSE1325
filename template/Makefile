SRCDIR = src
INC_SRC_DIR = $(SRCDIR)
TESTDIR=test

CXXFLAGS =-std=c++14 -w -I$(INC_SRC_DIR)
all: executable

debug: CXXFLAGS += -g

rebuild: clean executable
executable: $(SRCDIR)/main.cpp $(SRCDIR)/test.o
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp $(SRCDIR)/test.o
test.o: $(SRCDIR)/test.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/test.cpp 

test: $(TESTDIR)/main_test.cpp $(TESTDIR)/test_test.o $(SRCDIR)/test.o
	$(CXX) $(CXXFLAGS) $(TESTDIR)/main_test.cpp $(TESTDIR)/test_test.o $(SRCDIR)/test.o
test_test.o: $(TESTDIR)/test_test.cpp $(SRC)/test.h $(TESTDIR)/catch.hpp
	$(CXX) $(CXXFLAGS) -c $(TESTDIR)/test_test.cpp 
clean:
	rm -f src/*.o a.out test/*.o
