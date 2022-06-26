#include "Bin.h"

Bin::Bin()
{	city = "";	
	totalWeight = 0.0;	}
Bin::Bin(string city)
{	this->city = city;	
	totalWeight = 0.0;	}
string Bin::getCity() const
{	return city;	}
double Bin::getTotalWeight() const
{	return totalWeight;	}
vector<Package*> Bin::getContents() const
{	return contents;	}
void Bin::setCity(string city)
{	this->city = city;	}
void Bin::setTotalWeight(double w)
{	this->totalWeight = w;	}
void Bin::setContents(vector<Package*> contents)
{	this->contents = contents;	}

void Bin::addPackage(Package* p)	// POST: add package to this bin
{	contents.push_back (p);
	totalWeight += p->getWeight();
}
