//
// Created by hryhorchuk117 on 10/06/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Hash/CuckooHash.h"

TEST(Hash, Cuckoo) {
    CuckooHash<date_time::Time> table({date_time::Time(1, 1, 1),date_time::Time(1, 1, 5) });
    auto n = table.getData();
    table.search(date_time::Time(1,1,1));
    EXPECT_TRUE(table.getData() == n);
    table.erase(date_time::Time(1,1,1));
}

TEST(Hash, Cuckoo2) {
    CuckooHash<date_time::Time> table({date_time::Time(2, 1, 5),
                                          date_time::Time(1, 1, 5) });
    auto n = table.getData();
    EXPECT_TRUE(table.getData() == n);
}

TEST(Hash, Cuckoo3){
    CuckooHash<date_time::Time> s;
    s.add(date_time::Time(1,1,1));
    EXPECT_TRUE(s.search(date_time::Time(1,1,1)) != s.getData().first.end());
    EXPECT_FALSE(s.search(date_time::Time(1,3,1)) != s.getData().first.end());
    s.erase(date_time::Time(1,1,1));
    //EXPECT_FALSE(s.count(date_time::Time(1,1,1)));
}