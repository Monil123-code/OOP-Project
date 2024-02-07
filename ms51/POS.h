/*
*****************************************************************************
                          Final Project Milestone - #51

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 13/04/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_POS_H_
#define SDDS_POS_H_
#include <iostream>
#include <cstring>

namespace sdds {

   
    const double TAX = 0.13;
    const int MAX_SKU_LEN = 7;

    const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2030;

    const int MAX_STOCK_NUMBER = 99;
    const int MAX_NO_ITEMS = 200;

    const int MIN_MONTH = 1;
    const int MAX_MONTH = 12;

    const int MIN_DAY = 1;

    const int MIN_HOUR = 0;
    const int MAX_HOUR = 23;

    const int MIN_MINUTE = 0;
    const int MAX_MINUTE = 59;

    const int MAX_NAME_LEN = 128;

    const int POS_LIST = 1;
    const int POS_FORM = 2;

    const int MIN_PRICE = 0;
    const int MIN_QTY = 0;

    const char ERROR_POS_SKU[] = "SKU too long";
    const char ERROR_POS_NAME[] = "Item name too long";
    const char ERROR_POS_PRICE[] = "Invalid price value";
    const char ERROR_POS_TAX[] = "Invalid tax status";
    const char ERROR_POS_QTY[] = "Invalid quantity value";
    const char ERROR_POS_STOCK[] = "Item out of stock";
    const char ERROR_POS_EMPTY[] = "Invalid Empty Item";

}
#endif