// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Miner class (defined in Miner.cpp)

#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"

using namespace std;

class Miner : public Person
{
public:
	// Constructors
	Miner();
	Miner(int, Cart_Point);
	~Miner();

	// Public member functions
	bool update();
	void start_mining(Gold_Mine*, Town_Hall*);
	void show_status();

	/* Also inherited:
		from Game_Object: 
			int get_id();
			Cart_Point get_location();
		from Person:
			void start_moving(Cart_Point);
			void stop();
			void show_status();
	*/
private:
	double amount;
	Gold_Mine* mine;
	Town_Hall* home;

	/* Also inherited:
		from Game_Object:
			char display_code;
			int id_num;
			char state;
			Cart_Point location;
		from Person:
			double speed;
			Cart_Point destination;
			Cart_Vector delta;
	*/
};

#endif