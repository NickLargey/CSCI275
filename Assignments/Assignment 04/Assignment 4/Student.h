#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string name;							// name of student
	int nCourses;							// number of courses student is taking
	string courseList[5];					// array of course names

public:

	// POST: empty student with no courses
	Student()								
	{	name = "";
		nCourses = 0;
		for (int k=0; k<5; k++)
			courseList[k] = "";
	}
	
	// accessors

	// POST: return name
	string getName() const { return name; }					
	
	// POST: return number of courses
	int getNcourses() const { return nCourses; }			    
	
	// PRE: 0 <= index < number of courses
	// POST: return course name at index
	string getCourse(int index) const { return courseList[index]; }	
											
	// modifiers

	// POST: set name to s
	void setName(string s)	{ 
		name = s; 
	}
	
	// PRE: number of courses in range 1..5
	// POST: set number of courses
	void setNcourses (int n) { 
		nCourses = n; 
	}

	// PRE: 0 <= index < number of courses
	// POST: set course name at index to s
	void setCourse (int index, string s) { 
		courseList[index] = s; 
	}										
};

