

CC = clang
CXX = clang++

CXXFLAGS = -Wall -Wextra -Wpedantic -O2 -std=c++11 -lm


all: greedy_solver mst_solver


greedy_solver: greedy_solver.o tsp_solver.o euclidean.o
	$(CXX) $(CXXFLAGS) -o greedy_solver greedy_solver.o tsp_solver.o euclidean.o

mst_solver: mst_solver.o tsp_solver.o mst.o euclidean.o
	$(CXX) $(CXXFLAGS) -o mst_solver mst_solver.o tsp_solver.o mst.o euclidean.o

mst_solver.o: mst_solver.cpp
	$(CXX) $(CXXFLAGS) -c mst_solver.cpp

greedy_solver.o: greedy_solver.cpp
	$(CXX) $(CXXFLAGS) -c greedy_solver.cpp

tsp_solver.o: tsp_solver.cpp tsp_solver.h
	$(CXX) $(CXXFLAGS) -c tsp_solver.cpp

mst.o: mst.cpp mst.h
	$(CXX) $(CXXFLAGS) -c mst.cpp

euclidean.o: euclidean.cpp euclidean.h
	$(CXX) $(CXXFLAGS) -c euclidean.cpp



clean:
	rm greedy_solver mst_solver *.o


