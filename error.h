#include <iostream>

class Error {
public:
    static void overflowError() { 
        throw std::overflow_error("Overflow Detected! Program Terminated.");
    }

    static void underflowError() {
        throw std::underflow_error("Underflow Detected! Program Terminated.");
    }
};
