# Makefile for Elevators
CXXFLAGS = -std=c++14 -w

all: executable

debug: CXXFLAGS += -g

rebuild: clean executable
executable: main.o publication_controller.o publication_view.o publication.o
	$(CXX) $(CXXFLAGS) main.cpp publication_controller.o  publication_view.o publication.o
publication_controller.o: publication_controller.cpp publication_view.h publication.h
	$(CXX) $(CXXFLAGS) -c publication_controller.cpp
publication_view.o: publication_view.cpp
	$(CXX) $(CXXFLAGS) -c publication_view.cpp
publication.o: publication.cpp
	$(CXX) $(CXXFLAGS) -c publication.cpp
clean:
	rm -f *.o a.out
