// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Soldier class defines Soldiers, who can target and attack Miners. Soldiers are derived from the Person class.

#include "Soldier.h"

using namespace std;

// Constructors
Soldier::Soldier(): Person('S')
{
	attack_strength = 2;
	range = 2.0;
	cout << "Soldier default constructed." << endl;

	/* Also initialized:
		health = 5;
		display_code = 'S'; for Soldier
		id_num = 0;
		location = Cart_Point();
		speed = 5;
	*/
}

Soldier::Soldier(int in_id, Cart_Point in_loc): Person('S', in_id, in_loc)
{
	attack_strength = 2;
	range = 2.0;
	cout << "Soldier constructed." << endl;

	/* Also initialized:
		health = 5;
		display_code = 'S'; for Soldier
		id_num = in_id;
		location = in_loc;
		speed = 5;
	*/
}

Soldier::~Soldier()
{
	cout << "Soldier destructed." << endl;
}

void Soldier::start_attack(Person* in_target)
{
	if (state == 'x')
	{
		cout << "This Soldier is dead!" << endl;
		// Ignore command
	}
	else
	{
		if (cart_distance(in_target->get_location(), location) <= range)
		{
			cout << "Clang!" << endl;
			target = in_target;
			state = 'a';
		}
		else
		{
			cout << "Target out of range." << endl;
		}
	}
}

bool Soldier::update()
{
	switch (state)
	{
		case 's':
		{
			// stopped, do nothing
			return false;
		}
		case 'x':
		{
			// dead
			return false;
		}
		case 'm':
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
		case 'a':
		{
			if (cart_distance(target->get_location(), location) <= range)
			{
				target->take_hit(attack_strength);
				if (!target->is_alive())
				{
					// target is dead, Soldier won
					cout << "I triumph!" << endl;
					this->state = 's';
					return true;
				}
				else
				{
					cout << "Clang!" << endl;
					return false;
				}
			}
		}
	}
}

void Soldier::show_status()
{
	cout << "Soldier status: ";
	Person::show_status();
	if (state == 'a')
	{
		cout << "Soldier is attacking." << endl;
	}
	else
	{
		cout << "Soldier is not attacking." << endl;
	}
}
