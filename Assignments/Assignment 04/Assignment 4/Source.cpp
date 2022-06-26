#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Student.h"

using namespace std;

//PRE: list of students and courses has been loaded into an array of Students
//POST: return all students and courses they're taking
void displayAll(Student* a, int size);

//PRE: list of students and courses has been loaded into an array of Students
//POST: user entered course will return list of enrolled students for that course
void displayCourse(Student* a, int size);

//PRE: list of students and courses has been loaded into an array of Students
//POST: user entered student name will return list of all enrolled classes for that student
void displayStudent(Student* a, int size);



int main() {
	// declare max capacity of students and init array of Students
	const int CAPACITY = 20;
	Student sCourses[CAPACITY];
	// init line variable to read in to
	string line;
	// init size of student list read from first line of .txt file
	int size;
	// init file stream
	ifstream fin;
	// init variable to store current user chioce from list
	char choice;
	// init empty Student object to enter into sCourses array 
	Student student;
	// init number of courses being taken by a student for Student class
	int numCourses;
	string course;
	
	// read in file and throw error if file fails to open
	fin.open("courses.txt");
	if (fin.fail()) {
		cout << "File failed to open" << endl;;
		return 1;
	}

	// get first line of file containing size of student list
	getline(fin, line);
	size = stoi(line);

	// priming read for while loop
	getline(fin, line);

	// init variable for Student array index
	int i = 0;
	// read in file data
	while (!fin.fail()) {
		// set student name and read in next line
		student.setName(line);
		getline(fin, line);
		// set number of courses being taken by student
		numCourses = stoi(line.substr(0,1));
		student.setNcourses(numCourses);
		// create string stream to split courses being to take to be stored in Student.courseList indexes
		istringstream ss(line.substr(2));
		for (int i = 0; i < numCourses; i++) {
			ss >> course;
			student.setCourse(i, course);
		}
		// add student to sCourses array at index i
		sCourses[i] = student;
		// increment index variable
		i++;
		// read in next line
		getline(fin, line);
	}
	// close .txt file
	fin.close();

	do {
		// print menu options
		cout << "Please enter menu choice or Q to quit" << endl;
		cout << "D to display all students and courses." << endl;
		cout << "C to display students taking a course" << endl;
		cout << "S to display courses for a student." << endl;
		cout << ">>> ";
		// pick up users case-insensitive choice 
		cin >> choice;
		choice = tolower(choice);
		// exit program if user chooses too
		if (choice == 'q') {
			return 0;
		}
		// call functions depending on users input choice
		switch (choice) {
		case 'd':
			displayAll(sCourses, size);
			break;
		case 's':
			displayStudent(sCourses, size);
			break;
		case 'c':
			displayCourse(sCourses, size);
			break;
		}

	} while (choice != 'q');
	
	return 0;
	
}

//PRE: list of students and courses has been loaded into an array of Students
//POST: return all students and courses they're taking
void displayAll(Student* a, int size) {
	// print header
	cout << setw(15) << left << "\nName" << "Courses" << endl;
	// loop through sCourses indexes
	for (int i = 0; i < size; i++) {
		// set max number of courses to loop through for each student
		int n = a[i].getNcourses();
		// print current student's name
		cout << setw(15) << a[i].getName();
		// loop through and print current student's courses
		for (int j = 0; j < n; j++) {
			cout << a[i].getCourse(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//PRE: list of students and courses has been loaded into an array of Students
//POST: user entered course will return list of enrolled students for that course
void displayCourse(Student* a, int size) {
	// init variable for user to enter course to search
	string courseName;
	// init empty string to output at end of function
	string outStr = "";
	// prompt user
	cout << "\nPlease enter a course code: ";
	cin >> courseName;
	// loop over students in array
	for (int i = 0; i < size; i++) {
		// set max number of courses to loop through for each student
		int n = a[i].getNcourses();
		// loop over current students courses
		for (int j = 0; j < n; j++) {
			// if current course matches searched course append student's name to outStr
			if (a[i].getCourse(j) == courseName) {
				outStr += a[i].getName() + "\n";
			}
		}
	}
	// print list of students enrolled in searched course or error message if no match is found
	outStr.size() > 0 ? cout << "\nStudents taking " << courseName << "\n" << outStr << endl : cout << "\nPlease enter a valid course code" << "\n" << endl;
}

//PRE: list of students and courses has been loaded into an array of Students
//POST: user entered student name will return list of all enrolled classes for that student
void displayStudent(Student* a, int size) {
	// init variable for student searched
	string student;
	// print prompt
	cout << "\nPlease enter a students name: ";
	// ignore newline char
	cin.ignore();
	// get full name of the desired student
	getline(cin, student);
	// loop over students in sCourses array
	for (int i = 0; i < size; i++) {
		// set max number of courses to loop through for each student
		int n = a[i].getNcourses();
		// if current student's name matches search print class list 
		if (a[i].getName() == student) {
			cout << "\n" << a[i].getName() << " is taking: ";
			for (int j = 0; j < n; j++) {
				cout << a[i].getCourse(j) << " ";
			}
		}
	}	
	cout << "\n" << endl;

}