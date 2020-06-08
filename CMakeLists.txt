cmake_minimum_required(VERSION 3.15)
project(oop_exam)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(tests/lib/googletest-master)
include_directories(tests/lib/googletest-master/googletest/include)
include_directories(tests/lib/googletest-master/googlemock/include)

add_executable(oop_exam main.cpp src/Server/Server.cpp src/Server/Server.hpp src/structures/balanced_searched_trees/AVLTree.hpp src/structures/balanced_searched_trees/AVLTree.tpp
        src/structures/balanced_searched_trees/BPlusTree.hpp src/structures/balanced_searched_trees/BPlusTree.tpp src/structures/balanced_searched_trees/SplayTree.hpp src/structures/balanced_searched_trees/Tree.hpp tests/SplayTreeTests.cpp)

target_link_libraries(oop_exam gtest gtest_main)