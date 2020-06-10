cmake_minimum_required(VERSION 3.15)
project(oop_exam)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(tests/lib/googletest-master)
include_directories(tests/lib/googletest-master/googletest/include)
include_directories(tests/lib/googletest-master/googlemock/include)

add_executable(oop_exam main.cpp src/Server/Server.cpp src/Server/Server.hpp src/structures/balanced_searched_trees/AVLTree.hpp
        src/structures/balanced_searched_trees/AVLTree.tpp
        src/structures/balanced_searched_trees/BPlusTree.hpp src/structures/balanced_searched_trees/BPlusTree.tpp
        src/structures/balanced_searched_trees/SplayTree.hpp src/structures/balanced_searched_trees/Tree.hpp
        tests/SplayTreeTests.cpp
        src/Date/Date.hpp tests/DateTimeTests.cpp src/structures/lists/SingleLinkedList/SingleLinkedList.hpp
        tests/SingleLinkedListTests.cpp src/containers/Set/Set.hpp src/containers/Set/SetOperations.hpp tests/SetTests.cpp
        src/structures/lists/SingleLinkedList/SingleLinkedOrderedList.hpp src/containers/Map/Map.hpp tests/MapTests.cpp
        src/Date/Date.cpp src/Sort/Sort.cpp src/Sort/Sort.h tests/SortTests.cpp src/Hash/QuadraticHash.h src/Hash/CuckooHash.h src/Hash/HopscotchHash.h tests/QuadraricHashTest.cpp tests/CuckooHashTest.cpp tests/HopscotchHashTest.cpp)

target_link_libraries(oop_exam gtest gtest_main)