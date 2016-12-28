// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 1, Question 4: Blackjack

/* This program will create a blackjack simulator. Splitting cards and doubling down are not allowed. There is no dealer. It randomly draws 2 cards to start, and determines if you bust or allows you to draw again if your total is under 21. */

#include <iostream>
#include <time.h> // time (randomize)
#include <stdio.h> // printf, NULL
#include <stdlib.h> // srand, rand
#include <vector> // for initializing the card vector

using namespace std;
int inttemp;
char chtemp;

// Declaring the blackJack function, an overloaded function. Must be able to be called 6 ways depending on random user input. Returns an integer (the sum)
// For the first draw, we have two inputs for the two cards. They must accommodate for when a character is drawn.
int blackJack(int a, int b) {
	int value;
	value = a + b;
	return value;
}

int blackJack(char a, int b) {
	int value;
	int temp;
	// Convert a to its corresponding number or exit out of the program if a is an invalid entry
	if (a == 'A') {
		temp = 11;
	}
	else if (a == 'K' || a == 'J' || a == 'Q') {
		temp = 10;
	}
	else {
		cout << "ERROR OCCURRED" << endl;
	}
	value = temp + b;
	return value;
}

int blackJack(int a, char b) {
	int value;
	int temp;
	// Convert b to its corresponding number or exit out of the program if b is an invalid entry
	if (b == 'A') {
		temp = 11;
	}
	else if (b == 'K' || b == 'J' || b == 'Q') {
		temp = 10;
	}
	else {
		cout << "ERROR OCCURRED";
	}
	value = a + temp;
	return value;
}

int blackJack(char a, char b) {
	int value;
	int tempA;
	int tempB;
	// Convert a to its corresponding number or exit out of the program if a is an invalid entry
	if (a == 'A') {
		tempA = 11;
	}
	else if (a == 'K' || a == 'J' || a == 'Q') {
		tempA = 10;
	}
	else {
		cout << "ERROR OCCURRED";
	}
	// Convert b to its corresponding number or exit out of the program if b is an invalid entry
	if (b == 'A') {
		tempB = 11;
	}
	else if (b == 'K' || b == 'J' || b == 'Q') {
		tempB = 10;
	}
	else {
		cout << "ERROR OCCURRED";
	}
	value = tempA + tempB;
	return value;
}

// Redrawing the cards: second draw and continuing, only one card is drawn. Thus, one input:
int blackJack(char chtemp) {
	int value;
	int temp;
	// Recast character value obtained from main().
	chtemp = static_cast<char>(chtemp);
	// Convert to its corresponding number or exit out of the program if a is an invalid entry
	if (chtemp == 'A') {
		temp = 11;
	}
	else if (chtemp == 'K' || chtemp == 'J' || chtemp == 'Q') {
		temp = 10;
	}
	else {
		cout << "ERROR OCCURRED";
	}
	value = temp;
	return value;
}

int blackJack(int inttemp) {
	int value;
	value = inttemp;
	return value;
}

// Main function
int main ()
{
	// Declare response variable, runsum, random indices
	char resp;
	int aind, bind, naind; // Stands for a index, b index, new a index
	int runsum = 0;
	char a, b;

	// Declare array of inputs and convert to a character vector
	const char blackjackArray[] = {'A', 'K', 'Q', 'J', 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<char> choices(blackjackArray, blackjackArray + sizeof(blackjackArray) / sizeof(blackjackArray[0]));

	// Generate random vector indices
	srand(time(NULL));
	aind = rand() % choices.size();
	bind = rand() % choices.size();

	// Declare a and b depending on the index of the vector (is it a number or a character?)
	// Both characters
	if (aind <=3 && bind <=3) {
		char a = choices[aind];
		char b = choices[bind];
		// Welcome
		cout << "Welcome to EC327 BlackJack" << endl;
		// Get first random total
		runsum = blackJack(a,b);
		cout << "Total: " << runsum << endl;
	}
	// a is a character, b a number
	else if (aind <= 3 && bind > 3) {
		char a = choices[aind];
		int b = static_cast<int>(b);
		b = choices[bind];
		// Welcome
		cout << "Welcome to EC327 BlackJack" << endl;
		// Get first random total
		runsum = blackJack(a,b);
		cout << "Total: " << runsum << endl;
	}
	// a is a number, b a character
	else if (aind > 3 && bind <= 3) {
		int a = static_cast<int>(a);
		a = choices[aind];
		char b = choices[bind];
		// Welcome
		cout << "Welcome to EC327 BlackJack" << endl;
		// Get first random total
		runsum = blackJack(a,b);
		cout << "Total: " << runsum << endl;
	}
	// both numbers
	else if (aind > 3 && bind > 3) {
		int a = static_cast<int>(a);
		int b = static_cast<int>(b);
		a = choices[aind];
		b = choices[bind];
		// Welcome
		cout << "Welcome to EC327 BlackJack" << endl;
		// Get first random total
		runsum = blackJack(a,b);
		cout << "Total: " << runsum << endl;
	}

	// Loop for drawing again
	while (runsum < 21) {
		cout << "Draw Again (y/n): ";
		cin >> resp;
		if (resp == 'y') {
			// Pull another random card and add it to the total. Create another random index:
			naind = rand() % choices.size();
			// Character or integer?
			if (naind <= 3) {
				char a = choices[naind];
				chtemp = a;
				runsum = runsum + blackJack(chtemp);
			}
			else if (naind > 3 && naind <= 12) {
				// Static cast to an integer
				a = static_cast<int>(a);
				a = choices[naind];
				inttemp = a;
				runsum = runsum + blackJack(inttemp);
			}
			cout << "Total: " << runsum << endl;
		}
		else if (resp == 'n') {
			cout << "Total: " << runsum << endl;
			cout << "YOU QUIT WITH " << runsum << endl;
			break;
		}
		else {
			cout << "Total: " << runsum << endl;
			cout << "ERROR OCCURRED" << endl;
			break;
		}
	}

	// Ending messages
	if (runsum == 21) {
		cout << "WON BLACKJACK" << endl;
	}
	else if (runsum > 21) {
		cout << "FAILED BLACKJACK" << endl;
	}

	return 0;

}