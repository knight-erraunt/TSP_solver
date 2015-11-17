#ifndef MST_H
#define MST_H
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

#include "euclidean.h"

/*
 *Function taking the coordinates of points and creating the 
 *minimal spanning tree on those point. It is a naive function
 *so creating the MST takes quadratic time. 
 *Returns vector of pair of points between which the edge 
 *belongs to the MST.
 */
std::vector< std::pair<lint, lint> > naive_euclidean_mst(
        const std::vector< std::pair<lint, lint> > & points);


#endif
