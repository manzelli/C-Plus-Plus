// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// The Model class creates the set of initial objects on the board. It also updates the board by deleting all of the dead objects.
// Model calls each class's update() function whenever an event occurs so that the status of the object can be displayed.

#include "Model.h"

using namespace std;

// Constructors
Model::Model()
{
	// Set initial time
	time = 0;

	// First we have to add all of the object pointers to the specific pointer lists. Then we can add them all to the object_ptrs list
	// Using list, we can add all of the new objects to each pointer list using push_back:
	person_ptrs.push_back(new Miner(1,Cart_Point(5,1)));
	person_ptrs.push_back(new Miner(2,Cart_Point(10,1)));
	person_ptrs.push_back(new Soldier(3,Cart_Point(5,15)));
	person_ptrs.push_back(new Soldier(4,Cart_Point(10,15)));

	mine_ptrs.push_back(new Gold_Mine(1,Cart_Point(1,20)));
	mine_ptrs.push_back(new Gold_Mine(2,Cart_Point(10,20)));

	hall_ptrs.push_back(new Town_Hall(1,Cart_Point(0,0)));

	// To add all of the pointers to the object_ptrs list, we can implement push_back for the individual lists
	// add Persons to object_ptrs

	// Algorithm: from beginning to end of ptrs list, push back a dynamic cast of the specific object to a game object
	// Persons
	for (p = person_ptrs.begin(); p != person_ptrs.end(); p++)
	{
		object_ptrs.push_back(dynamic_cast<Game_Object*>(*p));
	}

	// Gold_Mines
	for (m = mine_ptrs.begin(); m != mine_ptrs.end(); m++)
	{
		object_ptrs.push_back(dynamic_cast<Game_Object*>(*m));
	}

	// Town_Hall
	for (h = hall_ptrs.begin(); h != hall_ptrs.end(); h++)
	{
		object_ptrs.push_back(dynamic_cast<Game_Object*>(*h));
	}

	// setting numbers of objects
	num_objects = 7;
	num_persons = 4;
	num_mines = 2;
	num_halls = 1;

	// We must create an active_ptrs list to edit when objects die, so we use the copy constructor for Model
	active_ptrs = object_ptrs;

	cout << "Model constructed." << endl;
}

// Destructor
Model::~Model()
{
	// Loop through array of objects on the heap and delete all of them
	for (o = object_ptrs.begin(); o != object_ptrs.end(); o++)
	{
		delete *o;
	}

	cout << "Model destructed." << endl;
}

// Copy constructor
Model::Model(Model& model) {}

// Public getters of object pointers
Person* Model::get_Person_ptr(int id)
{

	for (p = person_ptrs.begin(); p != person_ptrs.end(); p++)
	{
		if ((*p)->get_id() == id)
		{
			return *p;
		}
	}
	return 0;
}

Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
	for (m = mine_ptrs.begin(); m != mine_ptrs.end(); m++)
	{
		if ((*m)->get_id() == id)
		{
			return *m;
		}
	}
	return 0;
}

Town_Hall* Model::get_Town_Hall_ptr(int id)
{

	for (h = hall_ptrs.begin(); h != hall_ptrs.end(); h++)
	{
		if ((*h)->get_id() == id)
		{
			return *h;
		}
	}
	return 0;
}

bool Model::update()
{
	// increment time by one tick
	time++;

	// Check for events and update objects
	int eventNum = 0;

	for (a = active_ptrs.begin(); a != active_ptrs.end(); ++a)
	{
		bool event = (*a)->update();
		if (event)
		{
			eventNum++;
		}
	}

	// Delete all of the dead objects from the active pointers by using the erase property in list
	for (a = active_ptrs.begin(); a!= active_ptrs.end(); ++a)
	{
		if (!(*a)->is_alive()) // object is dead
		{
			a = active_ptrs.erase(a); // delete
		}
	}

	// Return true if an event occurred
	if (eventNum > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Model::show_status()
{
	// output time
	cout << "Time: " << time << endl;

	// Call all show_status functions
	for (o = object_ptrs.begin(); o != object_ptrs.end(); o++)
	{
		(*o)->show_status();
	}
}

void Model::display(View& view)
{
	// generates view display for all of the Game_Objects
	view.clear();

	for (a = active_ptrs.begin(); a != active_ptrs.end(); a++)
	{
		view.plot(*a);
	}

	view.draw();
}

void Model::handlenew(char& command, int& in_id, double& x, double& y, View& view)
{
	switch (command)
	{
		case 'm': // Miner
		{
			// Does the Person exist already?
			Person *newPerson = get_Person_ptr(in_id);

			if (newPerson)
			{
				cout << "This Miner already exists." << endl;			
			}
			else
			{
				// Add new Person if they don't already exists. We can use .back() to do this, this is the end of the list
				person_ptrs.push_back(new Miner(in_id,Cart_Point(x, y)));
				object_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
				active_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			}

			this->display(view);

			break;
		}
		case 'g':
		{
			// Look to see if the mine already exists
			Gold_Mine *newMine = get_Gold_Mine_ptr(in_id);

			if (newMine) // object already exists
			{
				cout << "This Gold_Mine already exists." << endl;
			}
			else
			{
				// Create new object to add to list using push_back if it doesn't exist
				mine_ptrs.push_back(new Gold_Mine(in_id, Cart_Point(x, y)));
				object_ptrs.push_back(dynamic_cast<Game_Object*>(mine_ptrs.back()));
				active_ptrs.push_back(dynamic_cast<Game_Object*>(mine_ptrs.back()));
			}

			this->display(view);

			break;
		}
		case 't':
		{
			Town_Hall *newHall = get_Town_Hall_ptr(in_id);

			if (newHall)
			{
				cout << "This Town_Hall already exists." << endl;
			}
			else
			{
				hall_ptrs.push_back(new Town_Hall(in_id, Cart_Point(x, y)));
				object_ptrs.push_back(dynamic_cast<Game_Object*>(hall_ptrs.back()));
				active_ptrs.push_back(dynamic_cast<Game_Object*>(hall_ptrs.back()));
			}

			this->display(view);

			break;
		}
	
		case 's':
		{
			Person *newSoldier = get_Person_ptr(in_id);

			if (newSoldier != NULL)
			{
				cout << "This Soldier already exists." << endl;
			}
			else
			{
				person_ptrs.push_back(new Soldier(in_id,Cart_Point(x, y)));
				object_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
				active_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			}

			this->display(view);

			break;
		}
		default:
			cout << "Invalid object type." << endl;
	}
}