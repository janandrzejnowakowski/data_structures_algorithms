cmake_minimum_required(VERSION 3.10)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra -Wpedantic)
endif()

project(data_structures_algorithms)

add_library (LinkedList data_structures/LinkedList.cpp)
target_include_directories (LinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable (swap_every_second_node algorithms/swap_every_second_node.cpp)


target_link_libraries (swap_every_second_node LINK_PUBLIC LinkedList)

