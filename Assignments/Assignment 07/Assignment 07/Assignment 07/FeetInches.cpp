#include "FeetInches.h"

FeetInches::FeetInches(int f, int i)			// PRE: f and i >= 0
{
	if (f >= 0 && i >= 0) {						// Check if input is greater than 0
		if (i < 12) {							// if inches are less than 12 automatically assign
			feet = f;
			inches = i;
		}
		else {									// else assign then simplify
			feet = f;
			inches = i;
			simplify();
		}
	}
}

void FeetInches::simplify()						// POST: feet and inches set and inches < 12
{	
	int inchToFoot = inches / 12;				// get how many feet are in inches, drop decimal places
	feet = feet + inchToFoot;					// add to current feet
	setFeet(feet);								// set feet
	inches = inches % 12;						// get and assign how many inches are left
	setInches(inches);							// set inches
}

// accessors
int FeetInches::getFeet() const					// getters and setters
{	
	return feet;
}

int FeetInches::getInches() const
{	
	return inches;
}

// modifiers
void FeetInches::setFeet(int f)
{	
	feet = f;
}

void FeetInches::setInches(int i)				// POST: set inches and simplify
{	
	inches = i;									
}

// POST: feet values same, inch values same
bool FeetInches::operator== (const FeetInches& other) const
{	
	int n1 = (feet * 12) + other.inches;		// convert feet from left and add to inches from right of operator
	int n2 = (other.feet * 12) + inches;		// convert feet from right and add to inches from left of operator
	return n1 == n2;							// return equality boolean 
}

bool FeetInches::operator!= (const FeetInches& other) const
{
	return !(*this == other);					// check if not equal
}

// POST: total inches less than other
bool FeetInches::operator< (const FeetInches& other) const
{	
	int f = feet - other.feet;					// subtract right feet from left of operator feet
	int i = inches - other.inches;				// subtract right inches from left of operator inches
	return (f < 0 || i < 0);					// return boolean of if either are less than zero
}

bool FeetInches::operator<= (const FeetInches& other) const
{	
	int f = feet - other.feet;					// subtract right feet from left of operator feet
	int i = inches - other.inches;				// subtract right inches from left of operator inches
	return (f <= 0 || i <= 0);					// return boolean of if either are less than or equal to zero
}

// POST: total inches more than other
bool FeetInches::operator> (const FeetInches& other) const
{
	int f = feet - other.feet;					// subtract right feet from left of operator feet
	int i = inches - other.inches;				// subtract right inches from left of operator inches
	return (f>0 || i>0);						// return boolean of if either are greater than zero
}

bool FeetInches::operator>= (const FeetInches& other) const
{	
	int f = feet - other.feet;					// subtract right feet from left of operator feet
	int i = inches - other.inches;				// subtract right inches from left of operator inches
	return (f >= 0 || i >= 0);					// return boolean of if either are greater than or equal to zero
}


// POST: add feet and inches from other and simplify
FeetInches FeetInches::operator+ (const FeetInches& other) const
{	
	int f = feet + other.feet;					// add feet from left and right of operator
	int i = inches + other.inches;				// add inches from left and right of operator
	return FeetInches(f, i);					// return new FeetInches object and simplify if need be 
}

FeetInches FeetInches::operator++ ()			// POST: add 1 to inches (prefix)
{	
	inches = inches + 1;						// increment inches
	return *this;								// return incremented value
}

FeetInches FeetInches::operator++ (int)			// POST: add 1 to inches (postfix)
{	
	FeetInches temp(feet, inches);				// create new temp object from current object
	inches = inches + 1;						// increment current object
	return temp;								// return temp object
}


FeetInches::operator int() const						// POST: return total inches
{	
	return (int)((feet * 12) + inches);					// convert feet to inches, add to inches and return value
}

FeetInches::operator double() const						// POST: return total in feet
{	
	return (double)feet + ((double)inches / 12);		// add feet to converted inches and return value
}

// POST: display feet inches
ostream& operator<< (ostream& out, const FeetInches& object)
{	
	out << object.getFeet() << " " << object.getInches(); // create new formatted string 
	return out;											  // return string
}

// POST: read feet inches
istream& operator>> (istream& in, FeetInches& object)
{	
	int f, i;												// init feet and inch variables
	in >> f >> i;											// read in input
	FeetInches temp(f, i);									// create new FeetInches object from input 
	object.setFeet(temp.getFeet());							// set passed argument's feet 
	object.setInches(temp.getInches());						// set passed argument's inches
	return in;												// return input
}
