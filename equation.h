#include "precedence.h"
#include "calculator.h"

class Equation {
private:
    bool validateEquation(string eq);
    string convertEquation(string eq);

public:
    double evaluateEquation(string eq);
};

