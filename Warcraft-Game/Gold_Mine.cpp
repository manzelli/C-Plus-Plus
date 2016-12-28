// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Gold_Mine class defines Gold_Mines, which store gold. They can be depleted by Miners.
// Gold_Mines are derived from the Game_Object class.

#include "Gold_Mine.h"

using namespace std;

// Constructors
Gold_Mine::Gold_Mine(): Game_Object('G', 0)
{
	state = 'f';
	amount = 100;

	/* Also initialized:
		display_code = 'G';
		id_num = 0;
		location = Cart_Point();
	*/
}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc): Game_Object('G', inputId, inputLoc)
{
	state = 'f';
	amount = 100;
	cout << "Gold_Mine constructed." << endl;

	/* Also initialized:
		display_code = 'G';
		id_num = inputId;
		location = inputLoc;
	*/
}

// Destructor
Gold_Mine::~Gold_Mine()
{
	cout << "Gold_Mine destructed." << endl;
}

// Public member functions
bool Gold_Mine::is_empty()
// Returns true if Gold_Mine is empty, returns false otherwise
{
	if (amount == 0) // Gold mine contains zero gold
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Gold_Mine::dig_gold(double amount_to_dig) // amount_to_dig = 35.0 default
// Function for digging operations
{
	if (amount >= amount_to_dig)
	{
		amount -= amount_to_dig;
		return amount_to_dig;
	}
	else if (amount <= amount_to_dig)
	{
		// Need to first save current amount before setting to 0
		double currAmount = amount;
		amount = 0;
		return currAmount;
	}
}

bool Gold_Mine::update() 
{
	if (state == 'f' && is_empty()) // If the Gold_Mine's state is set as full, but it is actually empty
	{
		display_code = 'g'; // to indicate that it is depleted
		state = 'e'; // empty
		// Use getter to get id_num and print
		cout << "Gold Mine " << get_id() << " has been depleted." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Gold_Mine::show_status()
{
	cout << "Gold_Mine status: ";
	cout << display_code << get_id() << " at location " << get_location() << " "; // Using getters to get private variables
	cout << "Contains " << amount << "." << endl;
}