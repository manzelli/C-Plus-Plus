// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Soldier class (defined in Soldier.cpp)

#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Person.h"

class Soldier : public Person
{
public:
	// Constructors
	Soldier();
	Soldier(int, Cart_Point);
	~Soldier();

	// Public member functions
	bool update();
	void show_status();
	void start_attack(Person*);

	/* Also inherited:
		from Game_Object: 
			int get_id();
			Cart_Point get_location();
		from Person:
			void start_moving(Cart_Point);
			void stop();
			void show_status();
			void take_hit(attack_strength);
			bool is_alive();
	*/
private:
	int attack_strength;
	double range;
	Person* target;

	/* Also inherited:
		from Game_Object:
			char display_code;
			int id_num;
			char state;
			Cart_Point location;
		from Person:
			int health;
			double speed;
			Cart_Point destination;
			Cart_Vector delta;
	*/
};

#endif