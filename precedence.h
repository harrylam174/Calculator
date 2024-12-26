/**
 * @file: precedence.h
 * @class: Precedence
 * @brief: Contain functions that evaluate mathematical operators/functions
 * @copyright: Copyright 2024, Harry Lam. All Rights Reserved.
 */

#include <string>
using namespace std;

/** 
 * @enum operatorRank
 * @details: Contain the rank of precedence of each operator/function as integers, 
 * with function has highest precedence of 5 and addition/subtraction has lowest precedence of 1
 **/
enum class operatorRank {
    FUNCTION = 5,
    BRACKET = 4,
    EXPONENTIAL = 3,
    DIVISION = 2, MULTIPLICATION = 2,
    ADDITION = 1, SUBTRACTION = 1
};

class Precedence {
private:
    /** @identifyoperator: convert a string that contain operator/function to an object of operatorRank
     * @param op: A string represent an operator/function
     * @return: An operatorRank object that correspond to the operator/function
     **/
    static operatorRank identifyOperator(string op);

public:
    /** @isgreaterprecedence: evaluate whether an operator has greater precedence compare to other
     * @param op1: A string represent the first operator/function
     * @param op2: A string represent the second operator/function
     * @return: true if op1 has greater precedence than op2, false otherwise
     **/
    static bool isGreaterPrecedence(string op1, string op2);
};



