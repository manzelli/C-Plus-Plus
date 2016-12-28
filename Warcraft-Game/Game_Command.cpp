// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// This file contains all of the commands that correspond to the user's input.
// These include the exception handling functions.

#include "Game_Command.h"

using namespace std;

void move(Model* model, int ID, double x, double y, View& view)
{
	// Takes in a person pointer, because only people move
	// Get the Person's pointer
	Person *newPerson = model->get_Person_ptr(ID);

	// Tell that Person to start moving
	newPerson->start_moving(Cart_Point(x,y));

	// Show grid
	model->display(view);
}

void work(Model* model, int personID, int mineID, int hallID, View& view)
{
	// Only Miners can do work. Miners are people. Get all of the pointers:
	Person *newPerson = model->get_Person_ptr(personID);
	Gold_Mine *newMine = model->get_Gold_Mine_ptr(mineID);
	Town_Hall *newHall = model->get_Town_Hall_ptr(hallID);

	// Tell person to work on the mine. This is why the start_mining function is virtual!
	newPerson->start_mining(newMine, newHall);

	// Show grid
	model->display(view);
}

void stop(Model* model, int ID, View& view)
{
	Person *newPerson = model->get_Person_ptr(ID);

	// Stop Person
	newPerson->stop();

	// Show grid
	model->display(view);
}

void go(Model* model, View& view)
{
	cout << "Advancing one tick." << endl;
	model->update();

	// Show grid
	model->show_status();
	model->display(view);
}

void run(Model* model, View& view)
{
	cout << "Advancing to next event." << endl;
	for (int i = 1; i <= 5; i++)
	{
		if (model->update())
		{
			break;
		}
	}

	// display once after while loop breaks
	model->show_status();
	model->display(view);

}

void quit(Model* myModel)
{
	delete myModel;
}

void list_them(Model* model)
{
	model->show_status();
	// List will also print the time
}

void attack(Model* model, int attackID, int targetID, View &view)
{
	Person *attacker = model->get_Person_ptr(attackID);
	Person *target = model->get_Person_ptr(targetID);

	// Start attack
	attacker->start_attack(target);

	// display status and grid
	model->show_status();
	model->display(view);
}

void makenew(Model* model, char in_code, int in_id, double x, double y, View& view)
{
	model->handlenew(in_code, in_id, x, y, view);
	model->display(view);
}

// Exception handling functions
int get_int()
{
	int i;
	if(!(cin >> i)) 
	{
		cin.clear();
		throw Invalid_Input("was expecting an integer.");
	}
	return i;
}

char get_char()
{
	char c; 
	if(!(cin >> c))
	{
		cin.clear();
		throw Invalid_Input("was expecting a character.");
	}
	return c;
}

double get_double()
{
	double d;
	if(!(cin >> d))
	{
		cin.clear();
		throw Invalid_Input("was expecting a double.");
	}
	return d;
}