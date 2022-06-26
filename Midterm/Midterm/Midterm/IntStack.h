#pragma once
class IntStack
{	public:
		IntStack();						// POST: empty stack of capacity 10
		IntStack(int cap);				// PRE: cap > 0
										// POST: empty stack of capacity cap
		IntStack(const IntStack& other);// POST: object constructed from other
		~IntStack ( );					// POST: destructor
		IntStack& operator= (const IntStack& other);
		void push (int item);			// POST: add item to top
		int pop ( );					// PRE: stack is not empty
										// POST: remove and return top item
		int peek ( ) const;				// PRE: stack is not empty
										// POST: return top item
		bool empty( ) const;			// POST: return empty status
		int count ( ) const;			// POST: return number of items
	private:
		int * stack;					// pointer to dynamic array
		int capacity;					// capacity of array
		int size;						// number of items in array
};


