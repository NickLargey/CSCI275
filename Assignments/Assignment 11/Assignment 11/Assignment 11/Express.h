#pragma once
#include "Package.h"
using namespace std;

// This concrete class models an express package
// It adds a new data member for the type of express (Two Day or Overnight)
// It must implement cost
class Express : public Package
{ public:
	Express();
	Express(string id, double weight, string type);
	string getType() const;
	void setType(string t);
	string toString() const;	// POST: return string rep of express pkg
	double cost() const;		// POST: return cost of package
 private:
	string type;				// type of express: Two Day/Overnight
};

