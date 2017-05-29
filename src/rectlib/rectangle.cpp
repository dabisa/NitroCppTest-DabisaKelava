#include "rectangle.h"

Rectangle Rectangle::createIntersection(const Rectangle& first, const Rectangle& second) {
    Interval hinterval = Interval::createIntersection(first.hinterval_, second.hinterval_);
    Interval vinterval = Interval::createIntersection(first.vinterval_, second.vinterval_);
    return Rectangle(hinterval, vinterval);
}
