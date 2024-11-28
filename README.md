# Calculator

## Table Of Contents
-  [Contributor](#contributor)
-  [Motivation](#motivation)
-  [Description](#description)
-  [Installation](#installation)
-  [Usage & Requirements](#usage-requirements)
-  [Include Test](#include-test)


## Contributor
-  Harry Lam

## Motivation

This is my first official project using C++ (outside of my class), so I want to start with something small like creating a simple calculator. The reason that I use C++ is that it is the language that I am most proficient at, and given that I have done a variety of C++ programming and project in class, this is the language I am most comfortable with. I also want to practice using Git and GitHub in case I will get a job interview of related field one day. Hope to update weekly!

## Description
A simple calculator with the following features:

-  Basic arithmetic (+, -, x, /)
-  Advanced functions (^, log, !)
-  Trigonometric functions (sin, cos, tan, etc.) (of course, without using built-in functions!)
-  Root finding functions (linear, quadratic)
-  and more...

Except for basic arithmetics, all other functions will be implemented not via built-in C++ functions, but rather using a variation of Taylor Series and Newton's Method to approximate solutions up to 3 decimals. Basic arithmetics will also have mechanism for checking overflow and invalid operation (divide by 0). There might also be GUI and user-friendly feature like saving result for future calculation (to be updated!)

## Installation

You can simply Git clone this project into your local repository and use it.

## Usage & Requirements

The Makefile currently utilizes clang++ (c++) and C++17 for compilation, so make sure to either have VS Code set up for them or install necessary compile machine to compile this project (although you can update the Makefile to use the compiler/version as your choosing). 

The header file, `calculator.h`, will store all (currently) available functions in calculator that you can use to perform math. Feel free to modify main to use/test these functionalities!
After you finish cloning and make all necessary modification, you can use `make` and then `./result` to output the result of the operation(s).

## Include Test

I am currently trying to use GoogleTest (Google Testing and Mocking Framework) for testing purposes, but as of right now, there are still things that I am attempting to figure it out in using the tests, so stay tune for more updates!




