// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 1: Functions, Header Files, File I/O

// This program will accept single-letter commands from the user, perform the appropriate functions, and return the appropriate responses.

#include <iostream>
#include <fstream> // ifstream, ofstream
#include <cmath> // the core math functions
#include <iomanip> // setprecision
#include "funcLib.h" // my library of functions

using namespace std;

// Declare external variable outside all functions
// This variable corresponds to the maximum number of responses the program may output before asking for another input.
extern const int ENTRIES = 23;

int main() 
{
	// Output header
	initialize();

	// Declare input variables
	char code;
	float first, last, delta;

	// Begin input loop
	top: while (true)
	{
		cout << "Please enter command code: ";
		cin >> code;

		// After receiving the code, the program must call its respective mathematical function.
		// I chose to implement this through a selection statement.
		// Since the selection is so long, I also decided to make the program majoratively modular (to shorten it).

		// If the user decides to quit...
		if (code == 'q' || code == 'Q')
		{
			break;
		}
		// If the input was otherwise invalid...
		else if (!checkCode(code))
		{
			cout << "Not a valid command..." << endl;
		}
		// If the command is a write command...
		else if (code == 'O' || code == 'o')
		{
			writeDataToFile("q1Output.txt");
			// No parameters
		}
		// If the command is a read command...
		else if (code == 'P' || code == 'p')
		{
			readDataFromFile("q1Input.txt");
			// No parameters
		}
		else if (code == 'U' || code == 'u')
		{
			cout << "Please enter command parameters: ";
			
			cin >> first;
				if (cin.get() == '\n') // cin.get() parses input character by character
			{
				cout << "No Computation needed" << endl << endl;
				// Although goto statements are generally frowned upon, for simple programs like this, I figured it wouldn't create any unreadable code.
				goto top;
			}
			cin >> last;
			cin >> delta;

			// If delta <= 0 or the first parameter is greater than the last, the program does no computation.
			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Area of square
				areaSq(first, last, delta);
			}
			
		}
		else if (code == 'C' || code == 'c')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Circumference
				circFun(first, last, delta);
			}

		}
		else if (code == 'R' || code == 'r')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Square roots
				sqRoots(first, last, delta);
			}

		}
		else if (code == 'D' || code == 'd')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Odd numbers	(ignore delta)
				oddNum(first, last, delta);
			}

		}
		else if (code == 'L' || code == 'l')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Lucky numbers
				luckyNum(first, last, delta);
			}

		}
		else if (code == 'S' || code == 's')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Sine
				sinVal(first, last, delta);
			}

		}
		else if (code == 'N' || code == 'n')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Cosine
				cosVal(first,last,delta);
			}

		}
		else if (code == 'E' || code == 'e')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Exponentials
				expFunc(first, last, delta);
			}

		}
		else if (code == 'A' || code == 'a')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// Natural logarithms
				logFunc(first, last, delta);
			}
			
		}
		else if (code == 'Y' || code == 'y')
		{
			cout << "Please enter command parameters: ";
			cin >> first;
				if (cin.get() == '\n')
			{
				cout << "No Computation needed" << endl << endl;
				goto top;
			}
			cin >> last;
			cin >> delta;

			if (delta <= 0 || first > last)
			{
				cout << "No Computation needed" << endl << endl;
			}
			else
			{
				// NyanCat value
				int count = 0;
				for (first; first <= last; first += delta)
				{
					if (count < ENTRIES)
					{
						double catVal = findNyanCatValue(first);
						cout << "Nyan Cat Value of " << setprecision(2) << first << " = " << setprecision(4) << catVal << endl;
						count++;
					}
					else
					{
						break;
					}
				}
				cout << endl;
			}
		}
	}
	cout << "quitting...." << endl;
}