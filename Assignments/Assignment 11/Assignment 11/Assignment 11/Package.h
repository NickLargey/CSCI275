#pragma once
#include <string>
using namespace std;

// This abstract class models a general package
// It uses dynamic binding on toString and cost 
// It includes pure virtual function cost which must be implemented in derived classes
class Package
{	public:
		Package();
		Package (string i, double w);
		string getIdentification() const;
		double getWeight() const;
		void setIdentification(string id);
		void setWeight (double w);
		virtual string toString ( ) const;	// POST: return string representation
		virtual double cost () const = 0;	// POST: return cost of package
	private:
		string identification;				// identification number			
		double weight;						// weight in pounds
};


