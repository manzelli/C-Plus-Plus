// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 2: Statistics (File I/O, Arrays, Random Numbers)

// This program demonstrates the functionality of the functions written in FileFunctions.cpp and Statistics.cpp.

#include <iostream>
#include <iomanip>
#include "FileFunctions.h"
#include "Statistics.h"

using namespace std;

int main()
{	
	// Check write function
	WriteRandomDataToFile("numbers.txt", 7, 8);

	// Check read function
	int size = 5; // Arbitrary, will be changed by ReadDataFromFile
	int * myArray = new int[1000]; // Allocating giant array on the heap

	ReadDataFromFile("numbers.txt",myArray,size);

	// Declaring mean and std variables
	float fileMean = getMean(myArray, size);
	float fileDev = getStDev(myArray, size);
	
	// Display 
	cout << fixed;
	cout << "Array size is: " << size << endl;
	cout << "Mean is: " << setprecision(2) << fileMean << endl;
	cout << "Standard Deviation is: " << setprecision(2) << fileDev << endl;

	delete myArray; // Free heap memory
	return 0;
}
