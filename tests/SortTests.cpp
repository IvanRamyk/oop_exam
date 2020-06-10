//
// Created by hryhorchuk117 on 10/06/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Sort/Sort.h"
#include <functional>

TEST(Sort, selectionSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.selectionSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, heapSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.heapSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, mergeSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.mergeSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, countingSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.selectionSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, insertionSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.insertionSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, radixSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.selectionSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

TEST(Sort, quickSort) {
    std::vector<int> vec = {1, 9, 6, 4, 2, 3, 5, 7, 8, 0};
    std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sort<int> sort(vec);
    std::function<bool(int, int)> f = [](int lhs, int rhs){ return  lhs < rhs;};
    sort.quickSort(f);
    auto res = sort.getData();
    EXPECT_TRUE(sort.getData() == sorted);
}

