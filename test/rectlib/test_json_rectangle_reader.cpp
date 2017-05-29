#include <vector>

#include "gtest/gtest.h"

#include "rectangle.h"
#include "json_rectangle_reader.h"

using namespace std;


const char* nitro_file_name = "nitro.json";
const char* nitro_duplicated_file_name = "nitro_duplicated.json";
const char* parse_error_file_name = "parse_error.json";
const char* invalid_data_file_name = "invalid_data.json";


TEST(JsonRectangleReader, nitro_example) {
    vector<Rectangle> expected_result {
        Rectangle(100, 100, 250, 80),
        Rectangle(120, 200, 250, 150),
        Rectangle(140, 160, 250, 100),
        Rectangle(160, 140, 350, 190)
    };
    vector<Rectangle> result = JsonRectangleReader(nitro_file_name).read();

    EXPECT_EQ(result.size(), expected_result.size());
    for (unsigned i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}

TEST(JsonRectangleReader, limited_input) {
    vector<Rectangle> expected_result {
        Rectangle(100, 100, 250, 80),
        Rectangle(120, 200, 250, 150),
        Rectangle(140, 160, 250, 100)
    };
    vector<Rectangle> result = JsonRectangleReader(nitro_duplicated_file_name, 3).read();

    EXPECT_EQ(result.size(), expected_result.size());
    for (unsigned i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}

TEST(JsonRectangleReader, invalid_data) {
    EXPECT_THROW(JsonRectangleReader(invalid_data_file_name).read(), JsonRectangleReader::InvalidDataError);
}

TEST(JsonRectangleReader, parse_error) {
    EXPECT_THROW(JsonRectangleReader(parse_error_file_name).read(), JsonRectangleReader::ParsingError);
}
