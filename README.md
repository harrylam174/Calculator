# Calculator

## Description
A simple calculator with the following features:

-  Basic arithmetic (+, -, x, /)
-  Advanced functions (^, log, !)
-  Trigonometric functions (sin, cos, tan, etc.) (of course, without using built-in functions!)
-  Root finding functions (linear, quadratic)
-  and more...

Except for basic arithmetics, all other functions will be implemented not via built-in C++ functions, but rather using a variation of Taylor Series and Newton's Method to approximate solutions up to 3 decimals. Basic arithmetics will also have mechanism for checking overflow and invalid operation (divide by 0). There might also be GUI and user-friendly feature like saving result for future calculation (to be updated!)

## Table Of Contents
-  [Description](#description)
-  [Contributor](#contributor)
-  [Motivation](#motivation)
-  [Installation](#installation)
-  [Usage & Requirements](#usage--requirements)
-  [Include Test](#include-test)


## Contributor
-  Harry Lam

## Motivation

This is my first official project using C++ (outside of my class), so I want to start with something small like creating a simple calculator. The reason that I use C++ is that it is the language that I am most proficient at, and given that I have done a variety of C++ programming and project in class, this is the language I am most comfortable with. I also want to practice using Git and GitHub in case I will get a job interview of related field one day. Hope to update weekly!

## Installation

You can simply Git clone this project into your local repository and use it.

## Usage & Requirements

-  Compiler: clang++ (c++)
-  Flags: -std=c++17 -Wall

To create a program that use the calculator without testing, use `MakefileTemplate.txt` as a template on how to create a Makefile, and use `main.cpp` (**NOT** `test.cpp`) as the executable. The header file, `calculator.h`, will store all (currently) available functions in calculator that you can use to perform math. Feel free to modify main to use these functionalities!
After cloning, creating a Makefile and make all necessary modification, you can use `make` and then `./result` to output the result of the operation(s).

## Include Test

For this project, I will use [Google Testing and Mocking Framework](https://github.com/google/googletest) for unit testing purposes. For more information on how to git clone and install googletest for testing, visit the provided link.

Assuming that you now have googletest that is in the same directory as this project, and have installed cmake in your computer (if not, visit [Download Cmake](https://cmake.org/download/) for directions on downloading CMake, or if you have installed [Brew](https://brew.sh/), you can use `brew install cmake` to install cmake into your computer), then you can perform testing by doing the following:

-  Make sure `CMakeLists.txt` exist in the current directory. This will be used to create `Makefile` later on.
-  Now, create a new directory (`mkdir`) of any name of your choosing, and move to that directory (`cd`)
-  Use `cmake ..` to begin creating a testing Makefile for the project
-  After cmake completed, you will notice that there is now a `Makefile` and other couple of new files in the directory. Use `make` to compile the program
-  For this CMakeLists.txt specifically, the executable name (which can be found in CMakeLists.txt under the name add_executable as the first string) will be `testResult`. Hence, the Makefile will create an executable named `testResult`, which you can compile using `./testResult` to output test result.

As of right now, the tests include:

-  Addition
-  Subtraction
