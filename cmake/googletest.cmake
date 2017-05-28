find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(googletest-project
    URL https://github.com/google/googletest/archive/release-1.8.0.zip
    URL_HASH SHA256=f3ed3b58511efd272eb074a3a6d6fb79d7c2e6a0e374323d1e6bcbcc1ef141bf
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/deps/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(googletest-project INSTALL_DIR)

# libgtest
add_library(libgtest STATIC IMPORTED GLOBAL)
add_dependencies(libgtest googletest-project)
set(GTEST_LIBRARY ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX})
set(GTEST_INCLUDE_DIR ${INSTALL_DIR}/include)
set_target_properties(libgtest PROPERTIES
	"IMPORTED_LOCATION" ${GTEST_LIBRARY}
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
include_directories(${GTEST_INCLUDE_DIR})

# libgtest_main
add_library(libgtest_main STATIC IMPORTED GLOBAL)
add_dependencies(libgtest_main googletest-project)
set(GTEST_MAIN_LIBRARY ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX})
set(GTEST_MAIN_INCLUDE_DIR ${INSTALL_DIR}/include)
set_target_properties(libgtest_main PROPERTIES
	"IMPORTED_LOCATION" ${GTEST_MAIN_LIBRARY}
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
include_directories(${GTEST_MAIN_INCLUDE_DIR})

# libgmock
#add_library(libgmock IMPORTED STATIC GLOBAL)
#add_dependencies(libgmock googletest-project)
#set(GMOCK_LIBRARY ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gmock${CMAKE_STATIC_LIBRARY_SUFFIX})
#set(GMOCK_INCLUDE_DIR ${INSTALL_DIR}/include)
#set_target_properties(libgmock PROPERTIES
#	"IMPORTED_LOCATION" ${GMOCK_LIBRARY}}
#   "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
#include_directories(${GMOCK_INCLUDE_DIR})

unset(INSTALL_DIR)
