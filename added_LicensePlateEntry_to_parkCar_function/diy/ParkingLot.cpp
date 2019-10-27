//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ParkingLot.h"
#include "utils.h"
#include "ParkingSpot.h"
#include <cstring>
using namespace std;
namespace sdds {

	void setEmpty(ParkingLot& setempty) {
		setempty.number_of_parkingspot = 0;
		setempty.parkingspots = nullptr;
	}

	bool isEmpty(const ParkingLot& isempty) {
		
		bool result;
		
		isempty.parkingspots == nullptr ? result = true : result = false;

		return result;
	}

	void openParking(ParkingLot& openparking, int noOfSpots) {
		openparking.number_of_parkingspot = noOfSpots;
		openparking.parkingspots = new ParkingSpot[openparking.number_of_parkingspot]; // dynamically allocates "noOfspots" and keeping the address in parkingspot.
		for (int i = 0; i < openparking.number_of_parkingspot; i++) {
			setEmpty(openparking.parkingspots[i]);
		}
	}

	int parkCar(ParkingLot& parkingcar) {
		bool result;
		int returning_value = 0;
		
		for (int i = 0; i < parkingcar.number_of_parkingspot; i++) {
			result = isEmpty(parkingcar.parkingspots[i]);
			if (result == true) {
		
				parkCar(parkingcar.parkingspots[i]);
				returning_value = i;
			
				break;
			}
			else
			{
				returning_value = -1;
			}
		}
		return returning_value;
	}
	
	

	bool returnCar(ParkingLot& returningcar, int spotNo) {
	
		bool result;
		if (spotNo >= 0 && spotNo < returningcar.number_of_parkingspot && !isEmpty(returningcar.parkingspots[spotNo])) {
			cout << "Returning ";
			print(returningcar.parkingspots[spotNo]);
			freeSpot(returningcar.parkingspots[spotNo]);
			result =  true;
		}
		else {
			result = false;
		}
		return result;
	}

	void closeParking(ParkingLot& car) {
		for (int i = 0; i < car.number_of_parkingspot; i++) {
			if (!isEmpty(car.parkingspots[i])) {
				returnCar(car, i);
			}
		}
		delete[] car.parkingspots;
		setEmpty(car);
	}


}