// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Game_Object class defines properties of Game_Objects, which are any of the objects in the game.

#include "Game_Object.h"

using namespace std;

	// Constructors
	Game_Object::Game_Object()
	{
		display_code = ' ';
		id_num = 0;
		location = Cart_Point();
		state = 's';
	}

	Game_Object::Game_Object(char in_code, int in_id)
	{
		// Initialize everything
		// display_code is how an object is represented in the View
		display_code = in_code;
		id_num = in_id;
		location = Cart_Point();
		state = 's';
		cout << "Game_Object default constructed." << endl;
	}

	Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
	{
		display_code = in_code;
		id_num = in_id;
		location = in_loc;
		state = 's';
		cout << "Game_Object constructed." << endl;
	}

	// Destructor
	Game_Object::~Game_Object()
	{
		cout << "Game_Object destructed." << endl;
	}

	// Public member functions
	// Getters (get private variables)
	Cart_Point Game_Object::get_location()
	{
		return location;
	}

	int Game_Object::get_id()
	{
		return id_num;
	}

	void Game_Object::show_status()
	{
		// Shows status of Game_Object
		cout << display_code << id_num << " at " << location << " ";
	}

	void Game_Object::drawself(char* ptr)
	{
		// Creating the representation of the object that is printed on the board
		// Pointer array with first element display_code and second element id_num, to be printed together

		ptr[0] = display_code; // *ptr stores display_code

		// convert integer id_num to ASCII character equivalent by adding '0' (represents 48 in ASCII)
		char char_id = (char)(id_num + (int)'0');

		// Assign character id_num to the second element in the pointer array
		ptr[1] = char_id; // (*ptr + 1) stores the character ID now
	}

	bool Game_Object::is_alive()
	{
		return true;
	}