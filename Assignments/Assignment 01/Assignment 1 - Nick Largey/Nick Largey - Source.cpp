#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main()
{	
	int numPackages = 0;
	double avgWeight = 0;
	double totalCharges = 0;
	double smWeight = INT_MAX;
	double lgWeight = 0;
	string hist1 = "1 ";
	string hist2 = "2 ";
	string hist3 = "3 ";
	string hist4 = "4 ";
	double weight;

	cout << "Statistics by Nick Largey\n" << endl;
	cout << "Enter Package Weights (0 to quit): ";
	
	cin >> weight;
	if (weight == 0) {
		cout << "Total number of packages: 0";
	}

	cout << setw(12) << "Category" << setw(12) << "Weight (lbs.)" << "Shipping" << endl;
	while (weight != 0) {
		int cat = 0;
		double shipping = 0.0;

		numPackages++;
		avgWeight = avgWeight + weight;
		if (weight <= 2.0) {
			cat = 1;
			shipping = 2.75;
			hist1 += "*";
		}

		if (weight > 2.0 && weight <= 5.0) {
			cat = 2;
			shipping = 4.50;
			hist2 += "*";
		}

		if (weight > 5.0 && weight <= 8.0) {
			cat = 3;
			shipping = 6.75;
			hist3 += "*";
		}
		if (weight > 8.0 && weight <= 10.0) {
			cat = 4;
			shipping = 8.25;
			hist4 += "*";
		}

		totalCharges = totalCharges += shipping;

		if (weight < smWeight) {
			smWeight = weight;
		}

		if (weight > lgWeight) {
			lgWeight = weight;
		}
		cout << setprecision(2) << fixed << showpoint << left;
		cout << setw(12) << cat << setw(12) << weight << '$' << shipping << endl;
		cin >> weight;
	}

		cout << "\n";
		cout << "Total number of packages: " << numPackages << endl;
		cout << "Average weight of all packages: " << avgWeight / numPackages << endl;
		cout << "Total shipping charges: $" << totalCharges << endl;
		cout << "Lightest weight: " << smWeight << endl;
		cout << "Heaviest weight: " << lgWeight << endl;
		cout << "\n";

		cout << "Histogram of category counts:" << endl;
		cout << "-----------------------------" << endl;
		cout << hist1 << endl;
		cout << hist2 << endl;
		cout << hist3 << endl;
		cout << hist4 << endl;

	return 0;
}