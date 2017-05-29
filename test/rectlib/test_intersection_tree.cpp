#include <vector>
#include <cmath>

#include "gtest/gtest.h"

#include "rectangle.h"
#include "intersection_tree.h"

using namespace std;


void testForExpectedOutput(const vector<Rectangle>& input, const vector<Rectangle>& expected_output) {
    vector<Rectangle> result;
    IntersectionTree::generate(input).visitInLevelOrder(
    [&result] (const std::vector<unsigned>& ids, const Rectangle& rect) {
        if(ids.size() > 1) {
            result.push_back(rect);
        }
    });

    EXPECT_EQ(result.size(), expected_output.size());
    for(unsigned i = 0; i<result.size(); ++i) {
        EXPECT_EQ(result[i], expected_output[i]);
    }
}

void testWorstCaseInputSize(int input_size) {
    vector<Rectangle> input (input_size, Rectangle(0, 0, 10, 10));

    vector<Rectangle> result;
    IntersectionTree::generate(input).visitInLevelOrder(
    [&result] (const std::vector<unsigned>& ids, const Rectangle& rect) {
        if(ids.size() > 1) {
            result.push_back(rect);
        }
    });

    int output_size = result.size();
    int expected_size = std::pow(2, input_size) - input_size - 1; // all posible subsets excluding single element set and empty set
    EXPECT_EQ(output_size, expected_size);
}

TEST (IntersectionTree, nitro_example) {

    vector<Rectangle> input {
        Rectangle(100, 100, 250, 80),
        Rectangle(120, 200, 250, 150),
        Rectangle(140, 160, 250, 100),
        Rectangle(160, 140, 350, 190)
    };

    vector<Rectangle> expected_output {
        Rectangle(140, 160, 210, 20),
        Rectangle(160, 140, 190, 40),
        Rectangle(140, 200, 230, 60),
        Rectangle(160, 200, 210, 130),
        Rectangle(160, 160, 230, 100),
        Rectangle(160, 160, 190, 20),
        Rectangle(160, 200, 210, 60)
    };

    testForExpectedOutput(input, expected_output);
}

TEST (IntersectionTree, empty) {
    vector<Rectangle> input {};
    vector<Rectangle> expected_output {};
    testForExpectedOutput(input, expected_output);
}

TEST (IntersectionTree, single) {
    vector<Rectangle> input {
        Rectangle(100, 100, 250, 80)
    };
    vector<Rectangle> expected_output {};
    testForExpectedOutput(input, expected_output);
}

TEST (IntersectionTree, two) {
    vector<Rectangle> input {
        Rectangle(100, 100, 250, 80),
        Rectangle(150, 110, 250, 80)
    };
    vector<Rectangle> expected_output {
        Rectangle(150, 110, 200, 70)
    };
    testForExpectedOutput(input, expected_output);
}

TEST (IntersectionTree, worst_case_input_vs_output_size) {
    for (int input_size = 0; input_size <= 10; ++input_size) {
        testWorstCaseInputSize(input_size);
    }
}
