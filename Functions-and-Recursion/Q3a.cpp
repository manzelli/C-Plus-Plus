// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 3: Recursively Computing the Greatest Common Divisor

// This program recursively computes the greatest common divisor of two positive integers m and n and returns the result as an integer.
// If either (or both) of the inputs is less than or equal to 0, the function returns zero to indicate invalid input.

#include <iostream>

using namespace std;

int gcd(int m, int n)
{
	if (m <= 0 || n <= 0)
	{
        return 0; // calculation will be zero anyways
	}
	else if (m % n == 0) // if m is evenly divided by n
	{
        return n;
	}
	else
	{
        return gcd(n,m % n); // recursive call
	}  
}

int main()
{
	// Declare variables
	int m, n;

	// Display
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	cout << "GCD is: " << gcd(m,n) << endl;   
}
