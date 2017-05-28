file(GLOB SRCS *.cpp)
add_library(rectlib ${SRCS})
target_include_directories(rectlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rectlib jsoncpp)
