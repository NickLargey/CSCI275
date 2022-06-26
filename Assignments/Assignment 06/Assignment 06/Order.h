#pragma once
#include <string>

using namespace std;

class Order
{	public:
		// Constructors
		Order();																			// default constructor
		Order(int id, string cName, string addr, string town, int nOrdered, string dDate);	// parameterized constructor
	
		// Getters
		int getID();					// return customer id
		string getCustName();			// return customer name
		string getAddr();				// return customer street address
		string getTown();				// return customer town
		int getNumOrdered();			// return amount customer ordered
		string getdelivDate();			// return delivery date
	
		// Setters						
		void setID(int id);				// set customer id
		void setCustName(string cNum);	// set customer name
		void setAddr(string addr);		// set customer address
		void setTown(string t);			// set customer town
		void setNOrdered(int nOrdered);	// set amount ordered
		void setDDate(string dDate);	// set delivery date

		string toString();				// format order info into toString() function
	private:
		int ID;							// Identification number
		string custName;				// Customer's name
		string stAddr;					// Customer's street address
		string town;					// Customer's town
		int numFridgesOrdered;			// Number of refidgerators ordered
		string delivDate;				// Delivery Date
};


