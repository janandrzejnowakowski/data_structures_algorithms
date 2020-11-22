cmake_minimum_required(VERSION 3.10)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra -Wpedantic)
endif()

project(data_structures_algorithms)

add_library(data_structures_algorithms INTERFACE)
target_include_directories(data_structures_algorithms INTERFACE .)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(testLinkedList tests/testLinkedList.cpp)
target_link_libraries(testLinkedList ${GTEST_LIBRARIES} pthread data_structures_algorithms)
add_executable(testStack tests/testStack.cpp)
target_link_libraries(testStack ${GTEST_LIBRARIES} pthread data_structures_algorithms)
add_executable(testBinaryTree tests/testBinaryTree.cpp)
target_link_libraries(testBinaryTree ${GTEST_LIBRARIES} pthread data_structures_algorithms)
