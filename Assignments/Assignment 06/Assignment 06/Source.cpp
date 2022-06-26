#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "IntStack.h"
#include "Order.h"

using namespace std;

// POST: return the index of the order id or -1 if not found
int search(Order* orders, int size, int orderID);

// POST: display the delivery schedule for the truck in LIFO order
void reportTruck(IntStack truck, Order* orders, int size);

// POST: display all pending orders
void reportPending(Order* orders, int size);

int main() {
	Order* orders = new Order[50];		// init new Order dynamic array
	Order* pOrders = new Order[10];		// init new dynamic Order array for pending orders
	Order currOrder;					// init Order object to put into *orders
	IntStack portland = IntStack(6);	// init IntStack for portland deliveries
	IntStack lewiston = IntStack(6);	// init IntStack for lewiston deliveries
	IntStack bangor = IntStack(6);		// init IntStack for bangor deliveries
	ifstream fin;						// init file stream variable
	string line;						// itit string to store getline
	string street;						// init string to store street from getline
	string town;						// init string to store city from getline	
	string date;						// init string to store date header
	int nOrd;							// init int to store amount ordered from getline
	int id;								// init string to store customer id from getline
	int p = 0;							// init counter for amount of refridgerators on truck for portland truck
	int l = 0;							// init counter for amount of refridgerators on truck for lewiston truck
	int b = 0;							// init counter for amount of refridgerators on truck for bangor truck
	int pIndex = 0;						// init counter for pending orders array insertions
	int i = 0;							// init counter for total number of orders 

	fin.open("TodayOrders.txt");		// open order file
	if (fin.fail()) {					// check if file exists or is corrupted
		cout << "File failed to open" << endl;;
		return 1;
	}

	getline(fin, date);					// read in and store date header

	getline(fin, line);					// priming read
	while (!fin.fail()) {
		id = stoi(line);				// convert id string to int 
		currOrder.setID(id);			// store id int in currOrder object 

		getline(fin, line);				// read in next line and set customer name
		currOrder.setCustName(line);

		getline(fin, street);			// read in next line and set street address
		currOrder.setAddr(street);
		getline(fin, town);				// read in next line and set town
		currOrder.setTown(town);

		getline(fin, line);				// read in next line, convert from string to int and set amount ordered
		nOrd = stoi(line);
		currOrder.setNOrdered(nOrd);

		orders[i] = currOrder;			// push currOrder object to orders array

		getline(fin, line);				// read in next line
		i++;							// increment orders counter
	}
	
	
	for (int k = 0; k < i; k++) {								// loop over each index in order array and assign to correct truck
		cout << orders[k].toString();							// print out each order in toString() format
		if (orders[k].getTown() == "Portland") {				// check if order town is Portland
			p += orders[k].getNumOrdered();						// increment amount of orders on truck
			if (p <= 6) { portland.push(orders[k].getID()); }	// if truck has room, push order id to stack
			else { 
				pOrders[pIndex] = orders[k];					// else push order id to pending orders array
				pIndex++;										// increment pending order index counter
			}
		}
		else if (orders[k].getTown() == "Lewiston") {			// check if order town is Portland
			l += orders[k].getNumOrdered();						// increment amount of orders on truck
			if (l <= 6) { lewiston.push(orders[k].getID()); }	// if truck has room, push order id to stack
			else { 
				pOrders[pIndex] = orders[k];					// else push order id to pending orders array
				pIndex++;										// increment pending order index counter
			}
		}
		else if (orders[k].getTown() == "Bangor") {				// check if order town is Portland
			b += orders[k].getNumOrdered();						// increment amount of orders on truck
			if (b <= 6) { bangor.push(orders[k].getID()); }		// if truck has room, push order id to stack
			else { 
				pOrders[pIndex] = orders[k];					// else push order id to pending orders array
				pIndex++;										// increment pending order index counter
			}
		}
		else {
			cout << orders[k].getTown() << " :Town not in delivery route" << endl;		// if town isn't Portland Lewiston or Bangor, alert user town isn't in delivery range
		}
		
	}

	cout << "\n\nDelivery Schedule for " << date << endl;		// print delivery header
	cout << "\nPortland Deliveries:" << endl;					// print portland header
	reportTruck(portland, orders, i);							// call reportTruck() to get deliveries
	cout << "\nLewiston Deliveries:" << endl;					// print lewiston header
	reportTruck(lewiston, orders, i);							// call reportTruck() to get deliveries
	cout << "\nBangor Deliveries:" << endl;						// print bangor header
	reportTruck(bangor, orders, i);								// call reportTruck() to get deliveries
	cout << "\nPending Orders:" << endl;						// print pending orders header
	reportPending(pOrders, pIndex);								// call reportPending() to get pending orders

	delete [] orders;											// free orders memory
	delete[] pOrders;											// free pOrders memory
	
	return 0;
}

// POST: return the index of the order id or -1 if not found
int search( Order* orders, int size, int orderID) {
	for (int i = 0; i < size; i++) {							// loop over orders in passed dynamic array
		if (orders[i].getID() == orderID) {						// check if current order'd id is the one being searched
			return i;											// return if matched
		}
	}
	return -1;													// return -1 if not found
}

// POST: display the delivery schedule for the truck in LIFO order
void reportTruck(IntStack truck, Order* orders, int size) {
	while (!truck.isEmpty()) {									// loop over truck stack 
		int index;												// create index variable to print order info
		index = search(orders, size, truck.pop());				// call search() to assign index
		cout << left << setw(10) << orders[index].getID() << setw(25) << orders[index].getCustName() << setw(25) << orders[index].getAddr() << orders[index].getNumOrdered() << endl;
	}
}

// POST: display all pending orders
void reportPending(Order* orders, int size) {
	for (int i = 0; i < size; i++) {							// loop over all elements in pending orders array and report
		cout << left << setw(10) << orders[i].getID() << setw(25) << orders[i].getCustName() << setw(25) << orders[i].getAddr() << setw(10) << orders[i].getNumOrdered() << orders[i].getTown() << endl;
	}
}
