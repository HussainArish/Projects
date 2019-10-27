//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca

#ifndef SDDS_PARKINGLOT_H__
#define SDDS_PARKINGLOT_H__
#include "ParkingSpot.h"

namespace sdds {
	struct ParkingLot {

		int number_of_parkingspot;
		ParkingSpot* parkingspots;

	};
	void setEmpty(ParkingLot&);
	bool isEmpty(const ParkingLot&);
	void openParking(ParkingLot&, int noOfSpots);
	int parkCar(ParkingLot&);
	bool returnCar(ParkingLot&, int spotNo);
	void closeParking(ParkingLot&);
}

#endif // !SDDS_PARKINGLOT_H__1