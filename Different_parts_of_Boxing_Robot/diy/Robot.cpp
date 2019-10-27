//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Robot.h"
#include <cstring>
using namespace std;
namespace sdds
{

	Robot::Robot() {

		m_durability = 0;
		strcpy(m_nickname, "");
	}

	Robot::Robot(const char* nickname, int arms_force, int leg_speed, int robot_durability) {

		if (nickname == nullptr || nickname[0] == '\0')
		{
			m_durability = 0;
			strcpy(m_nickname, "");
		}

		else {

			strlen(nickname) > NICK_MAX_LEN ? strncpy(m_nickname, nickname, NICK_MAX_LEN + 1) : strncpy(m_nickname, nickname, strlen(nickname) + 1);

			robot_durability < 1 ? m_durability = 100 : m_durability = robot_durability;

			m_Arms = arms_force;
			legs = leg_speed;
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
			cout << "Durability: " << m_durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;
		}

		return cout;
	}


	Robot::operator bool() const {
		bool result;

		m_durability == 0 || m_nickname[0] == '\0' ? result = true : result = false;

		return result;

	}


	Arms Robot::getArms() const {

		return m_Arms;

	}

	Legs Robot::getLegs() const {

		return legs;
	}


	Robot& Robot::operator-=(int value) {

		m_durability -= value;

		if (m_durability < 1) {

			m_durability = 0;

		}

		return *this;
	}

	void box(Robot& f_robort, Robot& s_robort) {

		cout << "Attempting to begin a Robot boxing match" << endl;

		if (f_robort || s_robort) {
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}
		else {
			cout << "Both participants are operational... beginning the bout" << endl;

			while (!f_robort && !s_robort) {

				if (f_robort.getLegs().getSpeed() > s_robort.getLegs().getSpeed()) {

					s_robort -= f_robort.getArms().getForce();

					if (!s_robort) {

						f_robort -= s_robort.getArms().getForce();

					}
				}
				else {
					f_robort -= s_robort.getArms().getForce();


					if (!f_robort) {
						s_robort -= f_robort.getArms().getForce();

					}
				}

			}

			if (!f_robort) {

				cout << "The bout has concluded... the winner is: " << endl;
				f_robort.display();

			}
			else if (!s_robort) {


				cout << "The bout has concluded... the winner is: " << endl;
				s_robort.display();

			}
			else {
				cout << "No bout will begin" << endl;
			}


		}

	}
}




