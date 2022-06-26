#pragma once
#include "Package.h"
using namespace std;

// This concrete class models a priority package
// It does not add any new data members
// It must implement cost
class Priority : public Package
{	public:
		Priority();
		Priority (string id, double weight);
		double cost () const;		// POST: return cost of package
};



