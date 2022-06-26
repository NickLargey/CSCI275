#include "IntStack.h"

// POST: empty stack of capacity 10
IntStack::IntStack()			
{	capacity = 10;
	stack = new int [capacity];
	size = 0;
}

// PRE: cap > 0
// POST: empty stack of capacity cap
IntStack::IntStack(int cap)		
{	capacity = cap;
	stack = new int[capacity];
	size = 0;
}


// POST: object is constructed from other
IntStack::IntStack(const IntStack& other)	
{	capacity = other.capacity;			    // copy the other capacity and size			
	size = other.size;
	stack = new int[capacity];			    // create new dynamic array of capacity
	for (int i = 0; i < size; i++)			// copy elements from other array
		stack[i] = other.stack[i];
}

// POST: destructor
IntStack::~IntStack()				
{	delete [ ] stack;
}

// POST: add item to top
void IntStack::push(int item)	
{	if (size == capacity)					// is array full?
	{	capacity = 2 * capacity;			// double the capacity
		int* temp = new int[capacity];		// make a new array twice as big
		for (int k = 0; k < size; k++)		// copy elements to new array
			temp[k] = stack[k];
		delete[] stack;						// release old array
		stack = temp;						// assign stack to new array
	}
	stack[size] = item;			// put item in next position of array
	size++;						// increase size
}

// PRE: stack is not empty
// POST: remove and return top item
int IntStack::pop()			
{	int topItem = stack[size-1];		// top is last element
	size--;								// decrement size
	return topItem;
}

// PRE: stack is not empty
// POST: return top item
int IntStack::peek() const		
{	return stack[size-1];
}

// POST: return empty status
bool IntStack::isEmpty() const	
{	return size == 0;
}

// POST: return number of items
int IntStack::count() const		
{	return size;
}


