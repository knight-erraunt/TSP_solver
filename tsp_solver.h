#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <queue>
#include <vector>

#include "euclidean.h"

#define NOT_VISITED (-1)


struct search_state {
    search_state(const std::vector<lint> & nvisit_order, lint ncurrent,
        ldouble ncost, lint nexp_cost) :
        visit_order(nvisit_order),
        current(ncurrent),
        cost(ncost),
        exp_cost(nexp_cost)
        {}

    search_state(const search_state & a) :
        visit_order(a.visit_order),
        current(a.current),
        cost(a.cost),
        exp_cost(a.exp_cost)
        {}

    search_state() {}

    std::vector<lint> visit_order;
    lint current;
    ldouble cost, exp_cost;
};

class tsp_solver {
    ldouble current_best;
    std::vector< std::pair<lint, lint> > points;
    std::vector<lint> best_order;
    lint n;
public:
    tsp_solver(const std::vector< std::pair<lint, lint> > &npoints);
    
    std::vector<lint> solve(); 
    ldouble path_len() const;
    ldouble cost(lint, lint) const;
    virtual ldouble heuristics(
            const std::vector< std::pair<lint, lint> > & points,
            const search_state & current, const lint next) const = 0;
};



#endif
