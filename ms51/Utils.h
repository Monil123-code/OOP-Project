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
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include <fstream>
#include "Item.h"
namespace sdds 
{
	int strLen(const char* str);
		void delAlloCopy(char*& des, const char* src);
	
		void bubbleItem(Item* list[], int size);
}
#endif