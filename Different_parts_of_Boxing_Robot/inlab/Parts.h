//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca
// Parts.h
#ifndef SDDS_PART_H__
#define SDDS_PART_H__

namespace sdds
{
const int MIN_FORCE = 50;

class Arms{

	int m_force;

public:

	Arms();
	Arms(int force_arms);
	int getForce() const;
	Arms& operator++();
	Arms operator++(int);
	Arms& operator+=(int);

};



}


#endif