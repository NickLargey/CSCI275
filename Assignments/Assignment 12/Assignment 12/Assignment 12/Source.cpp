#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

// function prototypes
void display(map<string, vector<string>> m);
string validate( map<string, vector<string>> m );
map<string, vector<string>> changePW(map<string, vector<string>> m);
map<string, vector<string>> buildMap();

int main() {
	map<string, vector<string>> userMap;	// init empty map
	string user;							// init user string
	userMap = buildMap();					// fill user map
	
	if (userMap.size() > 0) {				// if text file isn't empty or fails to open
		userMap = changePW(userMap);		// begin process to change user password
		display(userMap);					// display map
	}
	else {									// if text file is empty or fails to open
		return 1;							// return error code
	}
	
	return 0;								// return success code if processes all pass
}

map<string, vector<string>> changePW(map<string, vector<string>> m) {
	bool pass = false;						// init final test bool
	bool lower = false;						// init bool for lowercase char
	bool upper = false;						// init bool for uppercase char
	bool special = false;					// init bool for special char
	string newPass;							// init string for new password
	string user = validate(m);				// get user
	vector<string> data;					// init empty vector for user data
	set<char> specialChars = { '_', '%', '#', '!', '$' };	// init set of special chars
	set<char> lowercase;									// init empty set for lowercase chars 
	set<char> uppercase;									// init empty set for uppercase chars
	for (char c = 'A'; c <= 'Z'; c++) {
		uppercase.insert(c);				// fill uppercase set
	}
	for (char c = 'a'; c <= 'z'; c++) {
		lowercase.insert(c);				// fill lowercase set
	}
	cout << "Enter new password: ";			// prompt user for new password
	cin >> newPass;							// read in password
	do {
		for (int i = 0; i < newPass.length(); i++) {		// loop over chars in pw to check if all cases are met
			if (specialChars.find(newPass[i]) != specialChars.end()) {
				special = true;								// if char is special char filp special bool			
			}
			else if (lowercase.find(newPass[i]) != lowercase.end()) {
				lower = true;								// if char is lowercase flip lower bool
			}
			else if (uppercase.find(newPass[i]) != uppercase.end()) {
				upper = true;								// if char is uppercase flip upper bool
			}
		}
		if (special == true && lower == true && upper == true && newPass.length() >= 6) {
			pass = true;									// if all tests pass and new pw is 6 or more chars flip passing bool
		}
		else {
			cout << newPass << " not valid" << endl;		// if passing bool if false redo password choice
			cout << "Enter new password: ";					// prompt user for new password
			cin >> newPass;									// read in password
		}
	} while (!pass);										// while passing bool is false
	
	data = m[user];					// get data from chosen user
	data.push_back(newPass);		// add passing new password
	m[user] = data;					// update map
	cout << "Password successfully changed" << endl;

	return m;						// return updated map
}
string validate( map<string, vector<string>> m ) {
	bool found = false;							// init found bool
	string user;								// init empty user string
	string pw;									// init empty password string
	vector<string> passwords;					// init empty passwords vector
	map<string, vector<string>>::iterator it;	// init empty iterator to find user
	
	cout << "Enter user ID: ";					// prompt user for user ID
	cin >> user;								// read in user
	it = m.find(user);
	while (!found) {							// continue looping while user is not in map
		if (it != m.end()) {					// if user is found
			passwords = m[user];				// get vector of current and prev passwords
			cout << "Enter current password: ";	// prompt user
			cin >> pw;							// read in current password
			if (pw == passwords.back()) {		// if password is equal to the most recient password in set
				found = true;					// flip found bool
				return user;					// return user string
			}
			else {
				cout << "Invalid current password" << endl; // alert user if password is incorrect
			}
		}
		else {									// if user isn't valid repeat prompt
			cout << "User not found" << endl;	// alert user
			cout << "Enter user ID: ";			// prompt user
			cin >> user;						// read in user
			it = m.find(user);					// update iterator	
		}
	}
}

map<string,vector<string>> buildMap() {
	ifstream fin;										// init file in variable
	string line;										// init str varible for getline()
	map<string, vector<string>> map;					// init new map

	fin.open("users.txt");								// open  file
	if (fin.fail()) {									// check if file exists or is corrupted
		cout << "File failed to open" << endl;;
		exit;
	}
	getline(fin, line);									// priming read
	while (!fin.fail()) {
		istringstream ss(line);							// init string stream
		string username;								// init string for username 
		string pw;										// init string for password
		vector<string> passwords;						// init vector for all passwords

		ss >> username;									// read in first entry as username
		ss >> pw;										// priming read for passwords
		while (!ss.fail()) {
			passwords.push_back(pw);					// add password to vector
			ss >> pw;									// read next password
		}
		map.insert(pair<string, vector<string>>(username, passwords)); // insert username and passwords pair to map
		getline(fin, line);								// read in next line
	}
	fin.close();										// close text file
	return map;											// return map
}

void display(map<string, vector<string>> m) {
	vector<string> data;								// init empty vector for data
	cout << "\nUser map holds " << m.size() << " accounts\n" << endl;

	for (pair<string, vector<string>> p : m) {			// loop over map 
		cout << p.first << "\t";						// print username
		data = p.second;								// assign passwords vector to data
		for (string d : data) {							// loop over password data
			cout << d << " ";							// print out password
		}
		cout << endl;
	}
}