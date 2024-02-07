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
#include <fstream>
#include "Error.h"

using namespace std;

namespace sdds
{   // Constructor
	Error::Error()
	{
		m_errorMsgPtr = nullptr;
	}

	// one arg constructor
	Error::Error(const char* error)
	{

		if (error)
		{
			m_errorMsgPtr = new char[strlen(error) + 1];
			strcpy(m_errorMsgPtr, error);
		}
		else
		{
			m_errorMsgPtr = nullptr;
		}
	}

	//destructor
	Error::~Error()
	{
		delete[] m_errorMsgPtr;
	}

	// copy constructor
	Error::Error(const Error& source)

	{
		m_errorMsgPtr = nullptr;
		*this = source;
	}

	// copy assignment operator
	Error& Error::operator=(const Error& source)
	{
		if (this != &source) // check self assignment 
		{

			if (*this)
			{
				delete[] this->m_errorMsgPtr;
			}

			if (source.m_errorMsgPtr != nullptr) // check if not nullptr
			{
				int Size = strlen(source.m_errorMsgPtr);
				m_errorMsgPtr = new char[Size + 1]; // dynamically allocate memory

				strcpy(m_errorMsgPtr, source.m_errorMsgPtr); // copy 

			}
			else
			{
				m_errorMsgPtr = nullptr;
			}
		}
		return *this;
	}

	// return true if message is not null
	Error::operator bool() const
	{
		return m_errorMsgPtr != nullptr;
	}

	//Method clears the error message 
	Error& Error::clear()
	{
		delete[] m_errorMsgPtr;
		m_errorMsgPtr = nullptr;
		return *this;
	}

	// output the data
	void Error::outputData(std::ostream& os) const
	{
		if (m_errorMsgPtr != nullptr)
			os << m_errorMsgPtr;

	}

	// ostream insertion operator
	std::ostream& operator<<(std::ostream& os, const Error& Error)
	{
		Error.outputData(os);
		return os;
	}

}