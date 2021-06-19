
cmake_minimum_required(VERSION 3.10)

project(randomized-algorithms)
enable_testing()

include_directories(.)

set(CMAKE_CXX_FLAGS "-std=c++20 -msse4.2 -Wall -Wextra -O3 -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/../Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else (DOXYGEN_FOUND)
    message("Package Doxygen not found!")
endif (DOXYGEN_FOUND)

include_directories(${Eigen3_INCLUDE_DIR})

add_subdirectory(test)
