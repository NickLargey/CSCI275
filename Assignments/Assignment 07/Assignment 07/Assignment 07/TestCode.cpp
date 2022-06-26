
#include <iostream>
#include "FeetInches.h"
using namespace std;

int main ()
{	FeetInches f1;															// test default constructor
	cout << "f1 contents: " << f1.getFeet() << " " << f1.getInches() << endl;	// test modifier function

	FeetInches f2 (2, 3);													// test parameterized constructor
	cout << "f2 contents: " << f2 << endl;									// test << operator

	FeetInches f3;
	cout << "Enter data for f3 in format: feet inches ";
	cin >> f3;																// test >> operator
	cout << "f3 contents: " << f3 << endl;									// test simplify on data (1 13)

	FeetInches f4 (3,8);
	FeetInches f5 (2,8);
	FeetInches f6 = f4 + f5;												// test addition
	cout << "Sum of " << f4 << " and " << f5 << " is " << f6 << endl;
	
	
	// test relationals
	FeetInches f9 (3,8);
	if (f4 == f9) cout << f4 << " equals " << f9 << endl;
	else cout << "error as f4 " << f4 << " should equal f9 " << f9 << endl;
	if (f4 != f5) cout << f4 << " not equals " << f5 << endl;
	else cout << "error as " << f4 << " should not equal " << f5 << endl;
	if (f4 > f5) cout << f4 << " greater than " << f5 << endl;
	else cout << "error as " << f4 << " should be greater than " << f5 << endl;
	if (f5 < f4) cout << f5 << " less than " << f4 << endl;
	else cout << "error as " << f5 << " should be less than " << f4 << endl;

	// test increment
	FeetInches f10  (1,0);
	cout << "f10 currently is " << f10 << endl;
	++f10;
	cout << "Test prefix increment, f10 now is: " << f10 << endl;
	FeetInches f11(1,0);
	cout << "f11 currently is " << f11 << endl;
	f11++;
	cout << "Test postfix increment, f11 now is: " << f11 << endl;

	// test type conversion
	FeetInches f13 (2,3);
	int totalInches = (int)f13;
	cout << "Total inches in " << f13 << " is " << totalInches << endl;
	double totalFeet = static_cast<double> (f13);
	cout << "Total feet in " << f13 << " is " << totalFeet << endl;

	return 0;
}

