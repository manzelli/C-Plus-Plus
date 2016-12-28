// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Gold_Mine class (defined in Gold_Mine.cpp)

#ifndef GOLD_MINE_H
#define GOLD_MINE_H

#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Gold_Mine : public Game_Object
{
public:
	// Constructors
	Gold_Mine();
	Gold_Mine(int, Cart_Point);
	~Gold_Mine();

	// Public member functions
	bool is_empty();
	double dig_gold(double amount_to_dig = 35.0);
	void show_status();
	bool update();

	/* Inherited:
		Cart_Point get_location();
		int get_id();
	*/

private:
	double amount;

	/* Inherited: 
		char display_code;
		int id_num;
		char state;
		Cart_Point location;
	*/

};

#endif