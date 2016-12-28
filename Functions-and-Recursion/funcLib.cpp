// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 1: Functions, Header Files, File I/O

// This file will house all of the function implementations that are not previously established as core math commands.

#include <iostream>
#include <fstream> // ifstream, ofstream
#include <cmath>  // the core math functions
#include <stdlib.h> // srand, rand
#include <iomanip> // setprecision
#include <string> // string

using namespace std;

//Header to include external variable
extern int ENTRIES;

// Mathematical functions:

void areaSq(double fside, double lside, double delta)
{
	// Prints area of a square given a side, from first to last in steps of delta
	int count = 0;
	for (fside; fside <= lside; fside += delta)
	{
		if (count < ENTRIES)
		{
			double area = fside * fside;
			cout << fixed;
			cout << "Area of square with side length " << setprecision(2) << fside << " = " << setprecision(4) << area << endl;
			count++;
		}
		else
		{
			break;
		}

	}
	cout << endl;
}

void circFun(double frad, double lrad, double delta)
{
	// Prints circumference of a circle given a radius, from first to last in steps of delta
	int count = 0;
	for (frad; frad <= lrad; frad += delta)
	{
		if (count < ENTRIES)
		{
			const double PI = 2 * acos(0.0);
			double circ = 2 * PI * frad;
			cout << fixed;
			cout << "Circumference of a circle with radius " << setprecision(2) << frad << " = " << setprecision(4) << circ << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

void sqRoots(double fnum, double lnum, double delta)
{
	// Prints square root of a given value, from first to last in steps of delta
	int count = 0;
	for (fnum; fnum <= lnum; fnum += delta)
	{
		if (count < ENTRIES)
		{
			double root = sqrt(fnum);
			cout << fixed;
			cout << "Square root of " << setprecision(2) << fnum << " = " << setprecision(4) << root << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

void oddNum(double first, double last, double delta)
{
	// Prints odd numbers from first to last
	int count = 0;
	cout << fixed;
	cout << "Odd numbers from " << setprecision(2) << first << " to " << setprecision(2) << last << " = ";
	for (first; first <= last; first++)
	{
		if (count < ENTRIES)
		{
			if (fmod(first,2.0) == 1.0)
			{
				cout << static_cast<int>(first) << " ";
			}
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl << endl;
}

void luckyNum(double fnum, double lnum, double delta)
{
	// Prints random numbers for each first/last entered
	int count = 0;
	for (fnum; fnum <= lnum; fnum += delta)
	{
		if (count < ENTRIES)
		{
			srand (fnum);
			double lucky = rand();
			cout << fixed;
			cout << "Lucky number of " << setprecision(2) << fnum << " = " << setprecision(4) << lucky << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

void sinVal(double ftheta, double ltheta, double delta)
{
	// Prints sine of a given angle, from first to last in steps of delta
	int count = 0;
	for (ftheta; ftheta <= ltheta; ftheta += delta)
	{
		if (count < ENTRIES)
		{
			double tsine = sin(ftheta);
			cout << fixed;
			cout << "Sine of " << setprecision(2) << ftheta << " = " << setprecision(4) << tsine << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

void cosVal(double ftheta, double ltheta, double delta)
{
	// Prints cosine of a given angle, from first to last in steps of delta
	int count = 0;
	for (ftheta; ftheta <= ltheta; ftheta += delta)
	{
		if (count < ENTRIES)
		{
			double tcos = cos(ftheta);
			cout << fixed;
			cout << "Cosine of " << setprecision(2) << ftheta << " = " << setprecision(4) << tcos << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

void expFunc(double fnum, double lnum, double delta)
{
	// Prints exponential of a given value, from first to last in steps of delta
	int count = 0;
	for (fnum; fnum <= lnum; fnum += delta)
	{
		if (count < ENTRIES)
		{
			double expon = exp(fnum);
			cout << fixed;
			cout << "Exponential of " << setprecision(2) << fnum << " = " << setprecision(4) << expon << endl;
			count++;
		}
		else
		{ 
			break;
		}
	}
	cout << endl;
}

void logFunc(double fnum, double lnum, double delta)
{
	// Prints natural logarithm of a given value, from first to last in steps of delta
	int count = 0;
	for (fnum; fnum <= lnum; fnum += delta)
	{
		if (count < ENTRIES)
		{
			double logar = log(fnum);
			cout << fixed;
			cout << "Natural Log of " << setprecision(2) << fnum << " = " << setprecision(4) << logar << endl;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << endl;
}

double findNyanCatValue(double myNum)
{
	// Finds the Nyan Cat value. Called by writeDataToFile (must be defined before writeDataToFile).
	return (pow( 3*myNum, myNum ) + myNum);
}

// Other functions:

void initialize()
{
	// Prints the program output header. Called from main().
	cout << "327: Introduction to Software Engineering" << endl << "Fall 2016" << endl << "Programming Assignment 2" << endl;
	cout << "Maximum computation is: " << ENTRIES << endl << endl;
}

bool checkCode(char code)
{
	// Error checks for valid user code input; returns true/false accordingly. Called from main().
	// The simplest way to error check in this case is to validate correct input instead of checking many incorrect input cases
	bool valCode = false;
	
	// Create array of valid codes (not including 'q')
	char codeArr[] = {'U','u','C','c','R','r','D','d','L','l','S','s','N','n','E','e','A','a','Y','y','P','p','O','o'};

	// Loop through valid input array and compare to the user's code input
	int sizeArr = sizeof(codeArr) / sizeof(codeArr[0]); // Size of valid code array
	for (int i = 0; i < sizeArr; i++)
	{
		if (code == codeArr[i])
		{
			valCode = true;
		}
	}

	return valCode;
}

void writeDataToFile(const char * outfile)
{
	// Writes 3 separate NyanCat values to a file q1Output.txt. Called from main().
	// Open file
	ofstream ofile(outfile);

	// Generating required random parameters for findNyanCatValue
	srand(time(NULL));
	int minNyan = rand() % 21; // range: 0-20
	int maxNyan = rand() % 32 + 45; // range: 45-76
	int deltNyan = rand() % 6 + 5; // range: 5-10

	// Gather NyanCat values from first to last argument in steps of delta, writing to q1Output.txt with each iteration
	for (minNyan; minNyan <= maxNyan; minNyan += deltNyan)
	{
		ofile << "Nyan Cat Value of " << minNyan << " = " << findNyanCatValue(minNyan) << endl;
	}
	ofile.close();
	cout << "file has been written..." << endl;
}

void readDataFromFile(const char * infile)
{
	// Reads in commands from a file q1Input.txt. The commands will be treated as entered on the terminal. Called from main().
	// Open file
	ifstream ifile(infile);

	// Read in parameters line by line. Will contain a code and 3 number parameters.
	// The selection is repeated here in order to treat the commands. 
	char code;
	double first, last, delta;
	while (ifile >> code >> first >> last >> delta)
	{
		cout << fixed;
		cout << "Successfully read from file: Code " << setprecision(0) << code << " First " << setprecision(0) << first << " Finish " << setprecision(0) << last << " Delta " << setprecision(0) << delta << endl;
		// Return the input values to the main if-else statement
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
		else if (code == 'U' || code == 'u')
		{
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
}