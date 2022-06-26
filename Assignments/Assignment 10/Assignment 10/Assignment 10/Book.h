#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book
{
public:
	Book();									// POST: empty book
	Book (string t, string a, string i);	// POST: book with title t, author a, ISBN i
											// If i is invalid ISBN assign "missing"
	// accessors
	string  getTitle( ) const;				// POST: return title
	string  getAuthor( ) const;				// POST: return author
	string  getISBN( ) const;				// POST: return ISBN
	
	// modifiers
	void setTitle (string title);			// POST: set title to t
	void setAuthor (string author);			// POST: set author to a
	void setISBN (string isbn);				// POST: set ISBN to i
											// If i is invalid ISBN assign "missing"
	void display (ostream& out) const;		// POST: display title, author, ISBN one per line on out
private:
	string title;							// book title
	string author;							// book author
	string ISBN;							// book ISBN
	bool validISBN (string isbn);			// POST: return true if ISBN is valid, else false
};


