#include "Package.h"
#include <sstream>
#include <iomanip>
using namespace std;

Package::Package()
{	identification = "";
	weight = 0.0;	}
Package::Package(string i, double w)
{	identification = i;
	weight = w;	}
string Package::getIdentification() const
{	return identification;	}
double Package::getWeight() const
{	return weight;	}
void Package::setIdentification(string id)
{	identification = id;	}
void Package::setWeight(double w)
{	weight = w;	}

// POST: return string representation of package
string Package::toString() const	
{	ostringstream os;
	os << fixed << showpoint << setprecision(2);
	os << identification << "\t" << weight;
	return os.str();
}

