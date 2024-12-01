#pragma once

#include <iostream>
#include <string>

#include "RoomBooking.h"
using namespace std;

class Customer
{
private:
	string name;
	int customerID;

	RoomBooking* currentBooking;
public:
	Customer();

	Customer(string n, int cID);

	~Customer();

	void makeBooking(RoomBooking* booking);

	void cancelBooking();

	void printCustomerInfo() const;

	friend ostream& operator<<(ostream& out, const Customer& customer);
};