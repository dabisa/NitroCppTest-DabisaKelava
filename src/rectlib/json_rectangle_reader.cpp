#include <algorithm>
#include <fstream>
#include <sstream>

#include "json/json.h"

#include "rectangle.h"
#include "json_rectangle_reader.h"


JsonRectangleReader::InvalidDataError JsonRectangleReader::InvalidDataError::generateItemError(std::string description, unsigned id) {
	std::ostringstream ss;
	ss << description << " for rectangle " << id;
	return InvalidDataError(ss.str());
}

std::vector<Rectangle> JsonRectangleReader::read() const {

	std::ifstream file_stream(file_name_);

	Json::Value root;
	file_stream >> root;

	const Json::Value rects = root["rects"];
	if(rects.isNull()) {
		throw InvalidDataError("No rectangles found");
	}

	unsigned number_of_rectangles = (max_rectangles_ == INFINITE_RECTANGLES) ? rects.size() : std::min(max_rectangles_, rects.size());

	std::vector<Rectangle> rectangles;
	rectangles.reserve(number_of_rectangles);

	for(unsigned i = 0; i < number_of_rectangles; ++i) {

		const Json::Value rect = rects[i];

		const Json::Value x = rect["x"];
		if(x.isNull()) {
			throw InvalidDataError::generateItemError("Missing x", i);
		}
	
		const Json::Value y = rect["y"];
		if(y.isNull()) {
			throw InvalidDataError::generateItemError("Missing y", i);
		}

		const Json::Value w = rect["w"];
		if(w.isNull()) {
			throw InvalidDataError::generateItemError("Missing w", i);
		}

		const Json::Value h = rect["h"];
		if(h.isNull()) {
			throw InvalidDataError::generateItemError("Missing h", i);
		}

		int left = x.asInt();
		int top = y.asInt();
		int width = w.asInt();
		int height = h.asInt();

		if(width > 0 && height > 0) {
			rectangles.push_back(Rectangle(left, top, width, height));
		} else {
			throw InvalidDataError::generateItemError("Invalid size", i);
		}
	}

	return rectangles;
}
