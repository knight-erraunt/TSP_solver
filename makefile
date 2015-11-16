

CC = clang
CXX = clang++

CXXFLAGS = -Wall -Wextra -Wpedantic -O2 -std=c++11


all: greedy


greedy: tsp_solver.o
	$(CXX) $(CXXFLAGS) -o greedy greedy_solver.cpp tsp_solver.o


tsp_solver.o: tsp_solver.cpp tsp_solver.h
	$(CXX) $(CXXFLAGS) -c tsp_solver.cpp


