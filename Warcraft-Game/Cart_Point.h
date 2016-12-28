// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Cart_Point class (defined in Cart_Point.cpp)

#ifndef CART_POINT_H
#define CART_POINT_H

#include <iostream> // ostream
#include <cmath> // pow, sqrt
#include "Cart_Vector.h"

using namespace std;

class Cart_Point
{
	public:
		Cart_Point();
		Cart_Point(double,double);
		double x;
		double y;
};

// Nonmember functions
double cart_distance(Cart_Point, Cart_Point);

// Overloading operators (nonmember)
ostream& operator << (ostream&, Cart_Point);

Cart_Point operator+ (Cart_Point, Cart_Vector);

Cart_Vector operator- (Cart_Point, Cart_Point);

#endif
