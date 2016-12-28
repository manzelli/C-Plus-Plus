// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Person class defines the characters in the game, who have health and speed. 
// They can move around the game board while alive. People are derived from the Game_Object class.

#include "Person.h"

using namespace std;

// Constructors
Person::Person(): Game_Object()
{
	health = 5;
	speed = 5;

	/* Initialized:
		display_code = '';
		id_num = 0;
		location = Cart_Point();
		state = 's';
	*/
}

Person::Person(char in_code): Game_Object(in_code, 0)
{
	health = 5;
	speed = 5;
	cout << "Person default constructed." << endl;

	/* Also initialized:
		display_code = in_code;
		id_num = 0;
		location = Cart_Point();
		state = 's';
	*/
}

Person::Person(char in_code, int in_id, Cart_Point in_loc): Game_Object(in_code, in_id, in_loc)
{
	health = 5;
	speed = 5;
	cout << "Person constructed." << endl;

	/* Also initialized:
		display_code = in_code;
		id_num = in_id;
		location = in_loc;
		state = 's';
	*/
}

// Destructor
Person::~Person()
{
	cout << "Person destructed." << endl;
}

// Public member functions
void Person::start_moving(Cart_Point dest)
{
	// Tells the person to start moving
	if (state != 'x')
	{
		cout << "Moving " << get_id() << " to " << dest << endl;

		if (location.x == dest.x && location.y == dest.y)
		{
			// If the Miner is already at the location it should not be set to move:
			cout << "M" << get_id() << ": I'm already there. see?" << endl;
		}
		else
		{
			// Set up destination and set state to moving
			setup_destination(dest);
			state = 'm';
			cout << display_code << get_id() << ": On my way." << endl;
		}
	}
	else
	{
		cout << "This Person is dead!" << endl;
		// Ignore command
	}
}

void Person::stop()
{
	// Tells the miner to stop moving/mining
	state = 's';
	delta = Cart_Vector(); // no delta - cannot step
	cout << display_code << get_id() << ": Stopped." << endl;
}

void Person::show_status()
{
	if (is_alive())
	{
		Game_Object::show_status();

		if (state == 's' || state == 'a' || state == 'x')
		{
			// print nothing here
		}
		else
		{
			cout << "moving at speed of " << speed << " towards " << destination << " at each step of " << delta << " ";
			cout << "with health " << health << endl;
		}
	}
	else
	{
		cout << "This Person is dead!" << endl;
	}
}

bool Person::is_alive()
{
	if (state == 'x')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Person::take_hit(int attack_strength)
{
	health -= attack_strength;
	if (health <= 0)
	{
		state = 'x';
		cout << "Arrggh!" << endl;
	}
	else
	{
		cout << "Ouch!" << endl;
	}
}

void Person::start_attack(Person* target)
{
	cout << "I can't attack." << endl;
}

// Protected member functions
bool Person::update_location()
{
	if ((fabs(fabs(destination.x) - fabs(location.x)) <= fabs(delta.x) && fabs(fabs(destination.y) - fabs(location.y)) <= fabs(delta.y)) || cart_distance(destination,location) == 0)
	// Summary of the above statement: if the destination equals the location or is within one step of the location, then...
	{
		cout << display_code << get_id() << ": I'm there!" << endl;
		location = destination; // update the location variable
		return true;
	}
	else
	{
		cout << display_code << get_id() << ": step..." << endl;
		// continue moving
		location = location + delta; // using overloaded operator
		return false;
	}
}

void Person::setup_destination(Cart_Point dest) 
{
	// sets object to start moving to destination
	destination = dest;
	Cart_Vector separation = (destination - location);
	// calculate delta
	delta = separation * (speed / cart_distance(destination, location));
}

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
	// virtual function output - will not be used
	cout << "Sorry, I can't work a mine." << endl;
}
