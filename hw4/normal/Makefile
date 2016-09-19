# Makefile for Elevators
CXXFLAGS = -std=c++14 -w

all: executable

debug: CXXFLAGS += -g

rebuild: clean executable
executable: main.cpp publication_controller.o publication_view.o publication_repo.o publication.o customer.o
	$(CXX) $(CXXFLAGS) main.cpp publication_controller.o publication_view.o publication_repo.o publication.o customer.o
publication_controller.o: publication_controller.cpp publication_view.h publication_repo.h publication.h
	$(CXX) $(CXXFLAGS) -c publication_controller.cpp 
publication_repo.o: publication_repo.cpp publication.h customer.h
	$(CXX) $(CXXFLAGS) -c publication_repo.cpp
publication_view.o: publication_view.cpp publication.h customer.h
	$(CXX) $(CXXFLAGS) -c publication_view.cpp
publication.o: publication.cpp customer.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) -c customer.cpp
clean:
	rm -f *.o a.out
