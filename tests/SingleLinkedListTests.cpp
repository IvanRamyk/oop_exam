//
// Created by ivan on 08.06.20.
//

#include <gtest/gtest.h>
#include "../src/structures/lists/SingleLinkedList/SingleLinkedList.hpp"
#include <vector>

TEST(SingleLinled, withInt) {
    SingleLinkedList<int> list;
    for (int i = 0; i < 10; ++i)
        list.push_back(i);
    for (int i = 0; i < 10; ++i)
        EXPECT_EQ(i, list.select(i));
    for (int i = 0; i < 5; ++i)
        list.erase(2);
    EXPECT_EQ(5, list.size());
    for (int i = 0; i < 2; ++i)
        EXPECT_EQ(i, list.select(i));
    for (int i = 2; i < 5; ++i)
        EXPECT_EQ(i + 5, list.select(i));
}