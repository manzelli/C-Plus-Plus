// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 1, Question 3: Hamming Distance

// This program will calculate and print the Hamming distance between two numbers in ternary format.

#include <iostream>

using namespace std;

int main () {
// Declare variables
int num1, num2, hdist, ham1, ham2;
double n1remainder, n2remainder;

// Ask for 2 numbers and store them
cout << "Enter two numbers between 0-100: " << endl;
cin >> num1 >> num2;

// Store a separate copy of the inputs to print later
ham1 = num1;
ham2 = num2;

// Convert numbers to ternary as well as calculate the Hamming distance
// Using math, we are able to use modulo and division to convert the numbers to ternary.
while (num1 != 0 || num2 != 0) {
	// First, use modulo:
	n1remainder = num1 % 3;
	n2remainder = num2 % 3;
	// Then divide:
	num1 = num1/3;
	num2 = num2/3;

	//If these two numbers are not equal each time the loop goes through, the Hamming distance increases by 1.
	if (n1remainder != n2remainder) {
		hdist = hdist + 1;
	} 
}

cout << "The Hamming distance between " << ham1 << " and " << ham2 << " in ternary format is: " << hdist << "." << endl;

}