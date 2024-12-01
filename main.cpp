#include "calculator.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    double num1 = Calculator::add(2, 2);
    double num2 = Calculator::power(3, 2);
    double result = Calculator::factorial(num2 - num1);
    cout << result << endl;
}


