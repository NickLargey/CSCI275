#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;
void swap(int index, vector<string>& a, vector<string>& b);	// POST: swaps element at index between vectors
void printShore(vector<string>& a, vector<string>& b);		// POST: print contents of both north and south shore vectors

int main() {
	int farmer = 0;							// init variable for farmer setting 0 for south, 1 for north
	string choice;							// init string for user input
	vector<string> northShore;				// init north shore vector
	vector<string> southShore;				// init south shore vector

	southShore.push_back("fox");			// add fox to south shore
	southShore.push_back("chicken");		// add chicken to south shore
	southShore.push_back("grain");			// add grain to south shore

	while (1) {
		cout << "Enter the item to transport (fox, chicken, grain, none): ";	// prompt user
		cin >> choice;															// get user choice

		try {	
			if (farmer == 0) {													// if farmer is on south shore
				vector<string>::iterator it;									// init iterator to find user choice index
				it = find(southShore.begin(), southShore.end(), choice);		// search for index
				if (choice == "none") {											// if choice is none
					cout << "Farmer location: North bank" << endl;				// print updated farmer location
					printShore(southShore, northShore);							// call print function
					farmer = 1;													// update farmer location
				}		
				else if (it == southShore.end()) {								// if choice is not found in vector
					throw choice;												// throw exception
				}
				else {															// else choice was found
					cout << "Farmer location: North bank" << endl;				// print updated farmer location
					int i = it - southShore.begin();							// init int index of choice 
					swap(i, southShore, northShore);							// call swap function 
					printShore(southShore, northShore);							// call print function
					farmer = 1;													// update farmer location
				}
			}

			else if (farmer == 1) {												// if farmer is on north shore
				vector<string>::iterator it;									// init iterator to find user choice index
				it = find(northShore.begin(), northShore.end(), choice);		// search for index
				if (choice == "none") {											// if choice is none
					cout << "Farmer location: South bank" << endl;				// print updated farmer location
					printShore(southShore, northShore);							// call print function
					farmer = 0;													// update farmer location
				}
				else if (it == northShore.end()) {								// if choice is not found in vector
					throw choice;												// throw exception
				}
				else {															// else choice was found
					cout << "Farmer location: South bank" << endl;				// print updated farmer location
					int i = it - northShore.begin();							// init int index of choice
					swap(i, northShore, southShore);							// call swap function
					printShore(southShore, northShore);							// call print function
					farmer = 0;													// update farmer location
				}
			}

		}
		catch (string e)														// catch statement
		{
			cout << "Item is not found on bank." << endl;						// prompt user that their choice was not found
		}

		if (northShore.size() == 2 || southShore.size() == 2) {					// check to see if the size of either vector is 2
			// check if fox and chicken are alone on the north shore
			if (find(northShore.begin(), northShore.end(), "fox") != northShore.end() && find(northShore.begin(), northShore.end(), "chicken") != northShore.end() && farmer != 1) {	
				cout << "Game is over.\n" << "You lost :(" << endl;		// if true prompt user that they have lost
				return 0;												// exit game
			}
			// check if chicken and grain are alone on the north shore
			if (find(northShore.begin(), northShore.end(), "grain") != northShore.end() && find(northShore.begin(), northShore.end(), "chicken") != northShore.end() && farmer != 1) {	
				cout << "Game is over.\n" << "You lost :(" << endl;		// if true prompt user that they have lost
				return 0;												// exit game
			}
			// check if fox and chicken are alone on south shore
			if (find(southShore.begin(), southShore.end(), "fox") != southShore.end() && find(southShore.begin(), southShore.end(), "chicken") != southShore.end() && farmer != 0) {	
				cout << "Game is over.\n" << "You lost :(" << endl;		// if true prompt user that they have lost
				return 0;												// exit game
			}
			// check if chicken and grain are alone on south shore
			if (find(southShore.begin(), southShore.end(), "grain") != southShore.end() && find(southShore.begin(), southShore.end(), "chicken") != southShore.end() && farmer != 0) {	
				cout << "Game is over.\n" << "You lost :(" << endl;		// if true prompt user that they have lost
				return 0;												// exit game
			}
		}
		
		if (northShore.size() == 3) {					// check if all items have made it to the north shore
			cout << "Congrats! You Won!" << endl;		// prompt user that they have won!
			return 0;									// exit game
		}	
	}

	return 0;		// if while loops exits for unknown reason exit program
}

// POST: swaps element at index between vectors
void swap(int index, vector<string>& a, vector<string>& b){		
	string s = a.at(index);		// init and assign string for chosen index
	a.erase(a.begin()+index);	// remove element from first vector
	b.push_back(s);				// add element to second vector
}

// POST: print contents of both north and south shore vectors
void printShore(vector<string>& south, vector<string>& north) {	
	cout << "South Bank contains: ";	// print header
	for (string s : south) {			// loop over south shore vector printing each element
		cout << s << " ";
	}
	cout << "\nNorth Bank contains: ";	// print header	
	for (string n : north) {			// loop over north shore vector printing each element
		cout << n << " ";
	}
	cout << "\n" << endl;
}