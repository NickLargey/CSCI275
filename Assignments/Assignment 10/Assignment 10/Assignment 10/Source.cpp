#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "TextBook.h"

using namespace std;

int main()
{
	ifstream fin;									// init file input variable
	string major;									// init variable to store major
	string line;									// init line variable to store lines read in
	int mCount = 0;									// init counter for textbooks required for major
	
	fin.open("books.txt");							// open order file
	if (fin.fail()) {								// check if file exists or is corrupted
		cout << "File failed to open" << endl;;
		return 1;
	}

	cout << "Enter your major: ";					// prompt user for major input
	cin >> major;									// store input

	getline(fin, line);								// priming read of fin
	while (!fin.fail()){							// loop over file until EOF
		if (line == "Textbook") {					// if line == Textbook create TextBook object
			TextBook t;								// init new TextBook object   
			getline(fin, line);						// read in next line
			t.setTitle(line);						// set title to line

			getline(fin, line);						// read in next line
			t.setAuthor(line);						// set author to line

			getline(fin, line);						// read in next line
			t.setISBN(line);						// set ISBN to line or "missing" if invalid

			getline(fin, line);						// read in next line
			t.setCourse(line);						// set course to line
			
			if (line.substr(0, 3) == major) {			// if major == first three char's of course
				t.display(cout);						// call TextBook class display function
				cout << "<-- For your major" << endl;	// add major indicator 
				mCount++;								// increase major counter
			}
			else {									// else call TextBook class display function as is
				t.display(cout);
				cout << endl;
			}
		}
		else {
			Book b;									// init new Book object
			getline(fin, line);						// read in next line
			b.setTitle(line);						// set title to line

			getline(fin, line);						// read in next line
			b.setAuthor(line);						// set author to line

			getline(fin, line);						// read in next line
			b.setISBN(line);						// set ISBN to line or "missing" if invalid

			cout << left << setw(15) << "Tradebook";	// print genaric, non-course label
			b.display(cout);							// call Book class display function
			cout << endl;
		}
		getline(fin, line);							// read in next line
	}

	cout << "\nNumber of books for the " << major.substr(0, 3) << " major: " << mCount << endl;		// report amount of texts needed for major

	return 0;
}