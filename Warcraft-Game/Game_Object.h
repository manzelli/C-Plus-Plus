// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Game_Object class (defined in Game_Object.cpp)

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

class Game_Object {
public:
	// Constructors
	Game_Object();
	Game_Object(char, int);
	Game_Object(char, int, Cart_Point);
	virtual ~Game_Object();

	// Member functions
	Cart_Point get_location();
	int get_id();
	virtual bool update() = 0; // pure virtual
	virtual void show_status();
	void drawself(char*);
	virtual bool is_alive();

protected:
	Cart_Point location;
	char display_code;
	char state;

private:
	int id_num;
};

#endif
