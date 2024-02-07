/*
*****************************************************************************
						  Final Project Milestone - #4

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 06/04/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <iostream>
#include <cstring>
#include "PosIO.h"
#include "POS.h"
#include "Error.h"

using namespace std;
namespace sdds {
	class Item : public PosIO
	{
		// Private member variables
		char m_SKU[MAX_SKU_LEN]; // SKU code (stock-keeping unit)
		char* m_name; // Pointer to the item name
		double m_price; // Price of the item
		bool m_taxed; // Whether the item is taxed or not
		int m_quantity; // Quantity of the item in stock

		// Private member functions
		Item& clear(); // Clear the item
		
		void setEmpty(); // Set the item to an empty state

		// Protected member variable
	protected:
		ostream& write(ostream&) const; // Write the item to an output stream
		istream& read(istream&); // Read the item from an input stream
		ofstream& save(ofstream&) const; // Save the item to a file
		ifstream& load(ifstream&); // Load the item from a file
		int m_displayType; // Display type of the item 
		Error m_error; // Error object 

	public:
		// Public member functions

		Item(); // constructor
		Item(const Item&); // Copy constructor
		Item& operator=(const Item&); // Copy assignment operator
		~Item(); // Destructor

		
		bool operator==(const char*) const; // Comparison operator
		bool operator>(const Item&) const; // Comparison operator
		int operator+=(int); // Addition operator
		int operator-=(int); // Subtraction operator
		operator bool() const; // Bool conversion operator

		// Public member functions
		double cost() const; // Get the cost of the item
		int quantity() const; // Get the quantity of the item
		ostream& bprint(ostream&) const; // Print the item in a bill format
		Item& displayType(int); // Set the display type of the item

		virtual char itemType() const = 0;
	};

	//Helper functions
	double operator+=(double&, const Item&);

}
#endif