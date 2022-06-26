#pragma once
#include <vector>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

template <typename T>
class Bag
{	public:
		Bag ();							// empty bag
		void insert (T item);			// POST: insert item into bag
		T remove ( );					// PRE: bag is not empty
										// POST: remove random item from bag
		int size() const;				// POST: return number of items in bag
		bool empty () const;			// POST: return empty status of bag
	private:
		vector<T> bag;					// init bag vector
};

template <typename T>
Bag<T>::Bag()							// empty bag
{
}

template <typename T>
void Bag<T>::insert(T item)				// POST: insert item into bag
{	
	bag.insert(bag.end(), item);		// insert item at end of vector
}

template <typename T>
T Bag<T>::remove()						// PRE: bag is not empty
{										// POST: remove random item from bag
	srand(time(NULL));					// seed rand with current time
	int i = rand() % bag.size();		// set i to a number between 0 and size of bag
	T ret = bag.at(i);					// create object to return for comparison
	bag.erase(bag.begin() + i);			// erase random item from vector
	return ret;							// return chosen item
}

template <typename T>
int Bag<T>::size() const				// POST: return number of items in bag
{	
	return bag.size();					// return number of items in bag
}

template <typename T>
bool Bag<T>::empty() const				// POST: return empty status of bag
{	
	return bag.empty();					// return bool of if bag is empty or not
}

