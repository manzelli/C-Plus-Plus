// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Town_Hall class defines Town_Halls, where Miners can go to deposit gold. Town_Halls are derived from the Game_Object class.

#include "Town_Hall.h"

using namespace std;

// Constructors
Town_Hall::Town_Hall(): Game_Object('t', 0)
{
	amount = 0;
	state = 'o'; // original level
	cout << "Town_Hall default constructed." << endl;

	/* Also initialized:
		display_code = 't';
		id_num = 0;
		location = Cart_Point();
	*/
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc): Game_Object('t', inputId, inputLoc)
{
	amount = 0;
	state = 'o';
	cout << "Town_Hall constructed." << endl;

	/* Also initialized:
		display_code = 't';
		id_num = inputId;
		location = inputLoc;
	*/
}

// Public member functions

/* Inherited:
	Cart_Point get_location();
	int get_id();
*/

// Destructor
Town_Hall::~Town_Hall()
{
	cout << "Town_Hall destructed." << endl;
}

void Town_Hall::deposit_gold(double deposit_amount)
{
	// Deposit gold to Town_Hall
	amount += deposit_amount;
}

bool Town_Hall::update()
{
	if (amount >= 50 && state == 'o')
	{
		state = 'u'; // upgraded
		display_code = 'T'; // indicate upgrade
		cout << display_code << get_id() << " has been upgraded." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Town_Hall::show_status()
{
	cout << "Town_Hall status: ";
	// call Game_Object's show_status
	Game_Object::show_status();
	cout << "contains " << amount << " of gold. ";
	if (state == 'u')
	{
		cout << "Upgraded." << endl;
	}
	else
	{
		cout << "Not yet upgraded." << endl;
	}
}