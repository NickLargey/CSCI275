#include "Book.h"

Book::Book() {								// POST: empty book
	title = "";
	author = "";
	ISBN = "";
}									
Book::Book(string t, string a, string i) {	// POST: book with title t, author a, ISBN i
	this->title = t;									
	this->author = a;
	if (validISBN(i)) {						// if i is valid ISBN set to i
		this->ISBN = i;
	}
	else {
		this->ISBN = "missing";				// If i is invalid ISBN assign "missing"
	}
}

// accessors
string Book::getTitle() const {			// POST: return title
	return title;
}				
string Book::getAuthor() const{			// POST: return author
	return author;
}
string Book::getISBN() const{			// POST: return ISBN
	return ISBN;
}

// modifiers
void Book::setTitle(string title){		// POST: set title to t
	this->title = title;
}
void Book::setAuthor(string author){	// POST: set author to a
	this->author = author;
}
void Book::setISBN(string isbn){		// POST: set ISBN to isbn
										// If i is invalid ISBN assign "missing"
	if (validISBN(isbn)) {				// call validISBN
		this->ISBN = isbn;				// set to arg if true
	}
	else {
		this->ISBN = "missing";			// set to "missing" if false
	}
}										
void Book::display(ostream& out) const		// POST: display title, author, ISBN one per line on out
{
	out << left;							// format output left
	out << setw(35) << title;				// format title
	out << setw(35) << author;				// format author
	out << setw(15) << ISBN;				// format ISBN
	
	
}

bool Book::validISBN(string isbn) {					// POST: return bool of whether or not the ISBN is valid
	int sum = 0;									// init sum
	for (int i = 0; i < isbn.length() - 1; i++) {	// loop over int's in ISBN -- leave out checksum
		string s = to_string(isbn[i] - 48);			// convert int to string subtracting ASCII representation
		int n = stoi(s);							// convert back to int
		sum += (n * (i+1));							// add to sum -- multiplied by 1 indexed location
	}
	if ((sum % 11) == (stoi(to_string(isbn[9])) - 48)) {	// if checksum is valid return true
		return true;
	}
	else if (sum % 11 == 10 && isbn[9] == 'X') {	// if checksum = 10, X is used and checksum is valid -- return true
		return true;
	}
	else {											// checksum is not valid -- return false
		return false;
	}
}