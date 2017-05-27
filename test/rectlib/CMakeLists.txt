file(GLOB SRCS *.cpp)
add_executable(testAll ${SRCS})
target_link_libraries(testAll libgtest libgtest_main rectlib)
