#include "calculator.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(CALCULATOR, ADD) {
    ASSERT_EQ(Calculator::add(2, 2), 4);
    ASSERT_EQ(Calculator::add(-2, 3), 1);
    ASSERT_EQ(Calculator::add(1, -5), -4);
}

TEST(CALCULATOR, SUBTRACT) {
    ASSERT_EQ(Calculator::subtract(2, 2), 0);
    ASSERT_EQ(Calculator::subtract(-2, 3), -5);
    ASSERT_EQ(Calculator::subtract(1, -5), 6);
}

int main(int argc, const char * argv[]) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


