include(ExternalProject)
ExternalProject_Add(jsoncpp-project
    URL https://github.com/open-source-parsers/jsoncpp/archive/1.7.7.tar.gz
    URL_HASH SHA256=087640ebcf7fbcfe8e2717a0b9528fff89c52fcf69fa2a18cc2b538008098f97
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/deps/jsoncpp
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
               -DCMAKE_POSITION_INDEPENDENT_CODE=On
               -DJSONCPP_WITH_TESTS=Off
               -DJSONCPP_WITH_PKGCONFIG_SUPPORT=Off
)
ExternalProject_Get_Property(jsoncpp-project INSTALL_DIR)

# jsoncpp
add_library(jsoncpp STATIC IMPORTED)
add_dependencies(jsoncpp jsoncpp-project)
set(JSONCPP_LIBRARY ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}jsoncpp${CMAKE_STATIC_LIBRARY_SUFFIX})
set(JSONCPP_INCLUDE_DIR ${INSTALL_DIR}/include)
file(MAKE_DIRECTORY ${JSONCPP_INCLUDE_DIR})  # Must exist.
set_target_properties(jsoncpp PROPERTIES
    "IMPORTED_LOCATION" ${JSONCPP_LIBRARY}
    "INTERFACE_INCLUDE_DIRECTORIES" ${JSONCPP_INCLUDE_DIR}
)
include_directories(${JSONCPP_INCLUDE_DIR})

unset(INSTALL_DIR)
