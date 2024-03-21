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
#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

namespace seneca {
	class Time {
		int m_minutes;
	public:
		Time& reset();// Resets time to current time in minutes
		Time(unsigned int min = 0u);// Default constructor
		Time(Time& copy);// Copy constructor
		ostream& write(ostream& os) const; // Display time in HH:MM format
		istream& read(istream& is); // Reads input from user and ensure it is divided by ':', if not sets istream to failure state
		operator unsigned int()const; // Cast to assign an unsigned integer
		Time& operator*= (int val); // Overload multiplication sign
		Time& operator-= (const Time&); // Subtraction overload operator
		Time operator-(const Time&)const; // Subtraction overload without changing current object's value

		friend ostream& operator<<(ostream& ostr, const Time& time);// Friend output overload operator to read from an output stream
		friend istream& operator>>(istream& istr, Time& time); // Friend extraction operator to write to a input stream
	};

}
#endif // !SENECA_TIME_H
