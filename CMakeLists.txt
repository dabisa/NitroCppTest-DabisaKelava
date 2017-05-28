cmake_minimum_required(VERSION 3.5.1)
project(NitroCppTest-DabisaKelava)
set(CMAKE_CXX_STANDARD 14)

include("cmake/googletest.cmake")
include("cmake/jsoncpp.cmake")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
