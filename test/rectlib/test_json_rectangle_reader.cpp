#include <vector>

#include "gtest/gtest.h"

#include "rectangle.h"
#include "json_rectangle_reader.h"

using namespace std;


TEST (JsonRectangleReader, example) {

    vector<Rectangle> expected_result {
        Rectangle(100, 100, 250, 80),
        Rectangle(120, 200, 250, 150),
        Rectangle(140, 160, 250, 100),
        Rectangle(160, 140, 350, 190)
    };

    const char* file_name = "nitro.json";
    vector<Rectangle> result = JsonRectangleReader(file_name).read();

    EXPECT_EQ(result.size(), expected_result.size());
    for(unsigned i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}