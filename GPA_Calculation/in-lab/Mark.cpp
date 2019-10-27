//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Mark.h"

using namespace std;

namespace sdds {

	void Mark::flushKeyboard()const {
		char ch;
		do {
			ch = cin.get();

		} while (ch != '\n');

	}

	void Mark::set(int displayMode) {

		m_displayMode = displayMode;

	}
	void Mark::set(double mark, int outOf) {
		
		m_mark = mark;
		m_outOf = outOf;

	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
	}

	bool Mark::isEmpty()const {
		bool returning_val;

		if (m_mark == -1 && m_outOf == 100 && m_displayMode == DSP_UNDEFINED) {

			returning_val = true;
		}
		else {
			returning_val = false;
		}
		return returning_val;
	}

	int Mark::percent()const {
	

		int total = ((m_mark / m_outOf) * 100) + 0.5;
		return total;
		
	}


	double Mark::rawValue()const {

		double total_div;

		total_div = m_mark / m_outOf;

		return total_div;

	}

	bool Mark::read(const char* prompt) {
		
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			success = false;
		}
		flushKeyboard();
		return success;
	}

	ostream& Mark::display() const {
		
		if ( isEmpty()) {
			cout << "Empty Mark object!";
		}
			//else if (m_mark != isEmpty()) {
		else if (m_displayMode == DSP_RAW) {
		cout << rawValue();
		}
		else if (m_displayMode == DSP_PERCENT) {
		cout << "%" << percent();
		}
		else if (m_displayMode == DSP_ASIS) {
		cout << m_mark << "/" << m_outOf;
		}
		else if (m_displayMode == DSP_UNDEFINED) {
		cout << "Display mode not set!";

		}
		
		else 
			//if(*m_displayMode != DSP_UNDEFINED && *m_displayMode != DSP_ASIS && *m_displayMode != DSP_PERCENT) {
		{
			cout << "Invalid Mark Display setting!";


		}
		return cout;
	}
}
		
	


