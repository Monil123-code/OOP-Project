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
#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace sdds
{

    class NonPerishable :
        public Item
    {
        ostream& write(ostream&) const;
    public:
        char itemType() const;
    };
}
#endif