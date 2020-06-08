//
// Created by ivan on 08.06.20.
//

#include <gtest/gtest.h>
#include "../src/containers/Set/Set.hpp"


TEST(Set, SplayTreeImpl) {
    Set<SplayTree<int>> set;
    set.insert(6);
    EXPECT_FALSE(set.count(4));
    EXPECT_FALSE(set.count(2));
    EXPECT_TRUE(set.count(6));
    set.erase(4);
    set.erase(6);
    EXPECT_FALSE(set.count(6));
    auto node = set.search(4);
    EXPECT_EQ(node, nullptr);
}

TEST(Set, ListImpl) {
    Set<SingleLinkedOrderedList<int>> set;
    set.insert(6);
    EXPECT_FALSE(set.count(4));
    EXPECT_FALSE(set.count(2));
    EXPECT_TRUE(set.count(6));
    set.erase(4);
    set.erase(6);
    EXPECT_FALSE(set.count(6));
    auto node = set.search(4);
    EXPECT_EQ(node, nullptr);
}

TEST(Set, Add1) {
    Set<SplayTree<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = Union(set1, set2);
    for (int i = 0; i < 15; ++i)
        EXPECT_TRUE(set3.count(1));
}

TEST(Set, Add2) {
    Set<SingleLinkedOrderedList<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = Union(set1, set2);
    for (int i = 0; i < 15; ++i)
        EXPECT_TRUE(set3.count(1));
}

TEST(Set, Sub1) {
    Set<SplayTree<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = set1 - set2;
    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 5; i < 15;++i)
        EXPECT_TRUE(!set3.count(i));
}

TEST(Set, Sub2) {
    Set<SingleLinkedOrderedList<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = set1 - set2;
    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 5; i < 15;++i)
        EXPECT_TRUE(!set3.count(i));
}

TEST(Set, Intersection1) {
    Set<SingleLinkedOrderedList<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = Intersection(set1, set2);
    for (int i = 0; i < 5; ++i)
        EXPECT_FALSE(set3.count(i));
    for (int i = 5; i < 10;++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 10; i < 15; ++i)
        EXPECT_FALSE(set3.count(i));
}

TEST(Set, Intersection2) {
    Set<SplayTree<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = Intersection(set1, set2);
    for (int i = 0; i < 5; ++i)
        EXPECT_FALSE(set3.count(i));
    for (int i = 5; i < 10;++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 10; i < 15; ++i)
        EXPECT_FALSE(set3.count(i));
}

TEST(Set, SymmetricDifference1) {
    Set<SplayTree<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = SymmetricDifference(set1, set2);
    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 5; i < 10;++i)
        EXPECT_FALSE(set3.count(i));
    for (int i = 10; i < 15; ++i)
        EXPECT_TRUE(set3.count(i));
}

TEST(Set, SymmetricDifference2) {
    Set<SingleLinkedOrderedList<int>> set1, set2;
    for (int i = 0; i < 10; ++i)
        set1.insert(i);
    for (int i = 5; i < 15; ++i)
        set2.insert(i);
    auto set3 = SymmetricDifference(set1, set2);
    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(set3.count(i));
    for (int i = 5; i < 10;++i)
        EXPECT_FALSE(set3.count(i));
}