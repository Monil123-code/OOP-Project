/*
*****************************************************************************
						  Final Project Milestone - #54

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
#include "NonPerishable.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds
{
	//returns the character 'N'
	char NonPerishable:: itemType() const
	{
		return 'N';
	}

	// Displays the Nonperishable item
	ostream& NonPerishable::write(ostream& ostr) const
	{
		Item::write(ostr);
		if (!m_error)
		{
			if (m_displayType == POS_LIST) 
			{
				ostr << "     N / A   |";
			}
			else
			{
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
	istream& NonPerishable::read(istream& istr)
	{
		Item::read(istr);
		return istr;
	}
}