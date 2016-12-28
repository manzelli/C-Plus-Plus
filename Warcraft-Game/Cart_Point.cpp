// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Cart_Point class defines the Cartesian points on the game board. 
// This includes overloaded operators to operate on sets of points.

#include "Cart_Point.h"

using namespace std;

	// Members
	// Default constructor sets x and y to 0.0
	Cart_Point::Cart_Point()
	{
		x = 0.0;
		y = 0.0;
	}
	
	// Sets cartesian points to the input coordinate
	Cart_Point::Cart_Point(double inputx, double inputy)
	{	
		x = inputx;
		y = inputy;
	}

	// Nonmember functions
	double cart_distance(Cart_Point p1, Cart_Point p2)
	{
		return sqrt((pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2)));
	}

	// Nonmember overloaded operators
	// Stream operator <<
	ostream& operator << (ostream& os, Cart_Point p1)
	{
		os << "(" << p1.x << "," << p1.y << ")";
		return os;
	}
	
	// Plus operator +
	Cart_Point operator+ (Cart_Point p1, Cart_Vector v1)
	{
		return Cart_Point(p1.x+v1.x, p1.y+v1.y);
	}

	// Plus operator -
	Cart_Vector operator- (Cart_Point p1, Cart_Point p2)
	{
		return Cart_Vector(p1.x-p2.x, p1.y-p2.y);
	}
