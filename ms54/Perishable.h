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
#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_
#include <iostream>
#include <cstring>
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds
{

    class Perishable :
        public Item
    {
        Date m_date;

        ostream& write(ostream&) const;
        istream& read(istream&);
        ofstream& save(ofstream&) const;
        ifstream& load(ifstream&);
    public:
        char itemType()const;
    };
}
#endif

