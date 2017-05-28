file(GLOB SRCS *.cpp)
add_executable(testAll ${SRCS})
target_link_libraries(testAll libgtest libgtest_main rectlib)

# test files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/examples/nitro.json
    ${CMAKE_CURRENT_BINARY_DIR}/nitro.json COPYONLY)
