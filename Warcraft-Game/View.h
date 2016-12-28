// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the View class (defined in View.cpp)

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

// Declaration of maximum View size
const int view_maxsize = 20;

class View
{
public:
	View();
	void clear();
	void plot(Game_Object*);
	void draw();
private:
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];
	bool get_subscripts(int&, int&, Cart_Point);
};

#endif