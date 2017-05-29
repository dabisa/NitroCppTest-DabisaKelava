#ifndef _JSON_RECTANGLE_READER_H_
#define _JSON_RECTANGLE_READER_H_

#include <stdexcept>

#include "rectangle.h"

/**
 * \brief This class is used to read rectangles from json file.
 */
class JsonRectangleReader {

public:

	class InvalidDataError : public std::runtime_error {

	public:

		InvalidDataError(std::string description) : std::runtime_error(description) {}
		static InvalidDataError generateItemError(std::string description, unsigned id);
	};

	JsonRectangleReader(const char* file_name, unsigned max_rectangles = INFINITE_RECTANGLES)
	 : file_name_(file_name), max_rectangles_(max_rectangles) {}

	std::vector<Rectangle> read() const;

private:

	static constexpr unsigned INFINITE_RECTANGLES = 0;

	const char* file_name_;
	unsigned max_rectangles_; 
};

#endif // _JSON_RECTANGLE_READER_H_
