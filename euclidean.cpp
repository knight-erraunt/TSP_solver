#include "euclidean.h"

ldouble dist(const point & a, const point & b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + 
            (a.second-b.second)*(a.second-b.second));
}

