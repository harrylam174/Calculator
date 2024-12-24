#define euler 2.718281828459045235
#define TAYLOR_ITERATIONS 50
#define PI 3.1415926535897

#include <string>
#include "error.h"
using namespace std;

class Calculator {
    private:
        static const int version = 1;
        inline static const string name = "My Calculator";
        inline static const string author = "Harry Lam";
    
    private:
        bool save = false;
        static double root(double x, int n);

    public:
        // Calculator Info
        static void getInfo();

        // Common Functions (+, -, x, /)
        static double add(double x, double y);
        static double subtract(double x, double y);
        static double multiply(double x, double y);
        static double divide(double x, double y);

        // Advanced Functions (^, log, !)
        static double power(double x, double n);
        static double logarithm(double base, double x);
        static double factorial(int x);

        // Trigonometric Functions (sin, cos, tan)
        static double sine(double x);
        static double cosine(double x);
        static double tan(double x);

        // Reciprocal Trigonometric Functions (sec, csc, cot)
        static double secant(double x);
        static double cosecant(double x);
        static double cotangent(double x);

        // Inverse Trigonometric Functions (arcsin, arccos, arctan)
        static double arcsin(double x);
        static double arccos(double x);
        static double arctan(double x);

        // Finding Roots
        static double linearRoot(double a, double b);
        static pair<double, double> quadraticRoot(double a, double b, double c);
};

