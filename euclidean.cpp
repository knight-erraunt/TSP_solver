#include "euclidean.h"

ldouble dist(std::pair<lint, lint> a, std::pair<lint, lint> b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + 
            (a.second-b.second)*(a.second-b.second));
}


