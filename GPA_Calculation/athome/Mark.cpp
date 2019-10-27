//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Mark.h"
#include <cstring>
#include <iomanip>

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
		m_name[0] = '\0';
	}

	bool Mark::isEmpty()const {
		
		return m_mark == -1;
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

	ostream& Mark::display(int width) const {

		if (m_name[0] != '\0') {
			cout.width(width);
			cout.fill('.');
			cout.setf(ios::left);
			cout << m_name;
			cout.unsetf(ios::left);

		}
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else if (m_displayMode == DSP_RAW) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << rawValue();
			cout.unsetf(ios::fixed);
			cout.precision(2);
		}
		else if (m_displayMode == DSP_PERCENT) {
			cout << "%" << percent();
		}

		else if (m_displayMode == DSP_ASIS) {
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << m_mark << "/" << m_outOf;
			cout.unsetf(ios::fixed);
			cout.precision(1);
		}
		else if (m_displayMode == DSP_UNDEFINED) {
			cout << "Display mode not set!";
		}
		else if (m_displayMode == DSP_LETTER) {
			prnLetter();
		}
		else if (m_displayMode == DSP_GPA) {
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << GPA();
			cout.unsetf(ios::fixed);
			cout.precision(1);
		}
		else
		{
			cout << "Invalid Mark Display setting!";
		}
		return cout;
	}

	
	void Mark::prnLetter()const {
		if (!isEmpty()) {

			if (percent() >= 0 && percent() <= 49) {
				cout << "F";
			}

			else if (percent() >= 50 && percent() <= 54) {

				cout << "D";
			}

			else if (percent() >= 55 && percent() <= 59) {

				cout << "D+";
			}

			else if (percent() >= 60 && percent() <= 64) {

				cout << "C";
			}

			else if (percent() >= 65 && percent() <= 69) {

				cout << "C+";
			}

			else if (percent() >= 70 && percent() <= 74) {

				cout << "B";
			}

			else if (percent() >= 75 && percent() <= 79) {

				cout << "B+";
			}

			else if (percent() >= 80 && percent() <= 89) {

				cout << "A";
			}

			else if (percent() >= 90 && percent() <= 100) {

				cout << "A+";
			}

			else if (percent() > 100) {

				cout << "?";
			}
		}
	}

	void Mark::set(const char* name) {
	
		strcpy(m_name, name);
	}

	void Mark::set(const char* name, double rawMark, int outof) {

		set(name);
		set(rawMark, outof);
	}

	bool Mark::readName(const char* prompt, int maxLen) {
		bool success = true;
		cout << prompt;
		cin >> m_name;
	
		if(m_name[maxLen] > maxLen){
			cin.clear();
			flushKeyboard();
			m_name[0] = '\0';
			success = false;

		}
		return success;
	}

	void Mark::changeOutOf(int value) {

		m_outOf = value;
		double test = m_mark * (double(value) / m_outOf);

		if (test < 1) {

			setEmpty();

		}

	}

	double Mark::GPA()const {
		double gpa = 0.0;
		gpa = rawValue() * 4;
		return gpa;
	}

	double Mark::letterBasedGPA()const {
		double gpa = 0.0;

		if (percent() >= 0 && percent() <= 49) {

			
			gpa = 0.0;

		}
		else if (percent() >= 50 && percent() <= 54) {

			
			gpa = 1.0;
		}
		else if (percent() >= 55 && percent() <= 59) {

			
			gpa = 1.5;
		}
		else if (percent() >= 60 && percent() <= 64) {

			
			gpa = 2.0;
		}
		else if (percent() >= 65 && percent() <= 69) {

			
			gpa = 2.5;
		}
		else if (percent() >= 70 && percent() <= 74) {

			
			gpa = 3.0;
		}
		else if (percent() >= 75 && percent() <= 79) {

			
			gpa = 3.5;
		}
		else if (percent() >= 80 && percent() <= 89) {

			
			gpa = 4.0;
		}
		else if (percent() >= 90 && percent() <= 100) {

			
			gpa = 4.0;
		}

		return gpa;
	}

}




