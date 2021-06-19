
cmake_minimum_required(VERSION 3.10)

project(randomized-algorithms)
enable_testing()

include_directories(.)

set(CMAKE_CXX_FLAGS "-std=c++17 -msse4.2 -Wall -Wextra -O3 -g")

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

if(APPLE)
    set(EIGEN_PATH /usr/local/include/eigen3)
    find_package(Eigen3 REQUIRED NO_MODULE)
    include_directories(${EIGEN_PATH})
endif()

if(UNIX AND NOT APPLE)
    find_package(Eigen3 REQUIRED NO_MODULE)
    include_directories(${Eigen3_INCLUDE_DIRS})
endif()

add_subdirectory(src)
