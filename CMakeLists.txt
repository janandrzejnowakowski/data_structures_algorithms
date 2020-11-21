cmake_minimum_required(VERSION 3.10)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra -Wpedantic)
endif()

project(data_structures_algorithms)

add_library (LinkedList INTERFACE)
target_include_directories(LinkedList INTERFACE .)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(testLinkedList tests/testLinkedList.cpp)
target_link_libraries(testLinkedList ${GTEST_LIBRARIES} pthread LinkedList)
