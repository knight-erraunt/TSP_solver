#include "tsp_solver.h"

tsp_solver::tsp_solver(const std::vector< std::pair<lint, lint> > &npoints) :
        n(npoints.size()),
        points(npoints),
        current_best(std::numeric_limits<ldouble>::max())
        {}

std::vector< std::pair<lint, lint> > tsp_solver::solve() {
    std::priority_queue< std::pair<ldouble, std::vector< bool > > > for_search;
    std::vector< bool > visited(n, false);
    visited[0] = true;
    for_search.push(make_pair(0, visited));
    while(!for_search.empty()) {
    }
}

ldouble tsp_solver::cost() const {
    return 0;
}

ldouble tsp_solver::heuristics() const {
    return 0;
}



