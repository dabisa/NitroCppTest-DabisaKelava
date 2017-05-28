#include "gtest/gtest.h"

#include "interval.h"


TEST (Interval, constructor) {

    Interval interval(-10, 100);

    EXPECT_EQ (interval.getFirst(), -10);
    EXPECT_EQ (interval.getLast(), 90);
    EXPECT_EQ (interval.getSize(), 100);
    EXPECT_EQ (interval, Interval(-10, 100));

    EXPECT_THROW (Interval(10,0), std::invalid_argument);
    EXPECT_THROW (Interval(10,-100), std::invalid_argument);
}

TEST (Interval, contains) {

    const int first = -10;
    const int last = 5;
    const int size = last - first;

    Interval interval(first, size);

    for(int i = first; i < last; ++i) {
        EXPECT_TRUE(interval.contains(i));
    }

    EXPECT_FALSE (interval.contains(first-1));
    EXPECT_FALSE (interval.contains(last));
}

TEST (Interval, intersection_disjoined) {

    Interval a = Interval(10, 10); // [10, 20>
    Interval b = Interval(30, 10); // [30, 40>

    EXPECT_FALSE (Interval::canIntersect(a, b));
    EXPECT_FALSE (Interval::canIntersect(b, a));

    EXPECT_THROW (Interval::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Interval::createIntersection(b, a), std::domain_error);
}

TEST (Interval, intersection_touching) {

    Interval a = Interval(10, 10); // [10, 20>
    Interval b = Interval(20, 10); // [20, 30>

    EXPECT_FALSE (Interval::canIntersect(a, b));
    EXPECT_FALSE (Interval::canIntersect(b, a));

    EXPECT_THROW (Interval::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Interval::createIntersection(b, a), std::domain_error);
}

TEST (Interval, intersection_intersected) {

    Interval a = Interval(10, 15); // [10, 25>
    Interval b = Interval(20, 15); // [20, 35>

    EXPECT_TRUE (Interval::canIntersect(a, b));
    EXPECT_TRUE (Interval::canIntersect(b, a));

    Interval c = Interval::createIntersection(a, b);
    Interval d = Interval::createIntersection(b, a);

    EXPECT_EQ(c, d);
    EXPECT_EQ(c, Interval(20, 5));
}

TEST (Interval, intersection_equal) {

    Interval a = Interval(10, 30); // [10, 40>
    Interval b = Interval(10, 30); // [10, 40>

    EXPECT_TRUE (Interval::canIntersect(a, b));

    Interval c = Interval::createIntersection(a, b);
    Interval d = Interval::createIntersection(b, a);

    EXPECT_EQ(c, d);
    EXPECT_EQ(c, Interval(10, 30));
}

TEST (Interval, intersection_inside) {

    Interval a = Interval(10, 30); // [10, 40>
    Interval b = Interval(20, 10); // [20, 30>

    EXPECT_TRUE (Interval::canIntersect(a, b));
    EXPECT_TRUE (Interval::canIntersect(b, a));

    Interval c = Interval::createIntersection(a, b);
    Interval d = Interval::createIntersection(b, a);

    EXPECT_EQ(c, d);
    EXPECT_EQ(c, Interval(20, 10));
}
