#include "precedence.h"

operatorRank Precedence::identifyOperator(string op) {
    if (op == "+") return operatorRank::ADDITION;
    if (op == "-") return operatorRank::SUBTRACTION;
    if (op == "*") return operatorRank::MULTIPLICATION;
    if (op == "/") return operatorRank::DIVISION;
    if (op == "^") return operatorRank::EXPONENTIAL;
    if (op == "(" || op == ")") return operatorRank::BRACKET;
    return operatorRank::FUNCTION;
}

bool Precedence::isGreaterPrecedence(string op1, string op2) {
    return identifyOperator(op1) > identifyOperator(op2);
}
