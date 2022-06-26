#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// POST: display items in array
void display (const string a[], int size);		// string * a

// POST: insert item at end of array
void insert(string a[], int& size);

// POST: remove item if found from array
void remove(string a[], int& size);

// POST: return index of item or -1
int search(const string a[], int size, string name);


int main()
{	const int CAPACITY = 3;				// capacity of array
	string friends[CAPACITY];			// array of string
	int size = 0;						// number of elements used
	string name;						// a name
	char choice;						// menu choice

	// read names and place into array
	cout << "Enter name (quit to end): ";
	cin >> name;
	while (name != "quit")
	{	if (size < CAPACITY)
		{	friends[size] = name;
			size++;
		}
		else
			cout << "Array is full" << endl;
		cout << "Enter name (quit to end): ";
		cin >> name;
	}

	// display menu and perform task
	cout << "Enter choice (D display I insert R remove Q quit): ";
	cin >> choice;
	while (choice != 'Q')
	{	switch (choice)
		{	case 'D':						// display names
				display (friends, size);
				break;
			case 'I':						// insert a name
				insert (friends, size);
				break;
			case 'R':						// remove a name
				remove (friends, size);
				break;
		}
		cout << "Enter choice (D display I insert R remove Q quit): ";
		cin >> choice;
	}
	return 0;
}

// POST: display items in array
void display(const string a [], int size)
{	for (int k = 0; k < size; k++)
		cout << a[k] << endl;
}

// POST: insert item at end of array
// Note no error checking is done here
void insert (string a[ ], int & size)
{	string name;
	cout << "Enter name: ";
	cin >> name;
	a[size] = name;
	size++;
}

// POST: remove item if found from array
// Note no error checking is done here
void remove(string a[], int& size)
{	string name;
	cout << "Enter name: ";
	cin >> name;
	int index = search (a, size, name);
	if (index >= 0)
	{	for (int k = index+1; k < size; k++)
			a[k-1] = a[k];
		size--;
	}
}

// POST: return index of item or -1
int search (const string a[],  int size, string name)
{	for (int k = 0; k < size; k++)
		if (a[k] == name)
			return k;
	return -1;
}


