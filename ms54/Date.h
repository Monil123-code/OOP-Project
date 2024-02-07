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
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
namespace sdds {
    class Date
    {
        int m_year;
        int m_month;
        int m_day;
        int m_hour;
        int m_minute;

        bool m_DateOnly; // Date flag
        Error m_error;   // Error attribute

    public:
        Date(); //Constructor
        ~Date(); // Destructor
        Date(int year, int month, int day); // Four arg Constructor
        Date(int year, int month, int day, int hour, int minute = 0); // Five arg constructor
        bool operator==(const Date& received) const; // == operator
        bool operator!=(const Date& received) const; // != operator
        bool operator<(const Date& received) const; // < operator
        bool operator>(const Date& received) const; // > operator
        bool operator<=(const Date& received) const; // <= operator
        bool operator>=(const Date& received) const; // >= operator

        Date& dateOnly(bool); //sets the dateOnly flag 
        operator bool() const; //returns opposite of error
        Error& error(); //returns the refrence of error object
        ostream& display(ostream& ostr) const; // Displays the year, month, hour and minute
        istream& read(istream& istr); // Read from the user input
    };
    // Already implemented utility functions
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);

    int uniqueDateValue(int year, int mon, int day, int hour, int min);

    int daysOfMonth(int year, int month);

    //insertion operator
    istream& operator>>(istream& istr, Date& right);

    //extraction operator
    ostream& operator<<(ostream& ostr, const Date& right);

}
#endif