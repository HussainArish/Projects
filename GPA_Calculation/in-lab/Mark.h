//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
#ifndef SDDS_MARK_H__
#define SDDS_MARK_H__
#include <iostream>
namespace sdds {

const int DSP_RAW = 1;
const int DSP_PERCENT = 2;
const int DSP_ASIS = 3;
const int DSP_UNDEFINED = -1;


class Mark {

	int m_displayMode;
	double  m_mark;
	int  m_outOf;

	void flushKeyboard()const;

public: 

	void set(int diaplayMode);
	void set(double mark, int outOf = 1);
	void setEmpty();
	bool isEmpty()const;
	int percent()const;
	double rawValue()const;
	bool read(const char* prompt);
	std::ostream& display() const;

	};

}











#endif

