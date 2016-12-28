// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Miner class defines Miners, which can dig for gold at Gold_Mines and deposit it at Town_Halls.
// Miners are derived from the Person class. 

#include "Miner.h"

using namespace std;

// Constructors
Miner::Miner(): Person('M')
{
	amount = 0;
	mine = NULL;
	home = NULL;
	cout << "Miner default constructed." << endl;

	/* Also initialized:
		health = 5;
		display_code = 'M'; for Miner
		id_num = 0;
		location = Cart_Point();
		speed = 5;
	*/
}

Miner::Miner(int in_id, Cart_Point in_loc): Person('M', in_id, in_loc)
{
	amount = 0;
   	mine = NULL;
	home = NULL;
	cout << "Miner constructed." << endl;

		/* Also initialized:
		display_code = 'M';
		id_num = in_id;
		location = in_loc;
		speed = 5;
		health = 5;
	*/
}

// Destructor
Miner::~Miner()
{
	cout << "Miner destructed." << endl;
}

bool Miner::update()
{
	// Return true if state is changed as well as update status every unit of time
	// Best implementation: switch statement
	switch (state)
	{
		case 's': // Miner is stopped
		{
			break; // no change in state
		}
		case 'm': // Miner is moving to a destination
		{
			bool stat = update_location();
			if (stat) // destination = location
			{
				state = 's'; // change state to stopped
				return true;
			}
			else
			{
				return false; // no change in state
			}
			break;
		}
		case 'o': // Miner is outbound to a mine
		{
			bool stat = update_location();
			if (stat) // destination = location
			{
				state = 'g'; // getting gold from mine
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case 'g': // Miner is getting gold from a mine
		{
			// Use Gold_Mine's dig_gold function with assigned mine
			amount = mine->dig_gold(); // amount carrying = dig_gold function on the mine (dereferenced since it is a pointer)
			cout << display_code << get_id() << ": Got " << amount << " gold." << endl;

			// change location to home (Town_Hall where gold will be deposited)
			setup_destination(home->get_location());

			state = 'i'; // inbound to Town_Hall
			return true;
			break;
		}
		case 'i': // Inbound from Gold_Mine to Town_Hall
		{
			bool stat = update_location(); // Miner has arrived to Town_Hall
			if (stat)
			{
				state = 'd'; // deposit gold!
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case 'd':
		{
			home->deposit_gold(amount);

			// If mine is depleted, stop the miner:
			if (mine->is_empty())
			{
				state = 's'; // stop
				cout << display_code << get_id() << ": Deposit " << amount << " of gold." << endl;
				cout << display_code << get_id() << ": More work?" << endl;
				amount = 0;
				return true;
			}
			// If the mine still has gold in it, go back to get it:
			else 
			{
				state = 'o'; // outbound to a mine
				setup_destination(mine->get_location());
				cout << display_code << get_id() << ": Deposit " << amount << " of gold." << endl;
				cout << display_code << get_id() << ": Going back for more." << endl;
				amount = 0;
				return true;
			}
			break;
		}
		case 'x':
		{
			// do nothing (dead)
			return false;
		}
	}
	return false;
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
	if (!is_alive())
	{
		cout << "This Miner is dead!" << endl;
		// Ignore command
	}
	else
	{
		mine = inputMine;
		home = inputHome;

		// set destinatinon to assigned Gold_Mine using the mine's location variable
		setup_destination(mine->get_location());
		state = 'o'; // get going! state set to outbound to a mine

		cout << "Miner " << get_id() << " mining at Gold_Mine " << mine->get_id() << " and depositing at Town_Hall " << home->get_id() << "." << endl;
		cout << display_code << get_id() << ": Yes, my lord." << endl;
	}
}

void Miner::show_status()
{
	cout << "Miner status: ";
	switch (state)
	{
		case 's':
		{
			Game_Object::show_status();
			cout << "is stopped." << endl;
			break;
		}
		case 'm':
		{
			Person::show_status();
			cout << endl;

			break;
		}
		case 'o':
		{
			Person::show_status();
			cout << "is outbound to a mine." << endl;
			break;
		}
		case 'g':
		{
			Person::show_status();
			cout << "is getting gold from mine." << endl;
			break;
		}
		case 'i':
		{
			Person::show_status();
			cout << "is inbound to home with load: " << amount << endl; // displays amount carrying
			break;
		}
		case 'd':
		{
			Person::show_status();
			cout << "is depositing gold." << endl;
			break;
		}
	}
}