#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <queue>
#include <vector>

using lint = long;
using ldouble = double;

class tsp_solver {
    ldouble current_best;
    std::vector< std::pair<lint, lint> > points;
    lint n;
public:
    tsp_solver(const std::vector< std::pair<lint, lint> > &npoints);
    
    std::vector< std::pair<lint, lint> > solve(); 
    ldouble cost() const;
    ldouble heuristics() const;
};



#endif
