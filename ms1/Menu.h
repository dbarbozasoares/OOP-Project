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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_
#define SENECA_MENU_H_

using namespace std;

namespace seneca {
	class Menu {
		char* m_menuContent;
		int m_numberOfOptions;
		int m_numberOftabs;

		Menu(Menu& Copy) = delete; // Disable copy constructor
		Menu operator=(Menu& copy) = delete; // Disable copy assignment
		void printTabs(ostream& ostr = cout) const; // Print number of tabs from current numberOfTabs 

	public:
		Menu(); // Default constructor
		Menu(const char* menuContent, int numberOfTabs = 0); // overloaded constructor
		~Menu(); // Deconstructor
		void display(ostream& ostr = cout) const; // Print number of tabs from current numberOfTabs
		int& operator>>(int& Selection) const;// Get user input
	};
}

#endif // !SENECA_MENU_H_
