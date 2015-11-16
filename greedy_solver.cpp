#include <cstdio>
#include "tsp_solver.h"

class greedy_tsp_solver : public tsp_solver {
public:
    using tsp_solver::tsp_solver;
    ldouble heuristics(lint next) const;
};

ldouble greedy_tsp_solver::heuristics(lint next) const {
    return 0;
}

int main() {
    lint n;
    scanf("%ld", &n);
    std::vector< std::pair<lint, lint> > points(n);
    for(int i=0; i<n; i++)
        scanf("%ld %ld", &points[i].first, &points[i].second);
    greedy_tsp_solver A(points);
    std::vector<lint> order = A.solve();
    for(int i=0; i<order.size(); i++)
        printf("%ld ", order[i]);
    printf("\n");

    return 0;
}


