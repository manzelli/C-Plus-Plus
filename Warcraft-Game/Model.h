// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Model class (defined in Model.cpp)

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "View.h"
#include "Soldier.h"

using namespace std;

class Model
{
public:
	Model();
	~Model();
	Person* get_Person_ptr(int);
	Gold_Mine* get_Gold_Mine_ptr(int);
	Town_Hall* get_Town_Hall_ptr(int);
	bool update();
	void display(View&);
	void show_status();

	void handlenew(char&, int&, double&, double&, View&);

private:
	int time;

	// Copy constructor
	Model(Model&);

	// Hardcoded number of objects
	int num_objects;
	int num_persons;
	int num_mines;
	int num_halls;

	// List/iterator declarations
	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs;
	list<Person*> person_ptrs;
	list<Gold_Mine*> mine_ptrs;
	list<Town_Hall*> hall_ptrs;

	list<Game_Object*>::iterator o;
	list<Game_Object*>::iterator a;
	list<Person*>::iterator p;
	list<Gold_Mine*>::iterator m;
	list<Town_Hall*>::iterator h;
};

#endif