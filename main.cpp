#include "calculator.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // Example use case
    double num1 = Calculator::add(2, 2);                // 2 + 2 = 4
    double num2 = Calculator::power(3, 2);              // 3^2 = 9
    double result = Calculator::factorial(num2 - num1); // (9 - 4)! = 120
    cout << result << endl;
}


