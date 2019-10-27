//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MarksReport.h"
#include "Mark.h"
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

void  MarksReport::initialize() {

	Array_of_Marks = nullptr;
}

ostream& MarksReport::line(int len, char ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}
void MarksReport::listMarks(const Mark* marks, int num) {
	Mark result;
	result.setEmpty();
	double gpa = 0;
	
	int i;
	int highest_mark = 0;
	int lowest_mark = 0;

	//GPA calculation
	for (i = 0; i < num; i++) {
		marks[i].display(66) << endl;;
		gpa += marks[i].letterBasedGPA();
	}
	// calculating highest
	for (i = 0; i < num; ++i) {
		if (highest_mark < marks[i].percent()) {
			highest_mark = marks[i].percent();
		}
		else {
			highest_mark = 0;
		}
	}

	//calculating lowest 
	for (i = 0; i < num; ++i) {
		if (i == 0) {
			lowest_mark = marks[i].percent();
		}
		else if (lowest_mark > marks[i].percent()) {
		
			lowest_mark = marks[i].percent();
	}

	}


	line(70, '-') << endl;
	result.set(lowest_mark, 100);
	result.set(DSP_PERCENT);
	result.set("Lowest Mark");
	line(30, ' ');
	result.display(36);
	cout << endl;

	result.set(highest_mark, 100);
	result.set(DSP_PERCENT);
	result.set("Highest mark");
	line(30, ' ');
	result.display(36);
	cout << endl;

	result.set(gpa / num, 4);
	result.set(DSP_GPA);
	result.set("GPA");
	line(30, ' ');
	result.display(36) << endl;

}
//
void MarksReport::getMarks() {
	int no_of_marks = 0;
	char report_name[71];

	cout << "Enter the report Name: ";
	cin.getline(report_name, 71,'\n');
	strcpy(m_title, report_name);
	
	cout << "Enter the number of marks: ";

	cin >> no_of_marks;
	cin.clear();
	cin.ignore(1000, '\n');
	m_mark = no_of_marks;
	Array_of_Marks = new Mark[no_of_marks + 1];

	cout << "Please enter " << no_of_marks << " marks:" <<endl;

	for ( int i = 0; i < no_of_marks; i++) {
		Array_of_Marks[i].setEmpty();
		Array_of_Marks[i].set(DSP_LETTER);
		 cout << i + 1 << ": " ;
		while (!Array_of_Marks[i].readName("Subject Name: ", 6) || !Array_of_Marks[i].read("Mark (mark/outof): ")) {
			cout << "Invalid Entry, retry!" << endl;
			
			//Array_of_Marks[i].setEmpty();
			Array_of_Marks[i].set(DSP_LETTER);
			
			
		}
		
	}
	cout << "Entry Completed!" << endl;
	cout << endl;

}
void MarksReport::print() {

	cout << "----------------------------------------------------------------------" << endl;
	cout << m_title << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Marks entered:" << endl;
	listMarks(Array_of_Marks, m_mark);
}

void MarksReport::terminate() {
	delete [] Array_of_Marks;
	initialize();

}
}