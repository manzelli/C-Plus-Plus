// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 1, Question 1: Distance from a Point to a Line

// This program will take in 3 (x,y) coordinates. It will calculate the shortest distance from the third point to the line created by the two previous points.

#include <iostream>
#include <cmath> // pow, sqrt

using namespace std;

int main()
{
	// Declare variables
	float x1, y1, x2, y2, x3, y3;

	// Ask for and store coordinates
	cout << "Enter three x,y coordinates:" << endl;
	// The first delimiter with cin is a space, so we can store multiple inputs as follows:
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	// Calculate the distance from the third coordinate to the line using the distance formula
	distance = abs(((y2-y1)*x3) - ((x2-x1)*y3) + x2*y1 - y2*x1) / sqrt((pow((y2-y1),2)+(pow((x2-x1),2))));

	// Print the result
	cout << "The shortest distance from (" << x3 << "," << y3 << ") to the line composed of (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is ";
	cout << distance << "." << endl;

	return 0;
}