// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 2: Statistics (File I/O, Arrays, Random Numbers)

// This file contains file input/output functions.
// WriteRandomDataToFile writes random numbers to a file, while ReadDataFromFile reads data from a file into an array.

#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> // time seed
#include <fstream> // ifstream, ofstream

using namespace std;

void WriteRandomDataToFile(const char* filename, int N, int M)
{
	// Writing random data to a file numbers.txt
	srand(time(NULL));
	ofstream ofile(filename);
	// Write to the file using N and M
	if (ofile.is_open())
	{
		for (int i = 0; i < N; i++)
		{
			int num = rand() % (M+1); // range: 0 to M
			ofile << num << endl;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	ofile.close();
}

void ReadDataFromFile(const char* inputfile, int myArray[], int &size)
{
	// Reading data from a file into an array
	int position = 0; // Index of array to increment
	int a;

	ifstream ifile(inputfile);
	while (ifile >> a)
	{
		myArray[position] = a;
		position++;
	}
	ifile.close();
	size = position; // Change size by reference
}
