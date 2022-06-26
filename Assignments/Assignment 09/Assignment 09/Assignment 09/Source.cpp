#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Bag.h"

int main()
{
	ifstream storeOne;						// init stream for first file
	ifstream storeTwo;						// init stream for second file
	string fOne;							// init first variable for user to enter input file name
	string fTwo;							// init second variable for user to enter input file name
	string line;							// init variable to read lines of files
	vector <string> employees;			// init vector for employee names to be stored
	Bag <string> empBag;					// init bag object for employee names to be stored
	
	
	cout << "Please enter the text file of the first store: ";
	cin >> fOne;							// ask user for first file name and store in fOne 
	storeOne.open(fOne);					// open file
	if (storeOne.fail()) {					// check if first file exists or is corrupted
		cout << fOne << " failed to open" << endl;
		cout << "Please rerun program" << endl;
		return 1;							// exit if file doesn't work
	}

	cout << "Please enter the text file of the second store: ";
	cin >> fTwo;							// ask user for first file name and store in fTwo 
	storeTwo.open(fTwo);					// open file
	if (storeTwo.fail()) {					// check if second file exists or is corrupted
		cout << fTwo << " failed to open" << endl;
		cout << "Please rerun program" << endl;
		return 1;							// exit if file doesn't work
	}
	getline(storeOne, line);				// priming read of first line of first file
	while (!storeOne.fail()) {				// loop until end of file
		if (find(employees.begin(), employees.end(), line) != employees.end()) { // check if current name is in the employees list already
			cout << line << "'s name is already in the list" << endl;  // alert user if so
		}
		else {
			employees.push_back(line);		// add name to employees vector
			empBag.insert(line);			// add name to employee bag
		}
		getline(storeOne, line);			// get next line
	}

	getline(storeTwo, line);				// priming read of first line of second file
	while (!storeTwo.fail()) {				// loop until end of file
		if (find(employees.begin(), employees.end(), line) != employees.end()) {  // check if current name is in the employees list already
			cout << line << "'s name is already in the list" << endl;  // alert user if so
		}
		else {
			employees.push_back(line);		// add name to employees vector
			empBag.insert(line);			// add name to employee bag
		}
		getline(storeTwo, line);			// get next line
	}

	sort(employees.begin(), employees.end());  // sort names in employee vector


	cout << setw(15) << left << "\nName" << "Giftee" << endl;  // print header
	for (string i : employees) {			// loop through vector of employees
		string randName;					// init variable for random name
		do {
			randName = empBag.remove();		// assign random name 
			if (i == randName) {			// check if random name chosen is same as current vector name
				empBag.insert(randName);	// if so add it back into the bag and chose again
				//cout << i << " inserted back into bag." << endl;  // alert user (OPTIONAL)
			}
		} while (i == randName);			// continue looping if names are equal	
		cout << setw(15) << i << randName << endl;  // print list of secret santa matches
	}	
	
	return 0;								// exit program gracefully
}