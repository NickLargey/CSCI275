#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

// POST: last name (ex. Nolan), street name (ex. Main St.)
//		 town name (ex. Alfred), worth string (ex. 132566.75)
//       birthdate (ex. 01/13/1948) are filled with values from
//       next line of input file if possible
void input(ifstream& fin, string& lastName, string& streetName, string& townName,
	string& worthString, string& birthdate);

//PRE: extract townName fron input()
//POST: return new tax rate for town
double getTaxRate(string townName);

//PRE: extract worth and taxRate from input()
//POST: report senior payment schedule to output file
void seniorSchedule(ofstream& fout, double worth, double taxRate);  //

//PRE: extract worth and taxRate from input()
//POST: report regular payment schedule to output file
void regularSchedule(ofstream& fout, double worth, double taxRate);  // 

int main() {
	// initialize needed variables
	ifstream fin;
	ofstream fout;
	string lastName;
	string streetName;
	string townName;
	string worthString;
	string birthdate;
	double taxRate;
	double worth;
	int age;

	// open input file and output file
	fin.open("records.txt");
	fout.open("letters.txt");
	// format out put numbers
	fout << fixed << left << setprecision(2) << showpoint;

	// priming read
	input(fin, lastName, streetName, townName, worthString, birthdate);
	while (!fin.fail()) {
		// create double to calculate taxes from property worth
		worth = stod(worthString);
		// calculate tax rate
		taxRate = getTaxRate(townName);
		// calculate age of home owner
		age = 2022 - stoi(birthdate.substr(6));
		
		// begin output text block
		fout << "Dear Resident " << lastName << ":" << endl;
		fout << "In 2021 your property at " << streetName << " was assessed at $" << worthString << endl;
		fout << "The tax rate will be increasing to " << taxRate * 100 << "%" << " for 2022." << endl;
		// decide tax schedule based on age
		if (age >= 65) {
			fout << "Given your age of " << age << ", you are elegible for the senior payment schedule:" << endl;
			seniorSchedule(fout, worth, taxRate);
		} else {
			regularSchedule(fout, worth, taxRate);
		}

		fout << "Sincerely, the " << townName << " Town office." << endl;
		fout << endl;

		// call input to get next set of data
		input(fin, lastName, streetName, townName, worthString, birthdate);
	}

	// close input and output files
	fin.close();
	fout.close();

	return 0;
}

void input(ifstream& fin, string& lastName, string& streetName, string& townName,
	string& worthString, string& birthdate) {
	// create variable to store current line of input file
	string line;
	// get line from input file
	getline(fin, line);
	// create string stream to catch last name listed
	istringstream linestring(line);
	// assign name until last name is reached
	while (!linestring.fail()) {
		linestring >> lastName;
		linestring >> ws;
	}

	getline(fin, line);
	// find index of first white space char after house number
	size_t street = line.find_first_of(' ');
	// assign street name excluding house number
	streetName = line.substr(street + 1);
		
	getline(fin, line);
	// find index of ',' seperating town name from state and zip
	size_t town = line.find_first_of(',');
	// assign town name excluding state and zip
	townName = line.substr(0, town);

	// assign property worth
	getline(fin, line);
	worthString = line;

	// assign DOB
	getline(fin, line);
	birthdate = line;
}

double getTaxRate(string townName) {
	if (townName == "Alfred") {
		return 0.035;
	}
	
	if (townName == "Sanford") {
		return 0.03;
	}
	
	if (townName == "Lyman") {
		return 0.038;
	}

}

void seniorSchedule(ofstream& fout, double worth, double taxRate) {
	double taxesDue;

	// calculate taxes due
	taxesDue = (worth * taxRate) / 4;
	// begin output text block
	fout << endl;
	fout << setw(10) << "Due" << "Amount" << endl;
	fout << setw(10) << "Mar 15" << "$" << taxesDue << endl;
	fout << setw(10) << "Jun 15" << "$" << taxesDue << endl;
	fout << setw(10) << "Sep 15" << "$" << taxesDue << endl;
	fout << setw(10) << "Dec 15" << "$" << taxesDue << endl;
	fout << endl;
}

void regularSchedule(ofstream& fout, double worth, double taxRate){
	double taxesDue;

	// calculate taxes due
	taxesDue = (worth * taxRate) / 2;
	// begin output text block
	fout << endl;
	fout << fixed << left << setprecision(2) << showpoint;
	fout << setw(10) << "Due" << "Amount" << endl;
	fout << setw(10) << "Jun 15" << "$" << taxesDue << endl;
	fout << setw(10) << "Dec 15" << "$" << taxesDue << endl;
	fout << endl;
}