cmake_minimum_required(VERSION 3.10)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra -Wpedantic)
endif()

project(data_structures_algorithms)

add_library (LinkedList data_structures/LinkedList.cpp algorithms/swap_every_second_node.cpp)
target_include_directories (LinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(testLinkedList tests/testLinkedList.cpp)
target_link_libraries(testLinkedList ${GTEST_LIBRARIES} pthread LinkedList)
