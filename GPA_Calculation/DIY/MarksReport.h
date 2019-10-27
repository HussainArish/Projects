//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
#ifndef SDDS_MARKSREPORT_H__
#define SDDS_MARKSREPORT_H__
#include <iostream>
#include"Mark.h"
namespace sdds {

	

	class MarksReport {

		double  m_mark;
		char m_title[71];
		Mark* Array_of_Marks;

	
		
	public:

		void initialize();
		void getMarks();
		void print();
		void terminate();
		void listMarks(const Mark* marks, int num);
		std::ostream& line(int len, char ch);
	};



}

#endif