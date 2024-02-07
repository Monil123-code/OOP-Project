// Final Project 
// Milestone 4
// Perishable and NonPerishable Tester
// Version 1.0
// Date	2023-03-29
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of Milestone 4
// for submission.
//
/////////////////////////////////////////////////////////////////
#include "POS.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace sdds;
void div(const char* title);
void nonPerishableTest();
void perishableTest();

int main() {
   div("NonPerishable Test");
   nonPerishableTest();
   div("Perishable Test");
   perishableTest();
   return 0;
}
void perishableTest() {
   int i{};
   int num{};
   char ch{};
   Perishable PI[10];
   ifstream input("perishableInput.csv");
   ofstream output("perishableOutput.csv");
   while((input >> PI[i]).ignore(100, '\n')) {
      output << PI[i++] << endl;
   }
   cout << "Enter the following:" << endl;
   cout << "Sku" << endl;
   cout << "> 1111" << endl;
   cout << "Name" << endl;
   cout << "> Milk" << endl;
   cout << "Price" << endl;
   cout << "> 3.99" << endl;
   cout << "Taxed ?" << endl;
   cout << "(Y)es / (N)o : n" << endl;
   cout << "Quantity" << endl;
   cout << "> 10" << endl;
   cout << "Expiry date(YYYY/MM/DD)" << endl;
   cout << "> 2023/04/10" << endl << endl;
   cin >> PI[i];
   output << PI[i++];
   num = i;
   output.close();
   div("LIST");
   for(i = 0; i < num; i++) {
      cout << PI[i].displayType(POS_LIST) << endl;
   }
   div("FORM");
   for(i = 0; i < num; i++) {
      cout << PI[i].displayType(POS_FORM);
   }
   input.close();
   input.open("perishableOutput.csv");
   div("perishableOutput.csv");
   while(input.get(ch)) {
      cout << ch;
   }
   cout << endl;
}

void nonPerishableTest() {
   int i{};
   int num{};
   char ch{};
   NonPerishable NI[10];
   ifstream input("nonPerInput.csv");
   ofstream output("nonPerOutput.csv");
   while((input >> NI[i]).ignore(100, '\n')) {
      output << NI[i++] << endl;
   }
   num = i;
   output.close();
   div("LIST");
   for(i = 0; i < num; i++) {
      cout << NI[i].displayType(POS_LIST) << endl;
   }
   div("FORM");
   for(i = 0; i < num; i++) {
      cout << NI[i].displayType(POS_FORM);
   }
   input.close();
   input.open("nonPerOutput.csv");
   div("nonPerOutput.csv");
   while(input.get(ch)) {
      cout << ch;
   }
   cout << endl;
}

void div(const char* title) {
   cout << ">>>> ";
   cout.width(70);
   cout.fill('-');
   cout.setf(ios::left);
   cout << title << endl;
   cout.fill(' ');
   cout.unsetf(ios::left);
}
