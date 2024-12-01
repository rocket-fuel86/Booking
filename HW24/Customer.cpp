#include <iostream>
#include <string>

#include "Customer.h"
using namespace std;

Customer::Customer() : name(""), customerID(0), currentBooking(nullptr) {}

Customer::Customer(string n, int cID) : name(n), customerID(cID), currentBooking(nullptr) {}

Customer::~Customer()
{
	// Без понятия как (
}

void Customer::makeBooking(RoomBooking* booking)
{
	if (currentBooking != nullptr)
	{
		cancelBooking();
	}

	currentBooking = booking;
}

void Customer::cancelBooking()
{
	currentBooking = nullptr;
}

void Customer::printCustomerInfo() const
{
	cout << name << " " << customerID << endl;

	if (currentBooking != nullptr)
	{
		cout << *currentBooking;
	}
	else
	{
		cout << "No current booking";
	}

	cout << endl;
}

ostream& operator<<(ostream& out, const Customer& customer)
{
	out << customer.name << " " << customer.customerID << endl;

	if (customer.currentBooking != nullptr)
	{
		out << *customer.currentBooking;
	}
	else
	{
		out << "No current booking";
	}

	cout << endl;

	return out;
}
