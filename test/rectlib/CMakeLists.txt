file(GLOB SRCS *.cpp)
add_executable(testAll ${SRCS})
target_link_libraries(testAll libgtest libgtest_main rectlib)

# test files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/examples/nitro.json
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nitro.json COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/examples/nitro_duplicated.json
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nitro_duplicated.json COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/examples/parse_error.json
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/parse_error.json COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/examples/invalid_data.json
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/invalid_data.json COPYONLY)

