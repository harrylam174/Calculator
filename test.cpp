#include "calculator.h"
#include "precedence.h"
#include <iostream>
#include <gtest/gtest.h>

// Helper function to test for equality of trigonometric functions
// Here, we test for tolerance instead of pure equality
bool satisfyTolerance(double v1, double v2, double tolerance) {
    return abs(v1 - v2) < tolerance;
}

class TrigTest: public ::testing::TestWithParam <double> {};


TEST(CALCULATOR, BASIC) {
    // Input
    vector<double> x = {2, -2, 1, 2, 0.5, 0};
    vector<double> y = {2, 3, -5, 0, 2.5, 100};

    // Expected
    vector<double> addExpect = {4,  1, -4,  2,  3.0,  100};
    vector<double> subExpect = {0, -5,  6,  2, -2.0, -100};
    vector<double> mulExpect = {4, -6, -5,   0, 1.25,  0};
    vector<double> divExpect = {1, -2.0/3.0, -0.2, NAN, 0.2, 0};

    // Testing
    for (int i = 0; i < x.size(); ++i) {
        ASSERT_EQ(Calculator::add(x[i], y[i]), addExpect[i]);
        ASSERT_EQ(Calculator::subtract(x[i], y[i]), subExpect[i]);
        ASSERT_EQ(Calculator::multiply(x[i], y[i]), mulExpect[i]);

        // Special case for division if denominator is 0
        if (y[i] == 0) {
            ASSERT_EQ(true, isnan(Calculator::divide(x[i], y[i])));
        }
        else {
            ASSERT_EQ(Calculator::divide(x[i], y[i]), divExpect[i]);
        }
    }
}

TEST_P(TrigTest, TRIG) {
    ASSERT_EQ(true, satisfyTolerance(Calculator::sine(GetParam()), sin(GetParam()), 0.00001));
    ASSERT_EQ(true, satisfyTolerance(Calculator::cosine(GetParam()), cos(GetParam()), 0.00001));
    if (Calculator::cosine(GetParam()) == 0) {
        ASSERT_EQ(true, isnan(Calculator::tan(GetParam())));
    }
    else {
        ASSERT_EQ(true, satisfyTolerance(Calculator::tan(GetParam()), tan(GetParam()), 0.00001));
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