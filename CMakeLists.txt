cmake_minimum_required(VERSION 3.10)

option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra -Wpedantic)
    if (ENABLE_COVERAGE)
        add_compile_options(--coverage -O0)
    endif()
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(data_structures_algorithms)

add_library(data_structures_algorithms INTERFACE)
target_include_directories(data_structures_algorithms INTERFACE .)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(testLinkedList tests/testLinkedList.cpp)
target_link_libraries(testLinkedList ${GTEST_LIBRARIES} pthread --coverage data_structures_algorithms)
add_executable(testStack tests/testStack.cpp)
target_link_libraries(testStack ${GTEST_LIBRARIES} pthread --coverage data_structures_algorithms)
add_executable(testBinaryTree tests/testBinaryTree.cpp)
target_link_libraries(testBinaryTree ${GTEST_LIBRARIES} pthread --coverage data_structures_algorithms)
