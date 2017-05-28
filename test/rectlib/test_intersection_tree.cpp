#include <vector>

#include "gtest/gtest.h"

#include "rectangle.h"
#include "intersection_tree.h"

using namespace std;


TEST (IntersectionTree, example) {

    vector<Rectangle> rectangles {
        Rectangle(100, 100, 250, 80),
        Rectangle(120, 200, 250, 150),
        Rectangle(140, 160, 250, 100),
        Rectangle(160, 140, 350, 190)
    };

    vector<Rectangle> expected_result {
        Rectangle(140, 160, 210, 20),
        Rectangle(160, 140, 190, 40),
        Rectangle(140, 200, 230, 60),
        Rectangle(160, 200, 210, 130),
        Rectangle(160, 160, 230, 100),
        Rectangle(160, 160, 190, 20),
        Rectangle(160, 200, 210, 60)
    };

    vector<Rectangle> result;

    IntersectionTree::generate(rectangles).visitInLevelOrder(
    [&result] (const std::vector<unsigned>& ids, const Rectangle& rect) {
        if(ids.size() > 1) {
            result.push_back(rect);
        }
    });

    EXPECT_EQ(result.size(), expected_result.size());
    for(unsigned i = 0; i<result.size(); ++i) {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}
