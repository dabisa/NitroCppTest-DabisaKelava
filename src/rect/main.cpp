#include <iostream>

#include "rectangle.h"

int main(int argc, char* argv[]) {

    std::string name = Rectangle::test();
    std::cout << "Hello " << name << "!" << std::endl;

    return 0;
}
