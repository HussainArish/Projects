//Syed Hussain Arish Rizvi
//sharizvi@myseneca.ca
//139190177
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Subject.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds {

	void read(char* subject_name) {
		cout << "Enter subject name: ";

		read(subject_name, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
	}

	void read(int& no_of_sections) {
		cout << "Enter number of sections: ";


		read(no_of_sections, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
	}

	void read(int noofstud[], int no_of_sections) {


		cout << "Enter the number of students in each one of the " << no_of_sections << " sections:" << endl;
		for (int i = 0; i < no_of_sections; i++) {
			cout << i + 1 << ": ";
			read(noofstud[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}

	}
	void read(Subject& Sub) {
		char name[71];
		read(name);
		Sub.m_subjectName = new char[strlen(name) + 1];
		strcpy(Sub.m_subjectName, name);

		Sub.m_noOfSections = new int;
		read(*Sub.m_noOfSections);


		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);

	}
	int report(const Subject& Sub) {

		int totalArr = 0;
		int j = 1;
		for (int i = 0; i < *Sub.m_noOfSections; i++)
		{
			cout << Sub.m_noOfStdsInSecs[i];

			if (j < *Sub.m_noOfSections) {
				cout << ",";
				j++;

			}


			totalArr += Sub.m_noOfStdsInSecs[i];
		}

		cout << endl;
		cout << Sub.m_subjectName << ": " << totalArr << endl;

		return totalArr;

	}

	void freeMem(Subject& freeMem) {

		delete freeMem.m_noOfSections;
		delete[] freeMem.m_noOfStdsInSecs;
		delete[] freeMem.m_subjectName;

	}

}