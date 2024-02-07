/*
*****************************************************************************
						  Final Project Milestone - #53

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 16/04/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "POS.h"
#include "Perishable.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds
{
	//returns the character 'P'
	char Perishable::itemType()const
	{
		return 'P';
	}

	// read from data from input buffer
	istream& Perishable::read(istream& istr)
	{
		Item::read(istr);
		if (!istr.fail())
		{
			int year = 0, month = 0, day = 0;
		
			cout << "Expiry date (YYYY/MM/DD)" << endl;
			cout << "> ";
			istr >> year;
			istr.ignore();
			istr >> month;
			istr.ignore();
			istr >> day;

			int NuOfDays = daysOfMonth(year, month);

			if (year < MIN_YEAR || year > MAX_YEAR) {
				m_error = Error("Invalid Year");
			}
			else if (month < MIN_MONTH || month > MAX_MONTH) {
				m_error = Error("Invalid Month");
			}
			else if (day < MIN_DAY || day > NuOfDays) {
				m_error = Error("Invalid Day");
			}
			else
			{
				m_date = Date(year, month, day);
			}
		}
		return istr;
	}

	// Displays the Perishable item
	ostream& Perishable::write(ostream& ostr) const
	{
		Item::write(ostr);
		if (!m_error)
		{
			if (m_displayType == POS_LIST) // List view
			{
				ostr << "  " << m_date << " " << '|';
			}
			else // Form view
			{
				ostr << "Expiry date: " << m_date << endl;
				ostr << "=============^" << endl;
			}

		}
		return ostr;
	}

	//Extract Data from the file 
	ifstream& Perishable::load(ifstream& ifstr) 
	{
		Item::load(ifstr);
		if (!ifstr.fail() ) 
		{
			ifstr.ignore();

			int year = 0, month = 0, day = 0;
			ifstr >> year;
			ifstr.ignore();
			ifstr >> month;
			ifstr.ignore();
			ifstr >> day;

			int NuOfDays = daysOfMonth(year, month);

			if (year < MIN_YEAR || year > MAX_YEAR) {
				m_error = Error("Invalid Year");
			}
			else if (month < MIN_MONTH || month > MAX_MONTH) {
				m_error = Error("Invalid Month");
			}
			else if (day < MIN_DAY || day > NuOfDays) {
				m_error = Error("Invalid Day");
			}
			else
			{
				m_date = Date(year, month, day);
			}
		}
		return ifstr;
	}

	//save the data into file
	ofstream& Perishable::save(ofstream& ofstr) const
	{
		Item::save(ofstr);
		if (m_date)
		{
			ofstr << ',' << m_date << endl;
		}
		else
		{
			ofstr << endl;
		}
		return ofstr;

	}
}