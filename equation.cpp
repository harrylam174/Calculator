#include "equation.h"
#include <sstream>

bool isNumber(string word) {
    bool dot = false;
    for (int i = 0; i < word.size(); ++i) {
        if (i == 0 && word[i] == '-') continue;
        if (word[i] == '.' && (dot == true || i == 0)) return false;
        if (word[i] == '.') {
            dot = true;
            continue;
        }
        if (word[i] < '1' || word[i] > '9') return false;
    }
    return true;
}

bool isFunction(string word) {
    return (word == "sin" || word == "cos" || word == "tan" ||
            word == "sec" || word == "csc" || word == "cot" ||
            word == "arcsin" || word == "arccos" || word == "arctan" ||
            word == "log" || word == "!");
}

bool isOperator(string word) {
    return (word == "+" || word == "-" || word == "*" || word == "/" ||
            word == "^");
}

bool isLeftParenthesis(string word) {
    return (word == "(" || word == "[" || word == "{");
}

bool isRightParenthesis(string word) {
    return (word == ")" || word == "]" || word == "}");
}

bool Equation::validateEquation(string eq) {
    // Check for parentheses validation
    stack<char> left;
    for (int i = 0; i < eq.size(); ++i) {
        if (eq[i] == '(' || eq[i] == '[' || eq[i] == '{') left.push(eq[i]);
        else if (eq[i] == ')' || eq[i] == ']' || eq[i] == '}') {
            if (left.empty()) return false;
            if (eq[i] == ')' && left.top() != '(') return false;
            if (eq[i] == ']' && left.top() != '[') return false;
            if (eq[i] == '}' && left.top() != '{') return false;
            left.pop();
        }
    }
    return left.empty();
}

string Equation::convertEquation(string eq) {
    if (!validateEquation(eq)) throw std::logic_error("Invalid Equation. Program Terminated.");
    stringstream ss(eq);
    std::vector<std::string> words{
        std::istream_iterator<std::string>(ss),
        std::istream_iterator<std::string>()
    };
    
    string output;
    queue<string> output_q;
    stack<string> op;

    for (auto const& str : words) {
        if (isNumber(str)) output_q.push(str);
        else if (isFunction(str) || isLeftParenthesis(str)) op.push(str);
        else if (isOperator(str)) {
            while (!isLeftParenthesis(op.top()) && Precedence::isGreaterPrecedence(str, op.top())) {
                output_q.push(op.top());
                op.pop();
            }
            op.push(str);
        }
        else if (isRightParenthesis(str)) {
            while (!isLeftParenthesis(op.top())) {
                output_q.push(op.top());
                op.pop();
            }
            op.pop();
            if (isFunction(op.top())) {
                output_q.push(op.top());
                op.pop();
            }
        }
    }

    while (!op.empty()) {
        output_q.push(op.top());
        op.pop();
    }

    if (!output_q.empty()) {
        output = output_q.front();
        output_q.pop();
    }

    while (!output_q.empty()) {
        output += " ";
        output += output_q.front();
        output_q.pop();
    }

    return output;
}