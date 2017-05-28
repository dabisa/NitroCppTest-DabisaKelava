#include <cstddef>
#include <algorithm>
#include <stdexcept>

#include "interval.h"


Interval Interval::createIntersection(const Interval& interval1, const Interval& interval2) {

    if(interval1.contains(interval2.getFirst())) {
        const int left = interval2.getFirst();
        const int right = std::min(interval2.getLast(), interval1.getLast());
        return Interval(left, right - left);

    } else if(interval2.contains(interval1.getFirst())) {
        const int left = interval1.getFirst();
        const int right = std::min(interval1.getLast(), interval2.getLast());
        return Interval(left, right - left);

    } else {
        throw std::domain_error("intervals do not intersect");
    }
}
