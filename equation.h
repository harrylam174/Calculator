#include "precedence.h"
#include "calculator.h"

class Equation {
private:
    /** @validateequation: determine whether a string of mathematical equation in infix form is valid or not.
     * An equation is only valid if 
     * - there is no mismatch parentheses
     * - order of numbers and operators (unary/binary) is valid.
     * @param eq: A string of mathematical equation in infix form, with each number/operator/function separated by single space
     * @return true if eq is a valid infix equation, false otherwise
     * */
    bool validateEquation(string eq);

    /** @convertequation: convert a mathematical equation from infix form to postfix form
     * @param eq: A string of mathematical equation in infix form, with each number/operator/function separated by single space
     * @return: A string of same mathematical equation in postfix form, with each number/operator/function separated by space
     **/ 
    string convertEquation(string eq);

public:
    /** 
     * @evaluateequation: evaluate a mathematical equation in infix form. If the equation is not valid,
     * throw a logic error and exit program
     * @param eq: A string of mathematical equation in infix form, with each number/operator/function separated by single space
     * @return: A double representing the result of the equation.
    */
    double evaluateEquation(string eq);
};

