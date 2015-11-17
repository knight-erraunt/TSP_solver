#include "tsp_solver.h"


// inversed comparison operator as we want the cheapest to be first
bool operator<(const search_state & a, const search_state & b) {
    return a.exp_cost > b.exp_cost;
}

tsp_solver::tsp_solver(const std::vector< std::pair<lint, lint> > &npoints) :
        n(npoints.size()),
        points(npoints),
        current_best(std::numeric_limits<ldouble>::max())
        {}

std::vector<lint> tsp_solver::solve() {
    std::priority_queue< search_state > for_search;
    std::vector<lint> visited(n, NOT_VISITED);
    visited[0] = 0;
    for_search.push( search_state(visited, 0, 0, 0) );
    while(!for_search.empty()) {
        search_state A = for_search.top(), B;
        for_search.pop();
        if(std::all_of(A.visit_order.begin(), A.visit_order.end(),
                    [](lint a){return a != NOT_VISITED;})) {
            if(current_best > A.cost + cost(0, A.current)) {
                current_best = A.cost + cost(0, A.current);
                best_order = A.visit_order;
            }
            continue;
        }
        for(lint i=1; i<A.visit_order.size(); i++)
            if(A.visit_order[i] == NOT_VISITED) {
                ldouble expected_cost = A.cost + cost(A.current, i) + heuristics(i);
                if(expected_cost < current_best) {
                    B = A;
                    B.visit_order[i] = A.visit_order[A.current] + 1;
                    B.current = i;
                    B.cost = A.cost + cost(A.current, i);
                    B.exp_cost = expected_cost;
                    for_search.push(B);
                }
            }

    }
    return best_order;
}

ldouble dist(std::pair<lint, lint> a, std::pair<lint, lint> b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + 
            (a.second-b.second)*(a.second-b.second));
}

ldouble tsp_solver::cost(lint curret_node, lint next_node) const {
    return dist(points[curret_node], points[next_node]);
}

ldouble tsp_solver::path_len() const {
    return current_best;
}



