#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Bin.h"
#include "Express.h"
#include "Package.h"
#include "Priority.h"

using namespace std;

int main() {
	vector<Bin*> bins;									// init vector of Bin pointers
	ifstream fin;										// init file in variable
	string line;										// init str varible for getline()
	string id;											// init str variable for id
	string type;										// init str variable for package type
	string dest;										// init str variable for destination
	double weight;										// init double variable for weight to be cast from getline()


	fin.open("packages.txt");							// open package file
	if (fin.fail()) {									// check if file exists or is corrupted
		cout << "File failed to open" << endl;;
		return 1;
	}

	getline(fin, line);									// priming read
	while (!fin.fail()) {
		id = line;										// assign current id
		getline(fin, line);								// read and assign destination
		dest = line;
		getline(fin, line);								// read and assign weight
		weight = stod(line);
		getline(fin, line);								// read and assign shipment type
		type = line;	

		auto it = find_if(bins.begin(), bins.end(), [&dest, &weight](Bin* obj)				// iterate over current bins vector to find if there is a destination bin
			{return obj->getCity() == dest && (obj->getTotalWeight() + weight) < 50; });	// with room left for current package (modified from https://stackoverflow.com/questions/15517991/search-a-vector-of-objects-by-object-attribute)

		if (it != bins.end()) {								// if bin is found with room
			auto b = distance(bins.begin(), it);			// get index of bin
			if (type != "Priority") {						// if type is not priority add express package to bin
				Express* e = new Express(id, weight, type);
				bins[b]->addPackage(e);
			}
			else {											// else add priotity package to bin
				Priority* p = new Priority(id, weight);
				bins[b]->addPackage(p);
			}
		}
		else {												// if no bin is found with room
			if (type != "Priority") {						// if type is not priority, add new bin for dest, add express package to bin and add to bins vec
				Bin* newBin = new Bin(dest);
				Express* e = new Express(id, weight, type);
				newBin->addPackage(e);
				bins.push_back(newBin);
			}
			else {											// if type is priority, add new bin for dest, add priority package to bin and add to bins vec
				Bin* newBin = new Bin(dest);
				Priority* p = new Priority(id, weight);
				newBin->addPackage(p);
				bins.push_back(newBin);
			}
		}	
		getline(fin, line);									// get next package id
	}

	for (int i = 0; i < bins.size(); i++) {					// loop over bins vec 
		cout << "Bin #" << i+1 << endl;						// print current bin header
		cout << left << setw(15) << "Destination: " << bins[i]->getCity() << endl;		// print current bin header continued
		cout << left << setw(15) << "ID" << setw(10) << "Weight" << "Cost" << endl;		// print current bin header continued
		vector<Package*> packList = bins[i]->getContents();		// create new vector containing bin contents to read over
		cout << fixed << showpoint << setprecision(2);			// format cout
		for (int j = 0; j < packList.size(); j++) {				// loop over current bin contents
			Express* dcp = dynamic_cast<Express*>(packList[j]);	// downcast to Express type to access getter functions
			if (dcp != nullptr) {								// if able to downcast print formatted string
				cout << left << setw(15) << dcp->getIdentification() << setw(10) << dcp->getWeight() << setw(10) << dcp->cost() << dcp->getType() << endl;
			}
			else {												// if not able to downcase, print formatted string
				cout << left << setw(15) << packList[j]->getIdentification() << setw(10) << packList[j]->getWeight() << setw(10) << packList[j]->cost() << endl;
			}
			
		}
		cout << "Bin weight: " << bins[i]->getTotalWeight() << endl;	//output total bin weight
		cout << endl;													// make it a little prettier 
	}
}
