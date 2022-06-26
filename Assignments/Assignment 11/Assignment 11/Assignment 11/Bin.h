#pragma once
#include <vector>
#include <string>
#include "Package.h"
using namespace std;

class Bin
{	public:
		Bin ();
		Bin (string city);
		string getCity() const;
		vector<Package*> getContents () const;
		double getTotalWeight () const;
		void setCity (string city);
		void setTotalWeight (double w);
		void setContents (vector<Package*> contents);
		void addPackage (Package* p);	// POST: add a package to the bin
	private:
		string city;					// destination city
		vector <Package*> contents;		// packages going to this city
		double totalWeight;				// total weight of bin (pounds)
};

