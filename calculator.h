/**
 * @class: Calculator calculator.h
 * @brief: A class that contain all the calculator's information and valid operations
 * @copyright: Copyright 2024 Harry Lam. All Rights Reserved.
 **/

#define euler 2.718281828459045235
#define TAYLOR_ITERATIONS 50
#define PI 3.1415926535897

#include <string>
#include "error.h"
using namespace std;

class Calculator {
    private:
        /** @brief: A list of calculator's information */ 
        static const int version = 1;                       /** Calculator Version */
        inline static const string name = "My Calculator";  /** Calculator Name */
        inline static const string author = "Harry Lam";    /** Calculator Author */
    
    private:
        /** @root: return the root of a number of a given base
         * @param x: a double representing the value to take the root
         * @param n: a double representing the base
         * @return: the root of x of base n
         */
        static double root(double x, int n);

    public:
        /** @getinfo: get the calculator's version, name and author
         * @return: a three line output listing version, name and author
         **/
        static void getInfo();

        /// COMMON FUNCTIONS ///////////////////////////////////////////////////////////////////////////
        /** @add: add two numbers together. If result is larger than 13 digits, throw overflow/underflow
         * @param x: first double to add
         * @param y: second double to add
         * @return: a double that represent the sum of both parameters 
         **/
        static double add(double x, double y);

        /** @subtract: subtract two numbers. If result is larger than 13 digits, throw overflow/underflow
         * @param x: first double to subtract
         * @param y: second double to subtract
         * @return: a double that represent the difference of both parameters 
         **/
        static double subtract(double x, double y);

        /** @multiply: multiply two numbers. If result is larger than 13 digits, throw overflow/underflow
         * @param x: first double to multiply
         * @param y: second double to multiply
         * @return: a double that represent the product of both parameters 
         **/
        static double multiply(double x, double y);

        /** @divide: divide two numbers. If result is larger than 13 digits, throw overflow/underflow
         * @param x: first double to divide
         * @param y: second double to divide
         * @return: a double that represent the quotient of both parameters 
         **/
        static double divide(double x, double y);

        /// ADVANCED FUNCTIONS ////////////////////////////////////////////////////////////////////////

        /** @power: return x to the power of n.
         * @param x: a double represent the base
         * @param n: a double represent the exponent
         * @return: a double represent x^n
         **/
        static double power(double x, double n);

        /** @logarithm: return the logarithm of a number of a given base
         * @param base: a double represent the base
         * @param x: a double represent the number to take logarithm
         * @return: logarithm of x of base 'base'
         **/
        static double logarithm(double base, double x);

        /** @factorial: return the factorial of a number
         * @param x: an integer
         * @return: a double representing x!
         **/
        static double factorial(int x);

        /// TRIGONOMETRIC FUNCTIONS //////////////////////////////////////////////////////////

        /** @sine: return the sine of a value
         * @param x: a double
         * @return: a double representing sin(x)
         **/
        static double sine(double x);

        /** @cosine: return the cosine of a value
         * @param x: a double
         * @return: a double representing cos(x)
         **/
        static double cosine(double x);

        /** @tan: return the tangent of a value
         * @param x: a double
         * @return: a double representing tan(x)
         **/
        static double tan(double x);

        /** @secant: return the secant of a value
         * @param x: a double
         * @return: a double representing sec(x)
         **/
        static double secant(double x);

        /** @cosecant: return the cosecant of a value
         * @param x: a double
         * @return: a double representing csc(x)
         **/
        static double cosecant(double x);

        /** @cotangent: return the cotangent of a value
         * @param x: a double
         * @return: a double representing cot(x)
         **/
        static double cotangent(double x);

        /** @arcsin: return the inverse of sin of a value
         * @param x: a double
         * @return: a double representing arcsin(x)
         **/
        static double arcsin(double x);

        /** @arccos: return the inverse of sin of a value
         * @param x: a double
         * @return: a double representing arccos(x)
         **/
        static double arccos(double x);

        /** @arctan: return the inverse of tan of a value
         * @param x: a double
         * @return: a double representing arctan(x)
         **/
        static double arctan(double x);

        /// ROOT FINDING FUNCTIONS /////////////////////////////////////////////////
        /** @linearroot: return the x-intercept of the line y = ax + b;
         * @param a: a double representing the slope of a curve
         * @param b: a double representing y-intercept
         * @return: a double representing the x-intercept
         **/
        static double linearRoot(double a, double b);

        /** @quadraticroot: return the x-intercepts of the quadratic curve y = ax^2 + bx + c;
         * @param a: a double represent the coefficient of x^2
         * @param b: a double represent the coefficient of x
         * @param c: a double represent the constant
         * @return: a pair of double representing the two real roots of the quadratic curves
         **/
        static pair<double, double> quadraticRoot(double a, double b, double c);
};

