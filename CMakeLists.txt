cmake_minimum_required(VERSION 3.12) # version can be different
set(GOOGLETEST_VERSION 1.15.2)
project(Calculator) #name of your project
enable_testing() #to  discover tests in test explorer 
add_subdirectory(googletest) # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(testResult main.cpp calculator.cpp) # add this executable
target_link_libraries(testResult PRIVATE gtest) # link google test to this executable
include(GoogleTest)
gtest_discover_tests(testResult) # discovers tests by asking the compiled test executable to enumerate its tests