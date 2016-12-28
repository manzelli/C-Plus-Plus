// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 1: Functions, Header Files, File I/O

// This header file holds all function prototypes defined in funcLib.cpp.

#ifndef FUNCLIB_H
#define FUNCLIB_H

// Mathematical function prototypes:
// Besides findNyanCatValue, none of these functions will return anything. They will just print (cout).

void areaSq(double, double, double);

void circFun(double, double, double);

void sqRoots(double, double, double);

void oddNum(double, double, double);

void luckyNum(double, double, double);

void sinVal(double, double, double);

void cosVal(double, double, double);

void expFunc(double, double, double);

void logFunc(double, double, double);

double findNyanCatValue(double);

// Various other functions:

void initialize();

bool checkCode(char);

void writeDataToFile(const char *);

void readDataFromFile(const char *);

#endif