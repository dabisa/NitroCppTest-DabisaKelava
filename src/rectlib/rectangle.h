#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "interval.h"


class Rectangle {
public:
    Rectangle(int left, int top, int width, int height) : hinterval_(left, width), vinterval_(top, height) {}

    Rectangle(const Interval& hinterval, const Interval& vinterval) : hinterval_(hinterval), vinterval_(vinterval) {}

    bool operator==(const Rectangle& other) const {
        return (hinterval_ == other.hinterval_) && (vinterval_ == other.vinterval_);
    }

    static bool canIntersect(const Rectangle& rect1, const Rectangle& rect2) {
        return Interval::canIntersect(rect1.hinterval_, rect2.hinterval_) && Interval::canIntersect(rect1.vinterval_, rect2.vinterval_);
    }

    static Rectangle createIntersection(const Rectangle& first, const Rectangle& second);

    int getLeft() const {
        return hinterval_.getFirst();
    }
    int getTop() const {
        return vinterval_.getFirst();
    }
    int getRight() const {
        return getLeft() + getWidth();
    }
    int getBottom() const {
        return getTop() + getHeight();
    }
    int getWidth() const {
        return hinterval_.getSize();
    }
    int getHeight() const {
        return vinterval_.getSize();
    }

private:
    const Interval hinterval_;
    const Interval vinterval_;
};

#endif // _RECTANGLE_H_
