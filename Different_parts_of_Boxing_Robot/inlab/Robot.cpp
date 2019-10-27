//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Robot.h"
#include <cstring>
using namespace std;
namespace sdds{


	Robot::Robot() {

		m_durability = 0;
		strcpy(m_nickname, "");
	}

	Robot::Robot(const char* nickname, int arms_force, int robot_durability) {

		if (nickname == nullptr || nickname[0] == '\0')
		{
			m_durability = 0;
			strcpy(m_nickname, "");
		}

		else {

			strlen(nickname) > NICK_MAX_LEN? strncpy(m_nickname, nickname, NICK_MAX_LEN + 1) : strncpy(m_nickname, nickname, strlen(nickname) + 1);
		
			robot_durability < 1? m_durability = 100 : m_durability = robot_durability;
			
			m_Arms = arms_force;
		}
	}

	ostream& Robot::display() const {

		if (*this) {
			cout << "This Robot isn't operational" << endl;
		}
		else {

			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << m_nickname << endl;
			cout << "Arm Power: " << m_Arms.getForce() << endl;
			cout << "Durability: "<< m_durability << endl;
		}

		return cout;
	}


	Robot::operator bool() const {
		bool result;

		m_durability == 0 || m_nickname[0] == '\0'? result = true : result = false;

		return result;

	}





}