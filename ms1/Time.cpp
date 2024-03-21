#include <iomanip>
#include "Time.h"
#include "Utils.h"

using namespace std;

namespace seneca {
	// Default constructor
	Time::Time(unsigned int min)
	{
		m_minutes = min;
	}
	// Copy constructor
	Time::Time(Time& time)
	{
		this->m_minutes = time.m_minutes;
	}
	// Resets time to current time in minutes
	Time& Time::reset()
	{
		m_minutes = U.getTime();

		return *this;
	}

	// Reads input from user and ensure it is divided by ':', if not sets istream to failure state
	istream& Time::read(istream& istr)
	{
		int hours = 0;
		int minutes = 0;
		char seperator = ' ';

		cin >> hours;
		cin.get(seperator);

		// If the seperator is not valid
		if (seperator != ':') {
			if (seperator == '\n') {
				cin.putback('\n');
			}
			istr.setstate(ios::failbit); // Set stream state to failure
		}
		else {
			cin >> minutes;

			// If cin fail, set stream state to failure
			if (cin.fail()) {
				istr.setstate(ios::failbit);
			}
			else {
				m_minutes = ((hours * 60) + minutes);
			}
		}

		return istr;
	}

	// Display time in HH:MM format 
	ostream& Time::write(ostream& ostr) const
	{
		// Calculate hours and remaining minutes from current object value
		int hours = m_minutes / 60;
		int minutes = m_minutes - (hours * 60);
		ostr << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes;

		return ostr;
	}

	//  Cast to assign an unsigned integer
	Time::operator unsigned int() const
	{
		return m_minutes;
	}

	// Overload multiplication sign
	Time& Time::operator*=(int val)
	{
		m_minutes *= val;
		return *this;
	}

	// Subtraction overload operator
	Time& Time::operator-=(const Time& D)
	{
		m_minutes -= D.m_minutes;
		// If the result of the subtraction makes minutes negative, simply add 24 hours
		if (m_minutes <= -1) {
			m_minutes += 1440;
		}
		return *this;
	}

	// Subtraction overload without changing current object's value
	Time Time::operator-(const Time& T) const
	{
		Time tempTime(this->m_minutes); // Create temp Time object
		tempTime -= T.m_minutes;

		return tempTime;
	}

	// Friend extraction operator to write to a input stream
	istream& operator>>(istream& istr, Time& time)
	{
		return time.read(istr);
	}

	// Friend output overload operator to read from an output stream
	ostream& operator<<(ostream& ostr, const Time& time)
	{
		return time.write(ostr);
	}
}