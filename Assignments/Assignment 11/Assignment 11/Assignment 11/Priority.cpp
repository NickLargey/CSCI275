#include "Priority.h"

Priority::Priority() : Package()
{	}
Priority::Priority(string id, double w) : Package (id, w)
{	}

double Priority::cost() const	// POST: return cost of package
{	return getWeight() * 1.75;	}

