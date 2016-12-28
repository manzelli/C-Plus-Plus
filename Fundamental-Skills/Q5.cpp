// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 1, Question 5: Encryption

// This program will convert a letter input to the next letter in the alphabet, or print an error message if the user did not enter a letter.

#include <iostream>

using namespace std;

int main()
{

	//Declare variables (besides alphabet array)
	char letter;
	bool lettercheck = false;
	char encryption;

	// Create a character array of the alphabet
	char alphArray[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	// Gather the letter to be encrypted from the user and store it
	cout << "Enter a letter: ";
	cin >> letter;

	// Changes to uppercase letter if entered as lowercase
	letter = toupper(letter);

	// Loop through the alphabet to find the letter the user entered
	for (int i = 0; i < (sizeof(alphArray) / sizeof(alphArray[0])); i++) {
		char currentletter = alphArray[i];
		if (currentletter == letter)
		{
			// Change the letter to the encryption
			// Lettercheck will later print if the user did not input a letter
			lettercheck = true;
			if (i == (sizeof(alphArray) / sizeof(alphArray[0])) - 1) // If the letter is Z
			{
				encryption = alphArray[0];
			}
			else
			{
				encryption = alphArray[i + 1]; // the next letter
			}

			cout << "CRYPTO: " << encryption << endl;
		}
	}
	
	// Print out that the user did not input a letter if the lettercheck condition never became true
	if (lettercheck == false) {
		cout << "YOU DID NOT ENTER A LETTER" << endl;
	}

	return 0;
}