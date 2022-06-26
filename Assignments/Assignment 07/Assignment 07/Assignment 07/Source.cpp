#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "FeetInches.h"

using namespace std;

double computeFootage(FeetInches l, FeetInches w, FeetInches h);	// function prototype

int main()
{
	const double galCost = 31.75;									// named constant for price of one gallon of paint
	const int coverage = 400;										// named constant for coverage of one gallon
	int totalRooms;													// init variable for amount of rooms from user input 
	string roomName;												// init variable for current room
	string roomColor;												// init variable for room color
	FeetInches length;												// init variable for room length
	FeetInches width;												// init variable for room width
	FeetInches height;												// init variable for room height

	cout << showpoint << setprecision(2) << fixed;					// format output

	cout << "Room Painting Cost Program by Nick Largey" << endl;	// print header			
	cout << "Enter number of rooms and their dimensions and get painting cost" << endl;
	cout << "The currect cost of paint per gallon is $" << galCost << endl;


	cout << "\nPlease enter total number of rooms: ";				// prompt user for total rooms
	cin >> totalRooms;												// assign total rooms

	for (int i = 0; i < totalRooms; i++) {
		cin.ignore();												// clear input buffer
		cout << "\nEnter Name of room: ";							// prompt user for room name
		getline(cin, roomName);										// assign room name

		cout << "Enter color of paint: ";							// prompt user for room color
		getline(cin, roomColor);									// assign room color

		cout << "Enter length in feet and inches: ";				// prompt user for room length
		cin >> length;												// assign room length

		cout << "Enter width in feet and inches: ";					// prompt user for room width
		cin >> width;												// assign room width

		cout << "Enter height in feet and inches: ";				// prompt user for room height
		cin >> height;												// assign room height

		double sqFt = computeFootage(length, width, height);		// calculate square footage of room
		double pCans = ceil(sqFt / coverage);						// calculate how many total cans of paint are needed

		cout << "\n" << roomName << ":" << endl;										// print room name
		cout << setw(18) << left << "Color: " << roomColor << endl;						// print room color
		cout << setw(18) << left << "Square Footage: " << sqFt << endl;					// print square footage of room
		cout << setw(18) << left << "Actual Cans: " << sqFt / coverage << endl;			// print total amount of cans used
		cout << setw(18) << left << "Purchase Cans: " << pCans << endl;					// print total cans needed to purchase
		cout << setw(18) << left << "Paint Cost: " << "$" << pCans * galCost << endl;	// print cost for room

	}
}

double computeFootage(FeetInches l, FeetInches w, FeetInches h) {
	return (( (double)l * (double)h ) * 2) + (((double)w * (double)h ) * 2);			// return calulated square footage value
}