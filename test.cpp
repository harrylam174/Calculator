#include "calculator.h"
#include "precedence.h"
#include <cmath>
#include <iostream>
#include <gtest/gtest.h>

// Helper function to test for equality of trigonometric functions
// Here, we test for tolerance instead of pure equality
bool satisfyTolerance(double v1, double v2, double tolerance = 0.00001) {
    return abs(v1 - v2) < tolerance;
}

class TrigTest: public ::testing::TestWithParam <double> {};

TEST(CALCULATOR, ADDITION) {
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};
    vector<double> addExpect = {4,  1, -4,  2,  3.0,  100};
    for (int i = 0; i < x.size(); ++i) {
        ASSERT_EQ(Calculator::add(x[i], y[i]), addExpect[i]);
    }

    EXPECT_THROW(Calculator::add(2, 999999999999), std::overflow_error);
    EXPECT_THROW(Calculator::add(999999999980, 222), std::overflow_error);
}

TEST(CALCULATOR, SUBTRACTION) {
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};
    vector<double> subExpect = {0, -5,  6,  2, -2.0, -100};
    for (int i = 0; i < x.size(); ++i) {
        ASSERT_EQ(Calculator::subtract(x[i], y[i]), subExpect[i]);
    }

    EXPECT_THROW(Calculator::subtract(-2, 999999999999), std::underflow_error);
    EXPECT_THROW(Calculator::subtract(2, -999999999999), std::overflow_error);
}

TEST(CALCULATOR, MULTIPLICATION) {
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};
    vector<double> mulExpect = {4, -6, -5, 0, 1.25,  0};
    for (int i = 0; i < x.size(); ++i) {
        ASSERT_EQ(Calculator::multiply(x[i], y[i]), mulExpect[i]);
    }

    EXPECT_THROW(Calculator::multiply(-2, 999999999999), std::underflow_error);
    EXPECT_THROW(Calculator::multiply(2, -999999999999), std::underflow_error);
    EXPECT_THROW(Calculator::multiply(2, 999999999999), std::overflow_error);
    EXPECT_THROW(Calculator::multiply(-2, -999999999999), std::overflow_error);
    EXPECT_THROW(Calculator::multiply(100000000, 200000000), std::overflow_error);
}

TEST(CALCULATOR, DIVISION) {
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};
    vector<double> divExpect = {1, -2.0/3.0, -0.2, NAN, 0.2, 0};
    for (int i = 0; i < x.size(); ++i) {
        if (y[i] == 0) ASSERT_EQ(true, isnan(Calculator::divide(x[i], y[i])));
        else ASSERT_EQ(Calculator::divide(x[i], y[i]), divExpect[i]);
    }

    EXPECT_THROW(Calculator::divide(999999999995, 0.5), std::overflow_error);
    EXPECT_THROW(Calculator::divide(-500000000001, -0.5), std::overflow_error);
    EXPECT_THROW(Calculator::divide(500000000001, -0.5), std::underflow_error);
    EXPECT_THROW(Calculator::divide(-712345678922, 0.5), std::underflow_error);

}

TEST(CALCULATOR, ADVANCED) {
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};
    vector<double> z = {1, 2, 5, 6, 0.5, 10.75};
    vector<int> f = {0, 1, 2, 4, 5, 10};
    vector<int> fexpect = {1, 1, 2, 24, 120, 3628800};

    for (int i = 0; i < x.size(); ++i) {
        ASSERT_EQ(true, satisfyTolerance(Calculator::power(x[i], y[i]), pow(x[i], y[i])));
        ASSERT_EQ(true, satisfyTolerance(Calculator::logarithm(10, z[i]), log10(z[i])));
        ASSERT_EQ(true, satisfyTolerance(Calculator::factorial(f[i]), fexpect[i]));
    }
}

TEST_P(TrigTest, TRIG) {
    ASSERT_EQ(true, satisfyTolerance(Calculator::sine(GetParam()), sin(GetParam())));
    ASSERT_EQ(true, satisfyTolerance(Calculator::cosine(GetParam()), cos(GetParam())));
    if (Calculator::cosine(GetParam()) == 0) {
        ASSERT_EQ(true, isnan(Calculator::tan(GetParam())));
    }
    else {
        ASSERT_EQ(true, satisfyTolerance(Calculator::tan(GetParam()), tan(GetParam())));
    }
}

TEST(PRECEDENCE, SIMPLE) {
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("*", "+"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("*", "-"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("/", "+"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("/", "-"));
    ASSERT_EQ(false, Precedence::isGreaterPrecedence("+", "-"));
    ASSERT_EQ(false, Precedence::isGreaterPrecedence("*", "/"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("^", "*"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("sin", "*"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("cos", "/"));
    ASSERT_EQ(true, Precedence::isGreaterPrecedence("tan", "("));
    ASSERT_EQ(false, Precedence::isGreaterPrecedence("^", ")"));
}

INSTANTIATE_TEST_SUITE_P(MyTrigTest, TrigTest, testing::Range(0.0, 2.20*PI, 0.20*PI));