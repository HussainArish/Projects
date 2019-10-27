//Syed Hussain Arish Rizvi
//sharizvi@myseneca.ca
//139190177
#ifndef SDDS_SUBJECT_H__
#define SDDS_SUBJECT_H__
namespace sdds {

	struct Subject {
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};

	void read(char*);
	void read(int&);
	void read(int[], int);
	void read(Subject&);
	int report(const Subject&);
	void freeMem(Subject&);
}

#endif

