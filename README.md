# data_structures_algorithms

Repository with data structures and algorithms.

## Requirements:
* cmake
* GTest

## How to install requirements on Ubuntu:

* cmake:
    sudo apt install cmake

* GTest:
    sudo apt install libgtest-dev
    cd /usr/src/gtest
    sudo cmake .
    sudo make
    sudo cp *.a /usr/lib

## To compile the project, in the main project folder run the following commands:
    mkdir build && cd build
    cmake ..
    make
