/*
*****************************************************************************
						  Final Project Milestone - #1

Name: Monilkumar Kishorbhai Patel
Student No: 156199218
Email: mpatel450@myseneca.ca
Date: 11/03/23

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "PosApp.h"

using namespace std;

namespace sdds
{
	//constructor
	PosApp::PosApp(const char* filename)
	{
		
		strcpy(m_FileName, filename);

	}

	
	void PosApp::load() {
		cout << ">>>> Loading Items..........................................................." << endl;
		cout << "Loading data from " << m_FileName << endl;
	}

	void PosApp::save() {
		cout << ">>>> Saving Data............................................................." << endl;
		cout << "Saving data in " << m_FileName << endl;
		cout << "Goodbye!" << endl;
	}

	void PosApp::listItems() {
		cout << ">>>> Listing Items..........................................................." << endl;
		cout << "Running listItems()" << endl;
	}

	void PosApp::addItem() {
		cout << ">>>> Adding Item to the store................................................" << endl;
		cout << "Running addItem()" << endl;
	}

	void PosApp::removeItem() {
		cout << ">>>> Remove Item............................................................." << endl;
		cout << "Running removeItem()" << endl;
	}

	void PosApp::stockItem() {
		cout << ">>>> Select an item to stock................................................." << endl;
		cout << "Running stockItem()" << endl;
	}

	void PosApp::POS() {
		cout << ">>>> Starting Point of Sale.................................................." << endl;
		cout << "Running POS()" << endl;
	}

	// implement the actions by calling methods
	void PosApp:: run()
	{
	    load();
		menu();
	}

	// // to validate integer input
	istream& PosApp:: integerInput(istream& istr, int& input)const {

	istr >> input;
	if (istr.fail()) 
	{
		istr.clear();
		istr.ignore(1000, '\n');
		cout << "Invalid Integer, try again: ";
	integerInput(istr, input);
	}
	else if (input < 0 || input > 5) {
		cout << "[0<=value<=5], retry: > ";
		integerInput(istr, input);
	}
	return istr;
}


	//Displays the menu of system acc to user input
	ostream& PosApp::menu( ostream& ostr)
	{
		int input = -1;
		while (input != 0)
		{
			ostr << "The Sene-Store" << endl;
			ostr << "1- List items" << endl;
			ostr << "2- Add item" << endl;
			ostr << "3- Remove item" << endl;
			ostr << "4- Stock item" << endl;
			ostr << "5- Point of Sale" << endl;
			ostr << "0- exit program" << endl;
			ostr << "> ";

			integerInput(cin, input);

			switch (input)
			{
			case 1:
				listItems();
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				POS();
				break;
			case 0:
				save();
				break;
			default:
				break;
			}
		}
		return ostr;
	}
}