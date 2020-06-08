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

TEST(Map, MapListTree){
    Map <int, int, SingleLinkedOrderedList> map;
    map.insert(3, 4);
    EXPECT_EQ(map.getValue(3), 4);
    map.insert(3, 10);

}