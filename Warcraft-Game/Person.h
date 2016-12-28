// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Person class (defined in Person.cpp)

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cmath>
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

class Person : public Game_Object
{
public:
	// Constructors
	Person();
	Person(char);
	Person(char, int, Cart_Point);
	virtual ~Person();

	// Public member functions
	void start_moving(Cart_Point);
	void stop();
	void show_status();
	virtual void start_mining(Gold_Mine*, Town_Hall*);

	bool is_alive();
	void take_hit(int);
	virtual void start_attack(Person*);

	/* Also inherited:
		int get_id();
		Cart_Point get_location();
	*/

protected:
	bool update_location();
	void setup_destination(Cart_Point);

private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
	int health;

	/* Also inherited:
		char display_code;
		int id_num;
		char state;
		Cart_Point location;
	*/
};

#endif