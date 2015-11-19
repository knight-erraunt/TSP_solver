#ifndef UTILS_H
#define UTILS_H

#include <cfloat>
#include <cmath>
#include <utility>
#include <vector>

using lint = long;
using ldouble = double;

using point = std::pair<lint, lint>;
using point_vector = std::vector<point>;

const ldouble big_ldouble = DBL_MAX;


ldouble dist(const point & a, const point & b);


#endif
