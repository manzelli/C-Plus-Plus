// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Cart_Vector class defines the Cartesian vectors in the game, used for movement on the game board.

#include <iostream> // ostream
#include "Cart_Vector.h"

using namespace std;

	// Members
	// Default constructor sets x and y to 0.0
	Cart_Vector::Cart_Vector()
	{
		x = 0.0;
		y = 0.0;
	}
	
	// Sets cartesian points to the input coordinate
	Cart_Vector::Cart_Vector(double inputx, double inputy)
	{	
		x = inputx;
		y = inputy;
	}

	// Nonmember overloaded operators
	// Stream operator <<
	ostream& operator << (ostream& os, Cart_Vector v1)
	{
		os << "<" << v1.x << ", " << v1.y << ">";
		return os;
	}

	// Multiplication operator *
	Cart_Vector operator* (Cart_Vector v1, double d)
	{
		return Cart_Vector(v1.x*d, v1.y*d);
	}
	
	// Division operator /
	Cart_Vector operator/ (Cart_Vector v1, double d)
	{
		return Cart_Vector(v1.x/d, v1.y/d);
	}
