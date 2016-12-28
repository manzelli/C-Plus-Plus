// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 3: Computing a Series by Recursion

// This program computes a series using recursion.

#include <iostream>

using namespace std;

double series(double n)
{
	// Store series equation
	double serieseqn = (2 * n) / ((3 * n) + 2);
    
	if (n == 0)
	{
        	return 0;
	}
	else
	{
		// Recursive call
        	return serieseqn + series(n-1);
	}
}

int main()
{
	// Input
	double in;

	cout << "Enter n: ";
	cin >> in;

	// Calculate and print series
	cout << series(in) << endl;  
}
