#include "mst.h"

// directed edge representation
struct edge {
    edge(lint nbegin, lint nend, ldouble ncost) :
        begin(nbegin), end(nend), cost(ncost) {}
    lint begin, end;
    ldouble cost;
};

// inversed comparison operator as we want the cheapest to be first
bool operator<(const edge & a, const edge & b) {
    return a.cost > b.cost;
}

/*
 * Algorithm for finding MST on a plane uses Prim's algorithm
 * to find the MST returns pairs representing indexes of the matched points
 * complexity: O(n^2 * log(n))
 */
std::vector< std::pair<lint, lint> > naive_euclidean_mst(
        const point_vector & points) {

    ldouble cost = 0;
    lint n = points.size();
    std::vector<bool> already_in_mst(n, false);
    already_in_mst[0] = true;

    std::vector< std::pair<lint, lint> > mst;

    std::priority_queue<edge> potential_edges;

    for(lint i = 1; i < n; i++)
        potential_edges.push(edge(0, i, dist(points[0], points[i])));


    while(!potential_edges.empty()) {
        edge current = potential_edges.top();
        potential_edges.pop();
        if(!already_in_mst[current.end]) {
            cost += current.cost;
            already_in_mst[current.end] = true;
            mst.push_back(std::make_pair(current.begin, current.end));
            for(lint i = 1; i < n; i++)
                if(!already_in_mst[i])
                    potential_edges.push(edge(current.end, i,
                            dist(points[current.end], points[i])));
        }

    }

    return mst;
}


