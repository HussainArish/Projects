//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// RobotSquad.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"RobotSquad.h"
#include <cstring>
using namespace std;
namespace sdds
{

	RobotSquad::RobotSquad(const char* name)  : m_count(0), roster(nullptr){

			strcpy(m_name, name);
	
	}

	RobotSquad& RobotSquad::operator+=(const Robot& new_robot) {

		Robot* t_roster = new Robot[m_count + 1];

		for (int i = 0; i < m_count; i++) {

			t_roster[i] = roster[i];

		}

		delete[] roster;

		m_count++;
		roster = t_roster;
		roster[m_count - 1] = new_robot;

		return *this;

	}

	RobotSquad& RobotSquad::operator--() {

		if (roster == nullptr) {

			cout << "This squad **" << m_name << "** has no members or is uninitialized. Can't do --." << endl;

		}
		else {

			if (m_count == 0) {
				roster = nullptr;
			}
			else {

				Robot* t_roster = new Robot[m_count - 1];

				for (int i = 0; i < m_count - 1; ++i)
				{
					t_roster[i] = roster[i];
				}

				--m_count;

				delete[] roster;

				roster = t_roster;

			}
		}

		return *this;

	}

	std::ostream& RobotSquad::display() const {

		if (m_count == 0) {

			cout << "Squad **" << m_name << "** has no members" << endl;
		}
		else {

			cout << "***Squad Summary***" << endl;
			cout << "Name: " << m_name << endl;
			cout << "Roster Count: " << m_count << endl;
			cout << "Roster:" << endl;

			for (int i = 0; i < m_count; ++i) {

				roster[i].display();
			}
		}
		return cout;
	}


	Robot* RobotSquad::getRoster() const {

		return roster;

	}

	RobotSquad::~RobotSquad() {

		delete[] roster;

	}


}