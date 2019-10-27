//Syed Hussain Arish Rizvi
//sharizvi@myseneca.ca
//139190177
#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__
#include "Subject.h"
namespace sdds {

	struct School {
		int m_noOfSubjects;
		Subject* m_subjects;
		char* m_name;
	};

	void read(School&);
	int report(const School&);
	void freeMem(School&);
}



#endif

