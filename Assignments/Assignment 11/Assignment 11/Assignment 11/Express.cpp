#include "Express.h"
Express::Express() : Package()
{	type = "";	}
Express::Express(string id, double w, string t) : Package(id,w)
{	type = t;	}
string Express::getType() const
{	return type;	}
void Express::setType(string t)
{	type = t;	}
string Express::toString() const
{	return Package::toString() + "\t" + type;	}

double Express::cost() const	// POST: return cost 
{	if (type == "Two Day")
		return getWeight() * 1.75 + 10.00;
	else
		return getWeight() * 1.75 + 20.00;
}

