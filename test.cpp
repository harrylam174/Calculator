/**
 * @file: test.cpp
 * @brief: A file containing the unit tests for the file calculator.h (Calculator class)
 * @copyright: Copyright 2024, Harry Lam. All Rights Reserved
 * 
 * The unit test framework is provided by Google Testing and Mocking Framework
 * @link: https://github.com/google/googletest
 * @copyright: 
 * 
 * Copyright 2008, Google Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * *    Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 *
 * *    Redistributions in binary form must reproduce the above 
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 * 
 * *    Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
*/

#include "calculator.h"
#include "precedence.h"
#include <cmath>
#include <iostream>
#include <gtest/gtest.h>

/** 
 * @satisfytolerance: return true if two numbers are nearly close enough, false otherwise
 * @param v1: a double represent the first value
 * @param v2: a double represent the second value
 * @return: true if the absolute difference between v1 and v2 is no more than tolerance, false otherwise
*/
bool satisfyTolerance(double v1, double v2, double tolerance = 0.00000000001) {
    return abs(v1 - v2) < tolerance;
}


/** 
 * @test: ADDITION
 * @brief: A unit test for the calculator's add function (including normal & overflow/underflow)
 */
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

/** 
 * @test: SUBTRACTION
 * @brief: A unit test for the calculator's subtract function (including normal & overflow/underflow)
 */
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

/** 
 * @test: MULTIPLICATION
 * @brief: A unit test for the calculator's multiply function (including normal & overflow/underflow)
 */
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

/** 
 * @test: DIVISION
 * @brief: A unit test for the calculator's divide function (including normal & overflow/underflow)
 */
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

/** 
 * @test: ADVANCED
 * @brief: A unit test for the calculator's advanced functions (power, logarithm, factorial)
 */
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


// DUMMY CLASS FOR TESTING
class TrigTest: public ::testing::TestWithParam <double> {};

/**
 * @test: TRIG
 * @brief: A unit test for the calculator's basic trigonometric functions (sine, cosine, tan)
 */
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

INSTANTIATE_TEST_SUITE_P(MyTrigTest, TrigTest, testing::Range(0.0, 2.20*PI, 0.20*PI));

/**
 * @test: SIMPLE PRECEDENCE
 * @brief: A unit test for order of precedence
 **/
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

