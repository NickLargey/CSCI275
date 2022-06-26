#include "TextBook.h"
#include <iostream>
using namespace std;

TextBook::TextBook() : Book() {		// POST: empty TextBook
	course = "";
}
TextBook::TextBook(string t, string a, string i, string c) : Book(t, a, i) {	// POST: TextBook with title t, author a, ISBN i and course c
	this->course = c;
}
TextBook::~TextBook() {}			// TextBook destructor

string TextBook::getCourse() {		// POST: return course
	return course;
}

void TextBook::setCourse(string c) {	// POST: course is set to c
	this->course = c;
}

void TextBook::display(ostream& out) const {	// POST: display course, title, author, ISBN one per line on out
	out << left << setw(15) << course;			// format course
	Book::display(out);							// call parent class display function
}