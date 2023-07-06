#include "Seat.h"

// Constructors
Seat::Seat() noexcept(false) // Empty constructor
{
	this->occupied = false;
	this->customer = nullptr;
}

Seat::Seat(Customer* customer) noexcept(false) // Customer constructor
{
	if (customer == NULL || customer == nullptr)
		Seat();
	else
	{
		this->occupied = true;
		this->customer = customer;
	}
}

// Gets
bool Seat::isOccupied() const // Get occupied
{ 
	return this->occupied; 
}

Customer* Seat::getCustomer() const  // Get customer
{ 
	return this->customer; 
}

// Methods
bool Seat::sitCustomer(Customer* customer) // Sit customer
{
	if (customer == NULL || customer == nullptr)
	{
		this->occupied = false;
		this->customer = nullptr;
		return false;
	}

	this->occupied = true;
	this->customer = customer;
	return true;
}

// Operators
bool Seat::operator==(Customer& customer) const // Operator == with customer
{
	if ((strcmp(this->customer->getName(), customer.getName()) == 0) && (strcmp(this->customer->getTicketNumber(), customer.getTicketNumber()) == 0))
		return true;
	else
		return false;
}

bool Seat::operator==(Seat& seat) const // Operator == with seat
{
	if (strcmp(this->customer->getTicketNumber(), seat.getCustomer()->getTicketNumber()) == 0)
		return true;
	else
		return false;
}