#include "calculator.h"
#include <cmath>
#include <iostream>
#include <limits>

// This calculator will have a maximum of 11 digits precisions
constexpr double MAX = 1000000000000.0;
constexpr double MIN = -1000000000000.0;

double ln(double x) {
    if (x <= 0) return NAN;
    int power = 0;

    while (x > 1.0) {
        x /= euler;
        power++;
    }
    while (x < .25) {
        x *= euler;
        power--;
    }
    
    x -= 1.0;
    double t = 0.0, s = 1.0, z = x;
    for (int k = 1; k <= TAYLOR_ITERATIONS; k++) {
        t += z * s / k;
        z *= x;
        s = -s;
    }
    
    // Combine the result with the power_adjust value and return
    return t + power;
}

double Calculator::root(double x, int n) {
    const int K = 10;
    double A[K] = {1};
    for (int k = 0; k < K - 1; k++)
        A[k + 1] = (1.0 / n) * ((n - 1) * A[k] + x / power(A[k], n - 1));
    return A[K-1];
}

double Calculator::add(double x, double y) {
    if (x > 0 && y > MAX - x) Error::overflowError();
    if (x < 0 && y < MIN - x) Error::underflowError();
    return x + y;
}

double Calculator::subtract(double x, double y) {
    if (x < 0 && y > MAX + x) Error::underflowError();
    if (x > 0 && y < MIN + x) Error::overflowError();
    return x - y;
}

double Calculator::multiply(double x, double y) {
    if (x == 0 || y == 0) return 0;
    if (x > 0) {
        if (y > 0 && y > MAX / x) Error::overflowError();
        if (y < 0 && y < MIN / x) Error::underflowError();
    }
    if (x < 0) {
        if (y < 0 && y < MIN / fabs(x)) Error::overflowError();
        if (y > 0 && y > MAX / fabs(x)) Error::underflowError();
    }
    return x * y;
}

double Calculator::divide(double x, double y) {
    if (y == 0) return NAN;
    if (y > 0 && y < 1) {
        if (x > 0 && x > MAX * y) Error::overflowError();
        if (x < 0 && x < MIN * y) Error::underflowError();
    }
    if (y < 0 && y > -1) {
        if (x > 0 && x > MIN * y) Error::underflowError();
        if (x < 0 && x < MAX * y) Error::overflowError();
    }
    return x / y;
}

void Calculator::getInfo() {
    cout << "Version: " << version << endl;
    cout << "Product Name: " << Calculator::name << endl;
    cout << "Company: " << Calculator::author << endl;
}

double Calculator::power(double x, double n) {
    if (n == 0) return 1;
    else if (x == 1) return 1;
    else if (n < 0) return 1 / power(x, -n);
    else if (n < 1) return root(x, 1/n);
    else if (fmod(n, 2) == 0) return power(x, n/2) * power(x, n/2);
    return x * power(x, n-1);
}

double Calculator::logarithm(double base, double x) {
    if (x <= 0 || base <= 0) return NAN;
    return ln(x) / ln(base);
}

double Calculator::factorial(int x) {
    if (x < 0) return NAN;
    return tgamma(x + 1);
}


double Calculator::sine(double x) {
    while (x < 0) {
        x += 2*PI;
    }
    while (x >= 2*PI) {
        x -= 2*PI;
    }
    if (x > PI) {
        return -sine(x - PI);
    }

    double sign = 1;
    double result = 0;

    for (int i = 0; i < TAYLOR_ITERATIONS; ++i) {
        result += sign * power(x, 2*i + 1)/factorial(2*i+1);
        sign = -sign;
    }

    return result;
}

double Calculator::cosine(double x) {
    while (x < 0) {
        x += 2*PI;
    }
    while (x >= 2*PI) {
        x -= 2*PI;
    }

    if (x > PI/2.00 && x <= PI) return -cosine(PI - x);
    else if (x > PI && x <= 3.00/2.00 * PI) return -cosine(x - PI);
    else if (x > 3.00/2.00 * PI) return cosine(2*PI - x);

    double sign = 1;
    double result = 0;

    for (int i = 0; i < TAYLOR_ITERATIONS; ++i) {
        result += sign * power(x, 2*i)/factorial(2*i);
        sign = -sign;
    }

    return result;
}

double Calculator::tan(double x) {
    if (cosine(x) == 0) return NAN;
    return sine(x) / cosine(x);
}

double Calculator::secant(double x) {
    double denom = sine(x);
    if (denom == 0) return NAN;
    return 1.0/denom;
}

double Calculator::cosecant(double x) {
    double denom = cosine(x);
    if (denom == 0) return NAN;
    return 1.0/denom;
}

double Calculator::cotangent(double x) {
    double denom = tan(x);
    if (denom == 0) return NAN;
    return 1.0/denom;
}

double Calculator::arcsin(double x) {
    if (x < -1 || x > 1) return NAN;
    const int K = 15;
    double A[K] = {1};
    
    for (int i = 0; i < K - 1; ++i) {
        A[i+1] = A[i] - (sin(A[i]) - x) / cos(A[i]);
    }

    if (fabs(A[K-1] - 0) < 0.0001) return 0;
    return A[K-1]*1000.0/1000.0;
}

double Calculator::arccos(double x) {
    if (x < -1 || x > 1) return NAN;
    const int K = 15;
    double A[K] = {1};
    
    for (int i = 0; i < K - 1; ++i) {
        A[i+1] = A[i] - (cos(A[i]) - x) / -sin(A[i]);
    }

    if (fabs(A[K-1] - 0) < 0.0001) return 0;
    return A[K-1]*1000.0/1000.0;
}

double Calculator::arctan(double x) {
    if (x == 1) return 1.00/4.00 * PI;
    else if (x == -1) return -1.00/4.00 * PI;
    else if (x == 0) return 0;
    else if (x > 1) return 1.00/2.00 * PI - arctan(1.00/x);
    else if (x < -1) return -1.00/2.00 * PI - arctan(1.00/x);

    double result = 0;
    int sign = 1;
    for (int i = 0; i < TAYLOR_ITERATIONS; ++i) {
        result += sign * power(x, 2*i+1)/(2*i+1);
        sign = -sign;
    }
    return result;
}

double Calculator::linearRoot(double a, double b) {
    return -b/a;
}

pair<double, double> Calculator::quadraticRoot(double a, double b, double c) {
    pair<double, double> result;
    if (power(b, 2) - 4*a*c < 0) {
        cout << "Imaginary Not Supported" << endl;
        result.first = 0.00;
        result.second = 0.00;
        return result;
    }

    double vertex = -b/(2*a);
    double determinant = power(power(b, 2) - 4*a*c, 0.5);
    result.first = vertex - determinant;
    result.second = vertex + determinant;
    return result;
}

