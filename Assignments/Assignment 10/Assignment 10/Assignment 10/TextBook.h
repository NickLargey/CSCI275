#pragma once
#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

class TextBook : public Book
{
public:
	TextBook();												// POST: empty TextBook
	TextBook(string t, string a, string i, string c);		// POST: TextBook with title t, author a, ISBN i and course c
	~TextBook();											// TextBook destructor

	string getCourse();										// POST: return course

	void setCourse(string c);								// POST: course is set to c

	void display(ostream& out) const;						// POST: display course, title, author, ISBN one per line on out
private:
	string course;											// TextBook course
};