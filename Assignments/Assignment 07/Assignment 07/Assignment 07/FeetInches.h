#pragma once
#include <iostream>
using namespace std;

class FeetInches
{	private:
		int feet;								// feet 0..
		int inches;								// inches 0..11
		void simplify();						// POST: feet and inches set and inches < 12
	public:
		FeetInches (int f = 0, int i = 0);		// PRE: f and i >= 0
												// POST: set feet to f and inches to i and simplify
		// accessors and modifiers
		int getFeet() const;
		int getInches() const;
		void setFeet (int f);
		void setInches (int i);					// POST: set inches and simplify

		// relational operators
		bool operator== (const FeetInches& other) const;	// POST: feet values same, inch values same
		bool operator!= (const FeetInches& other) const;
		bool operator< (const FeetInches& other) const;		// POST: total inches less than other
		bool operator<= (const FeetInches& other) const;
		bool operator> (const FeetInches& other) const;		// POST: total inches more than other
		bool operator>= (const FeetInches& other) const;

		// math operator
		// POST: add feet and inches from other and simplify
		FeetInches operator+ (const FeetInches& other) const;	
				
		// increment and decrement operators
		FeetInches operator++ ();					// POST: add 1 to inches (prefix)
		FeetInches operator++ (int);				// POST: add 1 to inches (postfix)
		
		operator int () const;						// POST: return total inches (2 feet, 1 inch --> 25)
		operator double ( ) const;					// POST: return total inches in units of feet 
													//		 (2 feet, 6 inches --> 2.5)
	};

	//IO operators
	ostream& operator<< (ostream&, const FeetInches& object);	// POST: display feet inches
	istream& operator>> (istream&, FeetInches& object);			// POST: reads feet inches

