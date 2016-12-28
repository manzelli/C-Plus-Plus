// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// THIS IS THE MAIN PROGRAM, which takes in the user's command and passes it to the appropriate Game_Command.

#include <iostream>
#include <list>
#include <string>

#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Miner.h"
#include "Person.h"
#include "Game_Command.h"
#include "Soldier.h"
#include "Model.h"
#include "Input_Handling.h"

using namespace std;

int main()
{
	// Start screen
	cout << "EC327: Introduction to Software Engineering" << endl << "Fall 2016" << endl << "Programming Assignment 4" << endl;

	// Declare objects to be used in main program
	char in_command;
	Model* myModel = new Model();
	View view;

	// Show initial game status
	myModel->show_status();
	myModel->display(view);

	do
	{
		// We cannot assume the user enters the correct input, so we implement a try catch to catch the exceptions from normal input
		try {

			cout << "Enter command: ";
			in_command = get_char();
	
			switch (in_command)
			{
				case 'm':
				// Tell a Person to move to a destination
				// Format: m ID X Y
				{
					int ID = get_int();
					double x = get_double();
					double y = get_double();

					move(myModel, ID, x, y, view);
					break;
				}

				case 'w':
				// Tell a Miner to work a Gold_Mine and deposit at a Town_Hall
				// Format: w personID mineID hallID
				{
					int personID = get_int();
					int mineID = get_int();
					int hallID = get_int();

					work(myModel, personID, mineID, hallID, view);
					break;
				}

				case 's':
				// Stop a Person
				// Format: s ID
				{
					int ID = get_int();

					stop(myModel, ID, view);
					break;
				}

				case 'g':
				// Advance one tick
				// Format: g
				{
					go(myModel, view);
					break;
				}

				case 'r':
				// Run until an event occurs, or until 5 ticks go by
				// Format: r
				{
					run(myModel, view);
					break;
				}

				case 'l':
				// List the status of the objects currently on the board and the time
				// Format: l
				{
					list_them(myModel);
					break;
				}
				case 'a':
				// Command a person to attack a target
				// Format: a attackID targetID
				{
					int attackID = get_int();
					int targetID = get_int();
					attack(myModel, attackID, targetID, view);
					break;
				}
				case 'n':
				// Create new object
				// Format: n object_code ID X Y
				{
					char command = get_char();
					int id = get_int();
					double x = get_double();
					double y = get_double();

					myModel->handlenew(command, id, x, y, view);
					break;
				}
				default:
				{
					throw Invalid_Input("Invalid command.");
				}
			}

		}

		// catch exceptions
		catch (Invalid_Input& exception)
		{
			cout << "Invalid input - " << exception.msg_ptr << endl;

		}

		cin.ignore(1000, '\n');

	} while (in_command != 'q');

	quit(myModel); // Quit game
}