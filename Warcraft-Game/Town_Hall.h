// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Town_Hall class (defined in Town_Hall.cpp)

#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Gold_Mine.h"

using namespace std;

class Town_Hall : public Game_Object
{
public:
	// Constructors
	Town_Hall();
	Town_Hall(int, Cart_Point);
	~Town_Hall();

	// Public member functions
	void deposit_gold(double);
	bool update();
	void show_status();

	/* Also inherited:
		int get_id();
		Cart_Point get_location();
	*/

private:
	double amount;

	/* Also inherited:
		char display_code;
		int id_num;
		char state;
		Cart_Point location;
	*/
};

#endif