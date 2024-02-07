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
#define _CRT_SECURE_NO_WARNINGS
#include "POS.h"
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds
{
	// constructor
	Item::Item() : PosIO()
	{
		setEmpty();
	}

	// Copy constructor
    Item::Item(const Item& copyFrom) :PosIO(copyFrom)
	{
		operator=(copyFrom);
	}

	// Copy assignment operator
	Item& Item:: operator =(const Item& RightOperand) 
	{
		if (this != &RightOperand) // check for self assignment 
		{
			strncpy(m_SKU, RightOperand.m_SKU, MAX_SKU_LEN);
			m_price = RightOperand.m_price;
			m_quantity = RightOperand.m_quantity;
			m_error = RightOperand.m_error;
			m_taxed = RightOperand.m_taxed;
			delAlloCopy(m_name, RightOperand.m_name);
		}
		return *this;
	}

	// Destructor
	Item::~Item() 
	{
		delete[] m_name;
	}

	// Comparison operator
	bool Item:: operator==(const char* right) const 
	{
		return !strcmp(m_SKU, right);
	}

	// Comparison operator
	bool Item:: operator > (const Item& right) const
	{
		return strcmp(m_name, right.m_name) > 0;
	}

	// Addition operator
int Item::operator+=(int right)
	{
	 	m_quantity += right;
		if (m_quantity > MAX_STOCK_NUMBER)
		{
			m_quantity = MAX_STOCK_NUMBER;
			m_error = Error(ERROR_POS_QTY);
		}
		return m_quantity;
	}

// Subtraction operator
	int Item::operator-=(int right)
	{
		
		if (right > m_quantity)
		{
			m_quantity = 0;
			m_error = Error(ERROR_POS_STOCK);
		}
		else 
		{
			m_quantity -= right;
		}
		return m_quantity;
	}

	// Bool conversion operator
	Item::operator bool() const 
	{
		return !m_error;
	}

	//helper function
	double operator+=(double& left, const Item& right)
	{
		 left += (right.cost() * right.quantity());
		 return left;
	}

	// Set the display type of the item
	Item& Item:: displayType(int type) {
		m_displayType = type;
		return *this;
	}

	// Get the cost of the item
	double Item::cost() const {
		double totalCost =0.0;
		if (m_taxed) {
			totalCost = m_price *(1 + TAX); // add tax
		}
		else
		{
			totalCost = m_price;
		}
		return totalCost;
	}

	// Get the quantity of the item
	int Item::quantity()const
	{
		return m_quantity;
	}

	// Clear the item
	Item& Item::clear() {
		m_error.clear();
		return *this;
	}
	
	// Write the item to an output stream
	ostream& Item:: write(ostream& ostr) const 
	{
		if (!m_error) 
		{
			if (m_displayType == POS_LIST) // List view
			{
				char name[MAX_NAME_LEN + 1]{};
				if (m_name != nullptr)
				{
					strncpy(name, m_name, 20);
				}

				ostr.setf(ios::left);
				ostr.width(7);
				ostr << m_SKU;
				ostr << "|";
				ostr.width(20);
				ostr << name;
				ostr.unsetf(ios::left);
				ostr << "|";
				ostr.width(7);
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_price;
				ostr << "|";
				
				if (m_taxed) {
					ostr.width(3);
					ostr << " X ";
					ostr << "|";
				}
				else {
					ostr.width(3);
					ostr << "";
					ostr << "|";
				}
				ostr.width(4);
				ostr << m_quantity;
				ostr << "|";
				ostr.width(9);
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << (cost() * m_quantity);
				ostr << "|";
			}
			else // Form view
			{
				ostr.fill('=');
				ostr.width(13);
				ostr << '=';
				ostr << "v" << endl;
				ostr << "Name:        " << m_name << endl;
				ostr << "Sku:         " << m_SKU << endl;
				ostr << "Price:       " << m_price << endl;
				ostr << "Price + tax: ";
				if (m_taxed) {
					ostr << cost();
				}
				else {
					ostr << "N/A";
				}
				ostr << endl
					<<  "Stock Qty:   " << m_quantity << endl;
			}
		}
		else
		{
			ostr << m_error;
		}
		return ostr;
	}

	// Read the item from an input stream
	istream& Item::read(istream& istr)
	{
		char taxed = {0};
		char SKU[100] = {0};
		char tempName[100] = {0};
		
			// Clear any previous error status
			m_error.clear();

			// Read SKU code
			cout << "Sku" << endl << "> ";
			istr >> SKU;
			while (istr.fail() || strlen(SKU) > MAX_SKU_LEN) {
				istr.clear();
				istr.ignore(1000, '\n');
				cout << ERROR_POS_SKU << endl << "> ";
				istr >> SKU;
			}
			
			if (strlen(SKU) < MAX_SKU_LEN && 0 < strlen(SKU)) 
			{
				istr.ignore(1000, '\n');
				strcpy(m_SKU, SKU);
			}
			// Read name
			cout << "Name" << endl << "> ";
			istr.getline(tempName, 1000);
			while (strlen(tempName) > MAX_NAME_LEN) {
				istr.clear();
				cout << ERROR_POS_NAME << endl << "> ";
				istr.getline(tempName, MAX_NAME_LEN + 1);
			}
			if (strlen(tempName) < MAX_NAME_LEN && strlen(tempName) > 0) {
				delAlloCopy(m_name, tempName);
			}
			

			// Read price
			cout << "Price" << endl << "> ";
			istr >> m_price;
			while (istr.fail() || m_price < MIN_PRICE) {
				istr.clear();
				istr.ignore(1000, '\n');
				cout << ERROR_POS_PRICE << endl << "> ";
				istr >> m_price;
			}
			
			// Read taxed flag
			cout << "Taxed?" << endl << "(Y)es/(N)o: ";
			istr >> taxed;
			while (istr.fail() || (taxed != 'y' && taxed != 'n')) {
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Only 'y' and 'n' are acceptable: ";
				istr >> taxed;
			}
			if (taxed == 'y')
			{
				m_taxed = true;
			}
			else 
			{
				m_taxed = false;
			}

			// Read quantity
			cout << "Quantity" << endl << "> ";
			istr >> m_quantity;
			while (istr.fail() || (m_quantity <= MIN_QTY || m_quantity > MAX_STOCK_NUMBER)) {
				istr.clear();
				istr.ignore(1000, '\n');
				cout << ERROR_POS_QTY << endl << "> ";
				istr >> m_quantity;
			}
			return istr;
	}

	// Save the item to a file
	ofstream& Item:: save(ofstream& ofstr) const
	{
		if (m_name != nullptr) 
		{
			if (!m_error) // check erroneous state 
			{
				char Type = itemType();

				ofstr.setf(ios::fixed);
				ofstr.precision(2);
				ofstr << Type << ",";
				ofstr << m_SKU << ",";
				ofstr << m_name << ",";
				ofstr << m_price << ",";
				ofstr << m_taxed << ",";
				ofstr << m_quantity;
			}
			else
			{
				cerr << m_error << endl;
			}
		}
		return ofstr;
	}

	// Load the item from a file
	ifstream& Item:: load(ifstream& ifstr) 
	{
		char SKU[100]= {0};
		char name[100]= {0};
		double price = 0;
		int taxed = -1;
		int quantity = 0;
		// Clear any previous errors
		m_error.clear();  

		ifstr.getline(SKU, 100, ',');
		ifstr.getline(name, 100, ',');
		ifstr >> price;
		ifstr.ignore();
		ifstr >> taxed;
		ifstr.ignore();
		ifstr >> quantity;

		//validate
		if (!ifstr.fail()) {
			if (strlen(SKU) > MAX_SKU_LEN) {
				m_error = Error(ERROR_POS_SKU);
			}
			else if (strlen(name) > MAX_NAME_LEN) {
				m_error = Error(ERROR_POS_NAME);
			}
			else if (price < MIN_PRICE) {
				m_error = Error(ERROR_POS_PRICE);
			}
			else if (taxed != 0 && taxed != 1) {
				m_error = Error(ERROR_POS_TAX);
			}
			else if (quantity > MAX_STOCK_NUMBER) {
				m_error = Error(ERROR_POS_QTY);
			}
			if (!m_error) {
				strcpy(m_SKU, SKU);
				m_price = price;
				m_quantity = quantity;
				delAlloCopy(m_name, name);
				
				if (taxed == 0) {
					m_taxed = false;
				}
				else {
					m_taxed = true;
				}
			}
		}
		return ifstr;
	}

	// Print the item in a bill format
	ostream& Item::bprint(std::ostream& ostr) const
	{
		char name[21]={0};
		strncpy(name, m_name, 20);

		cout.fill(' ');
		cout.setf(ios::left);
		ostr << "| ";

		ostr.width(20);
		ostr << name;
		cout.unsetf(ios::left);
		ostr << "|";

		ostr.width(10);
		ostr << cost();
		ostr << " |";

		ostr.width(3);
		if (m_taxed) ostr << "T";
		else ostr << " ";
		ostr << "  |" << endl;

		return ostr;
	}

	// Set the item to an empty state
	void Item::setEmpty() 
	{
		m_SKU[0] = '\0';

		 m_name = nullptr;

		 m_price = 0;

	     m_taxed = false;

		m_quantity = 0;

	}
}