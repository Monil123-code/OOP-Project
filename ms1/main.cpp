// Final Project Milestone 2
// Student POS App Mockup tester
// Version 1.0
// Date	2023-02-28
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the PosApp class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include "PosApp.h"
int main() {
   sdds::PosApp pos("datafile.csv");
   pos.run();
   return 0;
}
