#include <iostream>
#include <iomanip>
#include <vector>

#include "json/json.h"

#include "rectangle.h"
#include "json_rectangle_reader.h"
#include "intersection_tree.h"

using namespace std;


std::ostream& operator<< (std::ostream& stream, const Rectangle& rect);
void printInput(int id, const Rectangle& rect);
void printIntersection(const std::vector<unsigned>& ids, const Rectangle& rect);
int process(const char* file_name);


int main(int argc, char* argv[]) {

	if( argc >= 2 ) {

		return process(argv[1]);

	} else {

		cout << "Input file not specified." << endl;
		return -1;
	}
}

std::ostream& operator<< (std::ostream& stream, const Rectangle& rect) {
	stream << "(" << rect.getLeft() << "," << rect.getTop() << "), w=" << rect.getWidth() << ", h=" << rect.getHeight();
	return stream;
}

void printInput( int id, const Rectangle& rect ) {
	cout << "      " << id + 1 << ": Rectangle at " << rect << "." << endl;
}

void printIntersection( const std::vector<unsigned>& ids, const Rectangle& rect ) {

	if( ids.size() >= 2 ) {
		cout << "      Between rectangle ";
		for(int i = 0; i < ids.size(); ++i) {
			const char* separator = (i < ids.size() - 2) ? ", " : (i == ids.size() - 2) ? " and " : "";
			cout << ids[i] + 1 << separator;
		}
		cout << " at " << rect << "." << endl;
	}
}

int process(const char* file_name) {

	try {
		constexpr int MAX_RECTANGLES = 10;

		vector<Rectangle> rectangles = JsonRectangleReader(file_name, MAX_RECTANGLES).read();

		cout << "Input:" << endl;

			for(int i = 0; i < rectangles.size(); ++i) {
			printInput(i, rectangles[i]);
		}
		
		cout << endl << "Intersections:" << endl;

		IntersectionTree::generate(rectangles).visitInLevelOrder(
			[] (const std::vector<unsigned>& ids, const Rectangle& rect) {
				printIntersection(ids, rect);
			});

		cout << endl;

		return 0;

	} catch(Json::RuntimeError err) {

		std::cout << "parsing error: " << err.what();
		return -1;

	} catch(JsonRectangleReader::InvalidDataError err) {

		std::cout << "invalid data: " << err.what() << "\n";
		return -1;
	}
}
