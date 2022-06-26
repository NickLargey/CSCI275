#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Customer.h"

using namespace std;

int main() {
	// create "Customer" object
	Customer customer;
	// reserve mem space to read in file
	ifstream inFile;

	// if file is not found, echo message to user and exit 
	inFile.open("customers.txt");
	if (inFile.fail())
	{
		cout << "File failed to open";
		return 1;
	}

	// reserve mem space for balance double
	double d;
	// reserve mem space for line to be read in from .txt file
	string s;

	// read in first line to file buffer
	getline(inFile, s);
	// loop over file until EOF is reached 
	while (!inFile.fail())
	{
		// Set customer ID
		customer.setID(s);

		// advance line buffer and set customer name
		getline(inFile, s);
		customer.setName(s);

		// advance line buffer, convert string to double for future math and set customer balance
		getline(inFile, s);
		d = stod(s);
		customer.setBalance(d);

		// advance line buffer to transaction history
		getline(inFile, s);
		
		// begin printing customer data block to console
		// print customer name
		cout << "Customer: " << customer.getName() << endl;
		// replace first 3 digits of customer ID with 'XXX' and append the last 3 digits
		cout << "Identification: XXX" << customer.getID().substr(3,6) << endl;
		// print initial balance
		cout << "Balance: " << customer.getBalance() << endl;
		// format and print header for transaction history
		cout << showpoint << setprecision(2) << fixed << left;
		cout << setw(9) << "Date" << setw(15) << "Transaction" << setw(12) << "Amount" << "Balance" << endl;

		// loop over transaction history, breaking when the string 'xxx' has been read in
		while (s != "xxx") {
			//set variable to current balance for future math
			double bal = customer.getBalance();
			// set variable if transaction is a deposit or withdrawl
			string transact = s.at(9) == 'W'? "Withdrawl" : "Deposit";
			// convert substring to double and set variable for transaction amount
			double transactAmt = stod(s.substr(11));
			// perform addition or subtraction on customer balance depending on deposit or withdrawl
			bal = transact == "Withdrawl" ? customer.withdraw(transactAmt) : customer.deposit(transactAmt);

			// print transaction history line
			cout << setw(9) << s.substr(0,8) << setw(15) << transact << setw(12) << transactAmt << bal << endl;
			// advance line buffer
			getline(inFile, s);
		}

		getline(inFile, s);
		cout <<"-----------------------------------------------------" << endl;


	}

	// close file that was read in
	inFile.close();
	// exit program
	return 0;
}