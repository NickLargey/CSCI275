#include "Order.h"
#include <iostream>
#include <sstream>
using namespace std;
// constructors
Order::Order() {
	ID = 0;
	custName = "";
	stAddr = "";
	town = "";
	numFridgesOrdered = 0;
	delivDate = "Pending";
}

Order::Order(int id, string cName, string addr, string t, int nOrdered, string dDate = "Pending") {
	ID = id;
	custName = cName;
	stAddr = addr;
	town = t;
	numFridgesOrdered = nOrdered;
	delivDate = dDate;
}

// getters
int Order::getID() {
	return ID;
}

string Order::getCustName() {
	return custName;
}

string Order::getAddr() {
	return stAddr;
}
string Order::getTown() {
	return town;
}

int Order::getNumOrdered() {
	return numFridgesOrdered;
}

string Order::getdelivDate() {
	return delivDate;
}

// setters
void Order::setID(int id) {
	ID = id;
}
void Order::setCustName(string cName) {
	custName = cName;
}
void Order::setAddr(string addr) {
	stAddr = addr;
}
void Order::setTown(string t) {
	town = t;
}
void Order::setNOrdered(int nOrdered) {
	numFridgesOrdered = nOrdered;
}
void Order::setDDate(string dDate) {
	delivDate = dDate;
}

string Order::toString() {
	stringstream ss;		// create string stream to format output
	ss << Order::getID() << " " << Order::getCustName() << " " << Order::getAddr() << " " << Order::getTown() << " " << Order::getNumOrdered() << " " << Order::getdelivDate() << endl;
	string oStr = ss.str(); // convert to string
	return oStr;			// return string
}