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

TEST(Set, SplayListImpl) {
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