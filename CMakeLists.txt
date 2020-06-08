cmake_minimum_required(VERSION 3.15)
project(oop_exam)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_exam main.cpp src/Server/Server.cpp src/Server/Server.hpp src/structures/AVLTree.hpp src/structures/AVLTree.tpp
        src/structures/BPlusTree.hpp src/structures/BPlusTree.tpp src/structures/SplayTree.hpp src/structures/Tree.hpp)