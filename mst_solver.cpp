#include <cstdio>

#include "tsp_solver.h"
#include "mst.h"

class mst_tsp_solver : public tsp_solver {
public:
    using tsp_solver::tsp_solver;
    ldouble heuristics(
            const point_vector & points,
            const search_state & current, const lint next) const;    
};

ldouble mst_tsp_solver::heuristics(
        const point_vector & points,
        const search_state & current, const lint next) const {

    point_vector for_mst;

    ldouble min_mst_to_next_dist = big_ldouble,
            min_mst_to_first_dist = big_ldouble,
            mst_cost = 0;

    for(lint i = 0; i < current.visit_order.size(); i++)
        if(i != next && current.visit_order[i] == NOT_VISITED) {
            for_mst.push_back(points[i]);
            min_mst_to_next_dist = std::min(min_mst_to_next_dist,
                                    dist(points[i], points[next]));
            min_mst_to_first_dist = std::min(min_mst_to_first_dist,
                                    dist(points[i], points[0]));
        }

    if(for_mst.size() < 1)
        return 0;

    std::vector< std::pair<lint, lint> > mst =
        naive_euclidean_mst(for_mst);

    for(lint i = 0; i < mst.size(); i++)
        mst_cost += dist(for_mst[mst[i].first], for_mst[mst[i].second]);

    // return the final approximation of the cost
    return min_mst_to_first_dist + min_mst_to_next_dist + mst_cost;
}

int main() {
    lint n;
    scanf("%ld", &n);
    point_vector points(n);
    for(int i=0; i<n; i++)
        scanf("%ld %ld", &points[i].first, &points[i].second);
    mst_tsp_solver A(points);
    std::vector<lint> order = A.solve();
    printf("%lf\n", A.path_len());
    for(int i=0; i<order.size(); i++)
        printf("%ld ", order[i]);
    printf("\n");

    return 0;
}




