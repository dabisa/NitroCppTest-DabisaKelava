file(GLOB SRCS *.cpp)
add_executable(rect ${SRCS})
target_link_libraries(rect rectlib)
