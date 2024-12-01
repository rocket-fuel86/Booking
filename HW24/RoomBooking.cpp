#include <iostream>

#include "RoomBooking.h"
using namespace std;

RoomBooking::RoomBooking() : roomNumber(0), daysBooked(nullptr), daysCount(0), customer(nullptr) {}

RoomBooking::RoomBooking(int rN, int* days, size_t dC, Customer* cust) : roomNumber(rN), daysCount(dC), customer(cust)
{
	daysBooked = new int[daysCount];

	for (int i = 0; i < daysCount; i++)
	{
		daysBooked[i] = days[i];
	}
}

RoomBooking::RoomBooking(const RoomBooking& that)
{
	this->roomNumber = that.roomNumber;
	this->daysCount = that.daysCount;
	this->customer = that.customer;

	daysBooked = new int[daysCount];

	for (int i = 0; i < daysCount; i++)
	{
		daysBooked[i] = that.daysBooked[i];
	}
}

RoomBooking::RoomBooking(RoomBooking&& that) noexcept
{
	roomNumber = that.roomNumber;
	daysBooked = that.daysBooked;
	daysCount = that.daysCount;
	customer = that.customer;

	that.daysBooked = nullptr;
	that.daysCount = 0;
	that.customer = nullptr;
}

RoomBooking::~RoomBooking()
{
	delete[] daysBooked;
}

void RoomBooking::addDay(int day)
{
	int* newDaysBooked = new int[daysCount + 1];

	for (int i = 0; i < daysCount; i++)
	{
		newDaysBooked[i] = daysBooked[i];
	}

	newDaysBooked[daysCount] = day;

	delete[] daysBooked;

	daysBooked = newDaysBooked;

	++daysCount;
}

void RoomBooking::removeDay(int day)
{
	for (int i = 0; i < daysCount; i++)
	{
		if (daysBooked[i] == day) 
		{
			for (int j = i; j < daysCount - 1; j++) 
			{
				daysBooked[j] = daysBooked[j + 1];
			}

			daysCount--;
			break;
		}
	}
}

void RoomBooking::printBooking()
{
	cout << roomNumber << endl;

	for (int i = 0; i < daysCount; i++)
	{
		cout << daysBooked[i] << " ";
	}

	cout << endl;
}

RoomBooking& RoomBooking::operator=(const RoomBooking& that)
{
	if (this != &that)
	{
		delete[] daysBooked;

		roomNumber = that.roomNumber;
		daysCount = that.daysCount;
		customer = that.customer;

		daysBooked = new int[daysCount];

		for (int i = 0; i < daysCount; i++)
		{
			daysBooked[i] = that.daysBooked[i];
		}
	}

	return *this;
}

RoomBooking& RoomBooking::operator=(RoomBooking&& that) noexcept
{
	if (this != &that)
	{
		delete[] daysBooked;

		roomNumber = that.roomNumber;
		daysBooked = that.daysBooked;
		daysCount = that.daysCount;
		customer = that.customer;

		that.daysBooked = nullptr;
		that.daysCount = 0;
		that.customer = nullptr;
	}

	return *this;
}

RoomBooking RoomBooking::operator+(const RoomBooking& that)
{
	if (this->customer == that.customer)
	{
		int* newDaysBooked = new int[this->daysCount + that.daysCount];

		int i = 0;

		for (; i < this->daysCount; i++)
		{
			newDaysBooked[i] = this->daysBooked[i];
		}

		for (int j = 0; j < that.daysCount; j++, i++)
		{
			newDaysBooked[i] = that.daysBooked[j];
		}

		RoomBooking newBooking(this->roomNumber, newDaysBooked, this->daysCount + that.daysCount, this->customer);

		delete[] newDaysBooked;

		return newBooking;
	}
	else 
	{
		cout << "Cannot combine bookings for different customers." << endl;
	}
}

ostream& operator<<(ostream& out, const RoomBooking& booking)
{
	out << booking.roomNumber << endl;

	for (int i = 0; i < booking.daysCount; i++)
	{
		out << booking.daysBooked[i] << " ";
	}

	out << endl;

	return out;
}