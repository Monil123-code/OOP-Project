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
#include "PosIO.h"
#include <iostream>

using namespace std;
namespace sdds
{
	// Input operator
	istream& operator>>(istream& istr, PosIO& right)
	{
		right.read(istr);
		return istr;
		
	}

	// Output operator
	ostream& operator<<(ostream& ostr,const PosIO& right)
	{
		right.write(ostr);
		return ostr;
	}

	// File output operator
	ofstream& operator<<(ofstream& oftr,const PosIO& right)
	{
		right.save(oftr);
		return oftr;
	}

	// File input operator
	ifstream& operator>>(ifstream& iftr, PosIO& right)
	{
		right.load(iftr);
		return iftr;
	}
}
