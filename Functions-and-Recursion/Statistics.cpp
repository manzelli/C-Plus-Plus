// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 2, Question 2: Statistics (File I/O, Arrays, Random Numbers)

// This file contains three statistical functions: a square root function, mean function, and standard deviation function.
// The mean and standard deviation functions operate on arrays.

#include <iostream>

using namespace std;

float sqrt(float N)
{
	// Sqrt function without using <cmath>
	// Babylonian method of average of guesses:
	float s = ((N/2) + N / (N/2)) / 2; // First guess
	for (int i = 1; i <= 4; i++) // Average of guesses
	{
	s = (s + N / s) / 2;
	}
	return s;
}

float getMean(int myArray[], int size)
{
	// Returns mean of array as a float
	float sum;
	for (int i = 0; i < size; i++)
	{
		sum += myArray[i];
	}
	
	float meanArray = sum / size;
	return meanArray;
}

float getStDev(int myArray[], int size)
{
	// Returns standard deviation of array as a float
	// Call mean function
	float mean = getMean(myArray, size);

	// Get standard deviation
	float sum;
	for (int i = 0; i < size; i++)
	{
		float temp = (myArray[i] - mean);
		sum += temp * temp;
	}
	float newMean = sum / size; 
	float stDev = sqrt(newMean);
	return stDev;
}
