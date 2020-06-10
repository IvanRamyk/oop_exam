//
// Created by ivan on 08.06.20.
//

#include <gtest/gtest.h>
#include "../src/containers/Map/Map.hpp"


TEST(Map, MapSplayTree){
    Map <int, int, SplayTree> map;
    map.insert(3, 4);
    EXPECT_EQ(map.getValue(3), 4);
    map.insert(3, 10);

}

/*
TEST(Map, MapList){
    Map <int, int, SingleLinkedOrderedList> map;
    map.insert(3, 4);
    EXPECT_EQ(map.getValue(3), 4);
    map.insert(3, 10);

}

TEST(Map, MapListValues){
    Map <int, int, SingleLinkedOrderedList> map;
    map.insert(3, 4);
    EXPECT_EQ(map.getValue(3), 4);
    map.insert(3, 10);
    auto pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 1);
    EXPECT_EQ(pairs[0].first, 3);
    EXPECT_EQ(pairs[0].second, 10);
    map.insert(3, 11);
    pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 1);
    EXPECT_EQ(pairs[0].first, 3);
    EXPECT_EQ(pairs[0].second, 11);
    map.insert(2, 20);
    pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 2);
}*/

TEST(Map, MapTreeValues){
    Map <int, int, SplayTree> map;
    map.insert(3, 4);
    EXPECT_EQ(map.getValue(3), 4);
    map.insert(3, 10);
    auto pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 1);
    EXPECT_EQ(pairs[0].first, 3);
    EXPECT_EQ(pairs[0].second, 10);
    map.insert(3, 11);
    pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 1);
    EXPECT_EQ(pairs[0].first, 3);
    EXPECT_EQ(pairs[0].second, 11);
    map.insert(2, 20);
    pairs = map.pairs();
    EXPECT_EQ(pairs.size(), 2);
}