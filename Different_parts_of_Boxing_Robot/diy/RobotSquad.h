
//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// RobotSquad.h
#ifndef SDDS_ROBOTSQUAD_H__
#define SDDS_ROBOTSQUAD_H__
#include"Parts.h"
#include"Robot.h"
namespace sdds
{
	class RobotSquad
	{

		char m_name[10];
		int m_count;
		Robot* roster;

	public:
		RobotSquad(const char* name = "No Name");
		RobotSquad& operator+=(const Robot& newRobot);
		RobotSquad& operator--();
		std::ostream& display() const; // display function
		Robot* getRoster() const; // get roster
		~RobotSquad(); // Destructor	
	};






}
#endif