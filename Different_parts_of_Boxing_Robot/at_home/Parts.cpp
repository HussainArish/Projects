//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Parts.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Parts.h"
#include <cstring>
using namespace std;
namespace sdds
{

	Arms::Arms() {

		m_force = 0;

	}

	Arms::Arms(int force_arms) : m_force(MIN_FORCE) {

		force_arms < 1 ? force_arms = MIN_FORCE : m_force = force_arms;

	}

	int Arms::getForce() const {

		return m_force;

	}

	Arms& Arms::operator++() {
		return(*this) += 10;
	}

	Arms Arms::operator++(int) {

		Arms F_S = *this;
		*this += (10);
		return F_S;

	}

	Arms& Arms::operator+=(int value) {
		m_force += value;

		if (m_force < 1) {

			value = 0;
		}
		return *this;

	}


	Legs::Legs() {

		speed = 0;

	}

	Legs::Legs(int leg_speed) {

		leg_speed < 1 ? speed = MIN_SPEED : speed = leg_speed;

	}

	int Legs::getSpeed() const {

		return speed;
	}

	Legs& Legs::operator-=(int value) {

		speed -= value;

		if (speed < 1) {

			speed = 0;
		}
		return *this;
	}

	bool operator>(const Legs& first, const Legs& second) {

		bool result;
		first.getSpeed() > second.getSpeed() ? result = true : result = false;
		return result;

	}

	bool operator<(const Legs& first, const Legs& second) {
		bool result;
		first.getSpeed() < second.getSpeed() ? result = true : result = false;
		return result;

	}

	bool operator>(const Arms& first, const Arms& second) {
		bool result;
		first.getForce() > second.getForce() ? result = true : result = false;
		return result;

	}

	bool operator<(const Arms& first, const Arms& second) {
		bool result;
		first.getForce() < second.getForce() ? result = true : result = false;
		return result;
	}




}