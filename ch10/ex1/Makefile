vpath = %.cpp src
vpath = %.h src

CXXFLAGS =-std=c++14 -w
all: executable

rebuild: clean executable
executable: main.cpp
	$(CXX) $(CXXFLAGS) $^
clean:
	rm -f src/*.o a.out 
