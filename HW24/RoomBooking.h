#pragma once

#include <iostream>
using namespace std;

class Customer;

class RoomBooking
{
private:
	int roomNumber;
	int* daysBooked;
	size_t daysCount;

	Customer* customer;
public:
	RoomBooking();

	RoomBooking(int rN, int* dB, size_t dC, Customer* cust);

	RoomBooking(const RoomBooking& that);

	RoomBooking(RoomBooking&& that) noexcept;

	~RoomBooking();

	void addDay(int day);

	void removeDay(int day);

	void printBooking();

	RoomBooking& operator=(const RoomBooking& that);

	RoomBooking& operator=(RoomBooking&& that) noexcept;

	RoomBooking operator+(const RoomBooking& that);

	friend ostream& operator<<(ostream& out, const RoomBooking& booking);
};