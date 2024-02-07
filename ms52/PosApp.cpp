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
#include "POS.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds
{
	//constructor
	PosApp::PosApp(const char* filename)
	{
		// set to safe empty state
		strcpy(m_FileName, filename);
		Iptr[0] = NULL;
		nptr = 0;
	}

	//load all the records of data file into Iptr
	void PosApp::load() {
		cout << ">>>> Loading Items..........................................................." << endl;
		ifstream input(m_FileName);
		if (!input) {
			ofstream output(m_FileName);
			output.close();
			return;
		}

		this->nptr = 0;
		this->Iptr[nptr] = nullptr;

		while (input.good() && this->nptr < MAX_NO_ITEMS) {
			char type;
			input >> type;
			input.ignore();

			Item* newItem = nullptr;

			if (type == 'N')
			{
				newItem = new NonPerishable;
			}
			else if (type == 'P')
			{
				newItem = new Perishable;
			}

			if (newItem != nullptr)
			{
				input >> *newItem;
				if (input.good())
				{
					this->Iptr[this->nptr++] = newItem;
					this->Iptr[this->nptr] = nullptr;
				}
				else 
				{
					delete newItem;
					newItem = nullptr;
				}
			}
			else
			{
				delete newItem;
				newItem = nullptr;
			}
		}

		input.close();
	}

	void PosApp::save() {
		cout << ">>>> Saving Data............................................................." << endl;

		
		cout << "Goodbye!" << endl;

		ofstream save(m_FileName);

		for (int i = 0; i < nptr; i++)
		{
			 Iptr[i]->save(save);
		}
	}

	void PosApp::listItems() {
		double totalAsset = 0.0;
		cout << ">>>> Listing Items..........................................................." << endl;
	
		
		bubbleItem(Iptr, nptr);
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;

		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
		int j = 1;
		for (int i = 0; i < nptr; i++)
		{
			
			cout.setf(ios::right);
			cout.width(4);
			cout.fill(' ');
			cout << j<< " | ";
			j++;
			cout.unsetf(ios::right);
			Iptr[i]->displayType(POS_LIST);
		
			Iptr[i]->write(cout);
			cout << endl;
			totalAsset += Iptr[i]->cost() * Iptr[i]->quantity();
		}
		// Print footer and total asset
		std::cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "                               Total Asset: $  |       ";
	 
		cout << setprecision(2) << totalAsset << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
	}

	void PosApp::addItem() {
		cout << ">>>> Adding Item to the store................................................" << endl;
		if (nptr >= MAX_NO_ITEMS) //check if full
		{
			cout << "Inventory Full!";
			return;
		}
		else // add item 
		{
			Item* tempItem = nullptr; // create a pointer to Item
			cout << "Is the Item perishable? (Y)es/(N)o: ";
			char Type;
			cin >> Type;
			cin.ignore();
			//dynamically allocate memory according to the selection
			if (Type == 'y' || Type == 'Y')
			{
				tempItem = new Perishable;
			}
			else if(Type == 'n' || Type == 'N')
			{
				tempItem = new NonPerishable;
			}
				tempItem->read(cin); //read the item

				if (!cin.good())//check if not in good state
				{
					cin.clear();
					cin.ignore();
					cout << *tempItem << ", try again...\n";
				}
				else // extract the item from the tempItem to Iptr
				{
					Iptr[nptr++] = tempItem;
					cout << ">>>> DONE!..................................................................." << endl;
					return;
				}
			
			
			
		}
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
			ostr << "5- POS" << endl;
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

	PosApp::~PosApp()
	{
		for (int i = 0; i < nptr; i++)
		{
			delete Iptr[i];
		}
	}
}