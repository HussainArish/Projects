//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Parts.h
#ifndef SDDS_PART_H__
#define SDDS_PART_H__

namespace sdds
{
	const int MIN_FORCE = 50;
	const int MIN_SPEED = 25;
	class Arms
	{

		int m_force;

	public:

		Arms();
		Arms(int force_arms);
		int getForce() const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);

	};

	class Legs
	{

		int speed;

	public:
		Legs();
		Legs(int leg_speed);
		int getSpeed() const;
		Legs& operator-=(int);
	};

	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);
}


#endif