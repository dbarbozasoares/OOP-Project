/*/////////////////////////////////////////////////////////////////////////
						 Milestone 1
Full Name  : Diego Barboza Soares
Student ID#: 145820239
Email      : dbarboza-soares@myseneca.ca
Section    : NII
Date       : 20th March 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "Menu.h"

using namespace std;

namespace seneca {
	// Default constructor
	Menu::Menu(){
		this->m_menuContent = nullptr;
		this->m_numberOfOptions = 0;
		this->m_numberOftabs = 0;
	}

	// overloaded constructor
	Menu::Menu(const char* menuContent, int numberOfTabs){
		this->m_numberOfOptions = 0;
		this->m_numberOftabs = numberOfTabs;

		if (menuContent != nullptr) {
			// Allocate memory for menu content based on menuContent length
			this->m_menuContent = new char[strlen(menuContent) + 1];
			strcpy(this->m_menuContent, menuContent);

			for (int i = 0; i < (int)strlen(menuContent); i++)
			{
				if (menuContent[i] == '\n') {
					this->m_numberOfOptions++;
				}
			}
			this->m_numberOftabs = numberOfTabs;
		}
		else {
			// Set pointer to safe state
			this->m_menuContent = nullptr;
		}
	}

	// Deconstructor
	Menu::~Menu()
	{
		delete[] this->m_menuContent;
		this->m_menuContent = nullptr;
	}

	// Print number of tabs from current numberOfTabs
	void Menu::printTabs(ostream& ostr) const
	{
		for (int j = 0; j < (this->m_numberOftabs * 3); j++)
		{
			ostr << ' ';
		}
	}

	// Output menu to an output stream parameter
	void Menu::display(ostream& ostr) const
	{
		this->printTabs(ostr);

		// For each character in menuContent, print it
		for (int i = 0; i < (int)strlen(this->m_menuContent); i++)
		{
			if (this->m_menuContent[i] != '\n') {
				ostr << this->m_menuContent[i];
			}
			else {
				ostr << '\n';
				// Print tabs
				this->printTabs(ostr);
			}
		}
		ostr << '\n';
		// Print tabs
		this->printTabs(ostr);
		ostr << "0- Exit\n";
	}

	// Get user input
	int& Menu::operator>>(int& Selection) const
	{
		string tempSelection;
		bool isValid = false;
		this->display();
		this->printTabs(cout);
		cout << "> ";

		do
		{
			getline(cin, tempSelection);
			bool flag = false;

			for (int i = 0; i < (int)tempSelection.size() && flag == false; i++)
			{
				if (isalpha(tempSelection[i]) != 0) {
					cout << "Bad integer value, try again: ";
					flag = true;
				}
			}
			if (flag == false) {
				if (tempSelection.back() == ' ') {
					cout << "Only enter an integer, try again: ";
				}
				else {
					if (stoi(tempSelection) < 0 || stoi(tempSelection) > this->m_numberOfOptions) {
						cout << "Invalid value enterd, retry[0 <= value <= " << this->m_numberOfOptions << "]: ";
					}
					else {
						Selection = stoi(tempSelection);
						isValid = true;
					}
				}
			}

		} while (isValid == false);

		return Selection;
	}

}