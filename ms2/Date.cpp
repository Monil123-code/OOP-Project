/*
*****************************************************************************
                          Final Project Milestone - #2

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 23/03/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Date.h"
#include "POS.h"
using namespace std;
namespace sdds
{
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }

    int uniqueDateValue(int year, int mon, int day, int hour, int min)
    {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }

    int daysOfMonth(int year, int month)
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    // Constructor
    Date::Date()
    {
        m_DateOnly = false;
        getSystemDate(m_year,m_month,m_day,m_hour,m_minute,m_DateOnly);
       
    }

    //Four arg Constructor that validated and assign values
    Date::Date(int year, int month, int day)
    {
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            m_error = Error("Invalid Year");
        }
        else
        {
            m_year = year;
            if (month < MIN_MONTH || month > MAX_MONTH)
            {
                m_error = Error("Invalid Month");
            }
            else
            {
                m_month = month;

                int NuOfDays = daysOfMonth(m_year, m_month);
                if (day < MIN_DAY || day > NuOfDays )
                {
                    m_error = Error("Invalid Day");
                }
                else
                {
                    m_day = day;
                    m_DateOnly = true;
                }
            }
        }

    }

    //Five arg constructor that validated and assign values
    Date::Date(int year, int month, int day, int hour, int minute)
    {
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            m_error = Error("Invalid Year");
        }
        else
        {
            m_year = year;

            if (month < MIN_MONTH || month > MAX_MONTH)
            {
                m_error = Error("Invalid Month");
            }
            else
            {
                m_month = month;

                int NuOfDays = daysOfMonth(m_year, m_month);
                if (day < MIN_DAY || day > NuOfDays)
                {
                    m_error = Error("Invalid Day");
                }
                else
                {
                    m_day = day;

                    if (hour < MIN_HOUR || hour > MAX_HOUR)
                    {
                        m_error = Error("Invalid Hour");
                        dateOnly(true);
                    }
                    else
                    {
                        m_hour = hour;

                        if (minute < MIN_MINUTE || minute > MAX_MINUTE)
                        {
                            m_error = Error("Invalid Minute");
                        }
                        else
                        {
                            m_minute = minute;
                            dateOnly(false);
                        }
                    }
                }
            }
        }
    }

    // == operator compares the received values with this returns true is equal
    bool Date::operator==(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }

    // Returns true if recieved values not equal to this values
    bool Date::operator!=(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }

    // returns true if this values are less than received values
    bool Date::operator<(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }

    // returns true if this values are greater than received values
    bool Date::operator>(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }


    // returns true if this values are less than  or equal to received values
    bool Date::operator<=(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }

    // returns true if this values are greater than or equal to received values
    bool Date::operator>=(const Date& received) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= uniqueDateValue(received.m_year, received.m_month, received.m_day, received.m_hour, received.m_minute);
    }

    //sets the dateOnly flag with the received value
    Date& Date::dateOnly(bool received)
    {
        m_DateOnly = received;

        if (received)
        {
            m_hour = 0;
            m_minute = 0;
        }
        return *this;
    }

    //returns opposite of error
    Date::operator bool() const
    {
        return !(m_error);
    }

    //returns the reference of error object
    Error& Date::error()
    {
        return m_error;
    }

    // Displays the year, month, hour and minute
    ostream& Date::display(ostream& ostr) const
    {
        if (!m_error) // check if erroneous state or not
        {
            if (m_DateOnly) // check for Dateonly flag
            {
                ostr << m_year << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_month << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_day;
            }
            else
            {
                ostr << m_year << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_month << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_day;
                ostr << ", ";
                ostr.fill('0'); ostr.width(2); ostr << m_hour << ":";
                ostr.fill('0'); ostr.width(2); ostr << m_minute;
            }
        }
        else
        {
            if (m_DateOnly)// check for Dateonly flag
            {
                ostr << m_error << "(" << m_year << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_month << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_day; ostr << ")";
            }
            else
            {
                ostr << m_error << "(" << m_year << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_month << "/";
                ostr.fill('0'); ostr.width(2); ostr << m_day; 
                ostr << ", ";
                ostr.fill('0'); ostr.width(2); ostr << m_hour << ":";
                ostr.fill('0'); ostr.width(2); ostr << m_minute << ")";
            }
        }
        return ostr;
    }

    //extraction operator
    ostream& operator<<(ostream& ostr, const Date& right)
    {
        right.display(ostr);
        return ostr;

    }

    // Read from the user input
    istream& Date:: read(istream& istr)
    {
        // clear the error object and set all attributes to zero
        m_error = nullptr;
        m_year = 0;
        m_month = 0;
        m_day = 0;
        m_hour = 0;
        m_minute = 0;

        int year = 0, month = 0, day = 0, hour = 0, minute = 0;

        if (!(istr >> year))
        {
           m_error = Error("Cannot read year entry");
            return istr;
        }
        else
        {
            m_year = year;
        }
        istr.ignore(1);

        if (!(istr >> month))
        {
            m_error = Error("Cannot read month entry");
            return istr;
        }
        else
        {
            m_month = month;
        }

        istr.ignore(1);
        if (!(istr >> day)) {
            m_error = Error("Cannot read day entry");
            return istr;
        }
        else
        {
            m_day = day;
        }

        if (!m_DateOnly)
        {
            istr.ignore(1);
            if (!(istr >> hour))
            {
                m_error = Error("Cannot read hour entry");
                return istr;
            }
            else
            {
                m_hour = hour;
            }

            istr.ignore(1);

            if (!(istr >> minute)) {
                m_error = Error("Cannot read minute entry");
                return istr;
            }
            else
            {
                m_minute = minute;
            }

        }
        int NuOfDays = daysOfMonth(m_year, m_month);

        // validate the received input
        if (year < MIN_YEAR || year > MAX_YEAR) {
            m_error = Error( "Invalid Year");
        }
        else if (month < MIN_MONTH || month > MAX_MONTH) {
            m_error = Error("Invalid Month");
        }
        else if (day < MIN_DAY || day > NuOfDays) {
            m_error = Error("Invalid Day");
        }
        else if (hour < MIN_HOUR || hour > MAX_HOUR) {
            m_error = Error("Invalid Hour");
        }
        else if (minute < MIN_MINUTE || minute > MAX_MINUTE) {
            m_error = Error("Invlid Minute");
        }

        return istr;

    }

    // insertion operator
    istream& operator>>(istream& istr, Date& right) 
    {
        right.read(istr);
        return istr;
    }

    //Destructor
   Date:: ~Date()
   {

    }
}