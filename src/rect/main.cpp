#include <iostream>
#include <vector>

#include "rectangle.h"
#include "json_rectangle_reader.h"
#include "intersection_tree.h"

using namespace std;


int process(const char* file_name);
void printInput(int id, const Rectangle& rect);
void printIntersection(const std::vector<unsigned>& ids, const Rectangle& rect);
std::ostream& operator<<(std::ostream& stream, const Rectangle& rect);

/**
 * \brief Application entry point
 *
 * Checks if input file is specified:
 * - if specified, proceeds with execution
 * - if not, prints 'usage' line
 */
int main(int argc, char* argv[]) {
    if (argc >= 2) {
        return process(argv[1]);
    } else {
        cout << "Usage: rect <json_input_file>" << endl;
        return -1;
    }
}

/**
 * \brief This function implements the main workflow of the application.
 *
 * - Read rectangles from input file in josn format
 * - Print input
 * - Calculate all intersections between input rectangles.
 * - Print output
 */
int process(const char* file_name) {
    try {
        // Read rectangles
        constexpr unsigned MAX_RECTANGLES = 10;
        vector<Rectangle> rectangles = JsonRectangleReader(file_name, MAX_RECTANGLES).read();

        // Print input
        cout << "Input:" << endl;
        for (unsigned i = 0; i < rectangles.size(); ++i) {
            printInput(i, rectangles[i]);
        }

        // Calculate all intersections
        IntersectionTree intersection_tree = IntersectionTree::generate(rectangles);

        // Print output
        cout << endl << "Intersections:" << endl;
        intersection_tree.visitInLevelOrder(
        [] (const std::vector<unsigned>& ids, const Rectangle& rect) {
            printIntersection(ids, rect);
        });
        cout << endl;

        return 0;
    } catch(JsonRectangleReader::ParsingError err) {
        std::cout << "parsing error: " << err.what();
        return -1;
    } catch(JsonRectangleReader::InvalidDataError err) {
        std::cout << "invalid data: " << err.what() << "\n";
        return -1;
    }
}

/**
 * \brief Prints line describing input rectangle
 */
void printInput(int id, const Rectangle& rect) {
    cout << "      " << id + 1 << ": Rectangle at " << rect << "." << endl;
}

/**
 * \brief Prints line describing intersection
 */
void printIntersection(const std::vector<unsigned>& ids, const Rectangle& rect) {
    if (ids.size() >= 2) {
        cout << "      Between rectangle ";
        for (unsigned i = 0; i < ids.size(); ++i) {
            const char* separator = (i < ids.size() - 2) ? ", " : (i == ids.size() - 2) ? " and " : "";
            cout << ids[i] + 1 << separator;
        }
        cout << " at " << rect << "." << endl;
    }
}

/**
 * \brief Prints rectangle to stream
 */
std::ostream& operator<<(std::ostream& stream, const Rectangle& rect) {
    stream << "(" << rect.getLeft() << "," << rect.getTop() << "), w=" << rect.getWidth() << ", h=" << rect.getHeight();
    return stream;
}
