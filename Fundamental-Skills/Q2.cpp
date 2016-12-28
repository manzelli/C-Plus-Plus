// Rachel Manzelli
// EC327 Fall 2016: Programming Assignment 1, Question 2: Tip and Tax on a Bill

// This program will calculate tax and tip on a meal, and will output the total bill pre-tip as well as the tip amount and total bill post-tip.

#include <iostream>
#include <iomanip> // setprecision

using namespace std;

int main()
{
	// Declare variables
	float bill, taxrate, tax, taxbill, tip, totbill, tiprate;
	int tipontax;

	// Establish printing 2 decimals
    cout << setprecision(2) << fixed << endl;

	// Ask user for bill amount and store
	cout << "Enter the original bill amount: ";
	cin >> bill;

	// Ask user for tax rate and store; calculate tax and store bill with added tax
	cout << "Enter the tax rate %: ";
	cin >> taxrate;

	tax = bill * (taxrate / 100);
	taxbill = bill + tax;

	// Ask user for tip level (15%, 20%, 25%)
	cout << "Enter desired tip level (1=15%, 2=20%, 3=25%): ";
	cin >> tiprate;

	// Error check
	while (tiprate < 1 || tiprate > 3) {
		cout << "That can't be right. Try again: " << endl;
		cout << "Enter tip level (1=15%, 2=20%, 3=25%): ";
		cin >> tiprate;
	} 

	// Store the actual tip rate amount
	if (tiprate == 1) {
		tiprate = 0.15;
	}
	else if (tiprate == 2) {
		tiprate = 0.2;
	}
	else if (tiprate == 3) {
		tiprate = 0.25;
	}

	// Ask if the user wants to tip on post-tax amount, calculate tip
	cout << "Tip on post-tax amount? (1=yes, 2=no): ";
	cin >> tipontax;

	// Error check
	while (tipontax != 1 && tipontax != 2) {
		cout << "That can't be right. Try again: " << endl;
		cout << "Tip on post-tax amount? (1=yes, 2=no): ";
		cin >> tipontax;
	}

	// Calculate totals depending on if the user wants to tip on taxed bill or not
	if (tipontax == 1) {
		tip = taxbill * tiprate;
		totbill = taxbill + tip;
	}
	else if (tipontax == 2) {
		tip = bill * tiprate;
		totbill = taxbill + tip;
	}
	
	// Print total bill (with tax) and tip amount, as well as total bill with tip
	cout << "Your total bill pre-tip is: " << taxbill << endl;
	cout << "Your total tip is: " << tip << endl;
	cout << "Your total bill post-tip is: " << totbill << endl;

	return 0;
}