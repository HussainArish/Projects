//Syed Hussain Arish Rizvi
//sharizvi@myseneca.ca
//139190177
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "School.h"
#include "utils.h"
#include "Subject.h"
using namespace std;
namespace sdds {

	void read(School& Sch) {
		char schoolname[61];
		
		cout << "Please enter the name of the school:\n> ";
		read(schoolname, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");
		Sch.m_name = new char[strlen(schoolname) + 1]; //dynamically allocation of memory 
		strcpy(Sch.m_name, schoolname);// copies name from school name to Sch.m_name.

		cout << "Please enter the number of subjects offered by "<< Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");
		
		Sch.m_subjects = new Subject[Sch.m_noOfSubjects]; 

		//Sch.m_subjects = new int[Sch.m_noOfSubjects];
			for (int i = 0; i < Sch.m_noOfSubjects; i++) {
				cout << i + 1 << ")";
				cout << " ------------------------------" << endl; 
				
				read(Sch.m_subjects[i]);
			}
			
		}
	int report(const School& rprt) {
		int total = 0;
		cout << rprt.m_name << endl;// print the name of the School
		cout << "Subject Enrollments" << endl;
		//loop
		for (int i = 0; i < rprt.m_noOfSubjects; i++) {
			//report(rprt.m_subjects[i]);
			total += report(rprt.m_subjects[i]); // adding the total enrollment.
		}

		cout << "Total enrollment: " << total << endl;

		return 0;

	}

	void freeMem(School& free) {
		delete[] free.m_name;
		//loop
		
			for (int i = 0; i < free.m_noOfSubjects; ++i) {
				/*delete Subject[i];
				delete[] array;*/
			freeMem(free.m_subjects[i]);
			}
		
		delete[] free.m_subjects;
	}

	}

