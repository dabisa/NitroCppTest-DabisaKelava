#include "gtest/gtest.h"

#include "rectangle.h"


TEST (Rectangle, constructor) {

    Rectangle rect(-10, -5, 20, 30);

    EXPECT_EQ (rect.getLeft(), -10);
    EXPECT_EQ (rect.getRight(), 10);
    EXPECT_EQ (rect.getTop(), -5);
    EXPECT_EQ (rect.getBottom(), 25);
    EXPECT_EQ (rect.getWidth(), 20);
    EXPECT_EQ (rect.getHeight(), 30);
    EXPECT_EQ (rect, Rectangle(-10, -5, 20, 30));

    EXPECT_THROW (Rectangle(0, 0, 0, 1), std::invalid_argument);
    EXPECT_THROW (Rectangle(0, 0, 1, 0), std::invalid_argument);
    EXPECT_THROW (Rectangle(0, 0, -1, 1), std::invalid_argument);
    EXPECT_THROW (Rectangle(0, 0, 1, -1), std::invalid_argument);
    EXPECT_THROW (Rectangle(0, 0, 0, 0), std::invalid_argument);
    EXPECT_THROW (Rectangle(0, 0, -1, -1), std::invalid_argument);
}

TEST (Rectangle, intersection_none) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(20, 20, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}

TEST (Rectangle, intersection_only_x) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(5, 20, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}

TEST (Rectangle, intersection_only_y) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(20, 5, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}


TEST (Rectangle, intersection_touching) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(10, 10, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}

TEST (Rectangle, intersection_touching_x) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(10, 0, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}

TEST (Rectangle, intersection_touching_y) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(0, 10, 10, 10);

    EXPECT_FALSE (Rectangle::canIntersect(a, b));
    EXPECT_FALSE (Rectangle::canIntersect(b, a));

    EXPECT_THROW (Rectangle::createIntersection(a, b), std::domain_error);
    EXPECT_THROW (Rectangle::createIntersection(b, a), std::domain_error);
}

TEST (Rectangle, intersection_intersected) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(5, 7, 10, 10);

    EXPECT_TRUE (Rectangle::canIntersect(a, b));
    EXPECT_TRUE (Rectangle::canIntersect(b, a));

    Rectangle c = Rectangle::createIntersection(a, b);
    Rectangle d = Rectangle::createIntersection(b, a);

    EXPECT_EQ (c, d);
    EXPECT_EQ (c, Rectangle(5, 7, 5, 3));
}

TEST (Rectangle, intersection_equal) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(0, 0, 10, 10);

    EXPECT_TRUE (Rectangle::canIntersect(a, b));
    EXPECT_TRUE (Rectangle::canIntersect(b, a));

    Rectangle c = Rectangle::createIntersection(a, b);
    Rectangle d = Rectangle::createIntersection(b, a);

    EXPECT_EQ (c, d);
    EXPECT_EQ (c, Rectangle(0, 0, 10, 10));
}

TEST (Rectangle, intersection_inside) {

    Rectangle a = Rectangle(0, 0, 10, 10);
    Rectangle b = Rectangle(2, 2, 6, 6);

    EXPECT_TRUE (Rectangle::canIntersect(a, b));
    EXPECT_TRUE (Rectangle::canIntersect(b, a));

    Rectangle c = Rectangle::createIntersection(a, b);
    Rectangle d = Rectangle::createIntersection(b, a);

    EXPECT_EQ (c, d);
    EXPECT_EQ (c, Rectangle(2, 2, 6, 6));
}
