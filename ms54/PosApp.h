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
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include <iostream>
#include <cstring>
#include"Item.h"
#include"POS.h"
using namespace std;
namespace sdds {
    class PosApp 
    {
        char m_FileName[128 + 1]; //cString to store name of file

        Item* Iptr[MAX_NO_ITEMS];

        int nptr;

        // to get the correct integer input
        istream& integerInput(istream& istr, int& input) const;
       
        ostream& menu(ostream& ostr = cout);
        void addItem();
        void removeItem();
        void stockItem();
        void listItems(bool);
        void POS();
        void load();
        void save();
        int integerInput(const std::string&, int&,const int );
        int selectItem();

    public:
        // Constructor
        PosApp(const char* filename);

        // Copy constructor
        PosApp(const PosApp& other) = delete;

        // Copy assignment operator
        PosApp& operator=(const PosApp& other) = delete;

        // implement the action
        void run();

        virtual ~PosApp();
       
    };

}

#endif 