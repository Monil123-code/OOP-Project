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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Utils.h"
#include "POS.h"
namespace sdds {

    int strLen(const char* str) {
        int len = -1;
        while (str[++len]);
        return len;
    }

    void delAlloCopy(char*& des, const char* src) {
        delete[] des;
        des = nullptr;
        if (src && src[0]) {
            des = new char[strLen(src) + 1];
            strcpy(des, src);
        }
    }

  

    void bubbleItem(Item* list[], int size)
    {
        int i, j;
        Item* temp;

        for (i = size - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (*(list[j]) > *(list[j + 1]))
                {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }
}