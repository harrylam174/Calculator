#include "test.cpp"
#include <iostream>

int unitTest() {
    testing::internal::CaptureStdout();
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

int main(int argc, const char * argv[]) {
    int testResult = unitTest();
    string error = testing::internal::GetCapturedStdout();
    if (testResult != 0) {
        cout << error << endl;
        return 1;
    }
    cout << Calculator::add(1, 1) << endl;
}


