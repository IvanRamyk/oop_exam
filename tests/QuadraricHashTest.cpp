//
// Created by hryhorchuk117 on 10/06/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Hash/QuadraticHash.h"

TEST(Hash, Quadratic) {
    QuadraticHash<date_time::Time> table({date_time::Time(1, 1, 1),date_time::Time(1, 1, 5) });
    auto n = table.getData();
    EXPECT_TRUE(table.getData() == n);
}

TEST(Hash, Quadratic2) {
    QuadraticHash<date_time::Time> table({date_time::Time(2, 1, 5),
                                          date_time::Time(1, 1, 5) });
    auto n = table.getData();
    EXPECT_TRUE(table.getData() == n);
}