/*
*****************************************************************************
                          Final Project Milestone - #3

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 5/04/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Utils.h"
namespace sdds {
   
    void delAlloCopy(char*& des, const char* src) {
        delete[] des;
        des = nullptr;
        if (src && src[0]) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
    }
}