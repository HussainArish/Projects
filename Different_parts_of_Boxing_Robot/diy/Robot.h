//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Robot.h
#ifndef SDDS_ROBOT_H__
#define SDDS_ROBOT_H__
#include"Parts.h"
namespace sdds
{
	const int NICK_MAX_LEN = 10;

	class Robot
	{
		char m_nickname[NICK_MAX_LEN];
		int m_durability;
		Arms m_Arms;
		Legs legs;

	public:
		Robot();
		Robot(const char* robot, int arms_force, int leg_speed, int robot_durability);
		std::ostream& display() const;
		operator bool() const;
		Arms getArms() const;
		Legs getLegs() const;
		Robot& operator-=(int);
	};

	void box(Robot&, Robot&);

}


#endif

