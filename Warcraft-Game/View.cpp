// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// View creates the grid display of the game board on the console.

#include "View.h"

using namespace std;

// Constructor
View::View()
{
	size = 11;
	scale = 2;
	origin = Cart_Point();
}

// Public member functions
void View::clear()
{
	// resets grid array back to all dots using 3D array
	// Assigning the grid variable, not plotting yet
	for (int x = 0; x < view_maxsize; x++)
	{
		for (int y = 0; y < view_maxsize; y++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}

void View::plot(Game_Object* ptr)
{
	// Plots the display code and ID onto the grid
	int x;
	int y;
	// if location is within the game grid
	bool validPlot = get_subscripts(x, y, ptr->get_location());
	if (validPlot)
	{
		// check to see if grid location is already occupied
		if (grid[y][x][0] != '.') // there is something besides a dot in this space
		{
			// '*' multiple objects in same grid location have a star
			grid[y][x][0] = '*';
			grid[y][x][1] = ' ';
		}
		else
		{
			// just a dot - draw Game_Object in grid location
			ptr->drawself(grid[y][x]);
		}
	}
}

void View::draw()
{
	// output the grid onto the screen, using cout
	int x;
	int y;
	int i;

	for (y = 0; y < size; y++)
	{
		// For the y-axis I had to print each number on the axis as well as the whole row of dots that follow
		if (y % 2 == 0)  // Represents line #. If y is an even number... skipping lines
		{ 
			// Print the labels on the y-axis first using the maxsize. These go from top to bottom
			cout << setw(2) << left << view_maxsize - 2 * y;
		}
		else // Spaces on y-axis in front of dots
		{
			cout << "  ";
		}

		for (x = 0; x < size; x++) // Printing the grid dots row by row
		{
			cout << grid[size - y - 1][x][0] << grid[size - y - 1][x][1];
		}

		cout << endl;
	}

	// Print bottom line of numbers on the x-axis
	for (i = 0; i <= 20; i = i + 4) // skipping every 4 numbers on the x-axis
	{
		cout << "  "; // Two spaces between every number
		cout << i; // print number
		if (i < 10)
			cout << " "; // extra space between one-digit numbers
	}

	cout << endl; // new line at the end
}


// Private member functions
bool View::get_subscripts(int& ix, int& iy, Cart_Point location)
{
	// determines if the Cart_Point location of the object is able to be plotted on the display
	// we are passed 2 subscripts, so we must check each of them against the size

	ix = (location.x - origin.x) / scale; // automatically casts to integer because scale is an integer
	iy = (location.y - origin.y) / scale;

	// if the subscripts aren't within the size...
	if (!(ix <= size && iy <= size))
	{
		// ... that object doesn't fit in the display.
		cout << "An object is outside the display." << endl;
		return false;
	}
	else
	{
		return true; // inside the display
	}
}