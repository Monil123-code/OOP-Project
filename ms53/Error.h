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
#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
    class Error
    {
        char* m_errorMsgPtr; //char pointer to dynamically store error

    public:
        Error();                  // constructor
        Error(const char* error); // one arg constructor
        ~Error(); // destructor
        Error(const Error& source); // copy constructor
        Error& operator=(const Error& source); //copy assignment operator
        operator bool() const; // bool operator
        Error& clear(); //Method clears the error message 
        void outputData(std::ostream& os) const; // output the data
    };
    std::ostream& operator<<(std::ostream& os, const Error& Error); // ostream insertion operator
}
#endif