// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Cart_Vector class (defined in Cart_Vector.cpp)

#ifndef CART_VECTOR_H
#define CART_VECTOR_H

#include <iostream> // ostream

using namespace std;

class Cart_Vector
{
	public:
		Cart_Vector();
		Cart_Vector(double,double);
		double x;
		double y;
};

// Overloading operators (nonmember)
ostream & operator << (ostream&os, Cart_Vector);

Cart_Vector operator* (Cart_Vector, double);

Cart_Vector operator/ (Cart_Vector, double);

#endif
