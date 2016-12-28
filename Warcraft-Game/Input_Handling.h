// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 3: Warcraft

// Header file for the declaration of the Invalid_Input class (only defined here)

#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

class Invalid_Input
{
	public:
	Invalid_Input(const char * in_ptr):msg_ptr(in_ptr){} 
	const char * const msg_ptr;

	private:
	Invalid_Input(); // No default construction
};

#endif