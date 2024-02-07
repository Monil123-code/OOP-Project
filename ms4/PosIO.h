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
#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

namespace sdds {
	
	class PosIO
	{
	public:
		// Pure virtual functions 
		virtual ostream& write(ostream&) const = 0; // Write the object to an output stream
		virtual istream& read(istream&) = 0; // Read the object from an input stream
		virtual ofstream& save(ofstream&) const = 0; // Save the object to a file
		virtual ifstream& load(ifstream&) = 0; // Load the object from a file
	};

	// Operator overloading functions
	istream& operator>>(istream&, PosIO&); // Input operator
	ifstream& operator>>(ifstream&, PosIO&); // File input operator
	ostream& operator<<(ostream&, const PosIO&); // Output operator
	ofstream& operator<<(ofstream&, const PosIO&); // File output operator

}
#endif