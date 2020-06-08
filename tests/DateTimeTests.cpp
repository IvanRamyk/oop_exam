//
// Created by ivan on 08.06.20.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../src/Date/Date.hpp"

TEST(DateTime, Date) {
    date_time::Date date1(2012, date_time::Feb, 23);
    EXPECT_TRUE(date1.to_string() == std::string("2012-Feb-23"));
}

TEST(DateTime, Time) {
    date_time::Time time1(0, 12, 2);
    EXPECT_TRUE(time1.to_string() == std::string("00:12:02"));
}
