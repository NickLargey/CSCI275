#pragma once
#include <string>

using namespace std;
class Customer
{
private:
	string id;
	string name;
	double balance;

public:
	Customer()
	{
		id = "";
		name = "";
		balance = 0.0;
	}
	
	Customer(string id, string name, double balance) :id{ "" }, name{ "" }, balance{ 0.0 } {};
	string getID() const
	{
		return id;
	}
	string getName() const
	{
		return name;
	}	
	double getBalance() const
	{
		return balance;
	}
	void setID(string s) 
	{
		id = s;
	}
	void setName(string n)
	{
		name = n;
	}

	void setBalance(double d)
	{
		balance = d;
	}

	double deposit(double depAmount)
	{	
		balance = balance + depAmount;
		return balance;
	}
	double withdraw(double drawAmount)
	{
		balance = balance - drawAmount;
		return balance;
	}
};