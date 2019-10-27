//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca

#ifndef SDDS_PARKINGSPOT_H__
#define SDDS_PARKINGSPOT_H__

namespace sdds {
	//const int size = 9;
	struct ParkingSpot {
		char license_plate_of_car[9];
		char* model_of_car = nullptr;
	};

	void setEmpty(ParkingSpot&);
	bool isEmpty(const ParkingSpot&);
	void freeSpot(ParkingSpot&);
	void print(const ParkingSpot&);
	void parkCar(ParkingSpot&);

}

#endif // !SDDS_PARKINGSPOT_H__


