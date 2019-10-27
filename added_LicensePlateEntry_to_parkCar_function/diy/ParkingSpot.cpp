//Syed Hussain Arish Rizvi
//student id = 139190177
//email = sharizvi@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ParkingSpot.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds {

	void setEmpty(ParkingSpot& setempty) {
		setempty.license_plate_of_car[0] = '\0';
		setempty.model_of_car = nullptr;
	
	}

	bool isEmpty(const ParkingSpot& isempty) {
		bool result;

		isempty.model_of_car == nullptr ? result = true : result = false;

		return result;
	
	}

	void freeSpot(ParkingSpot& freespot) {
		delete[] freespot.model_of_car;
		setEmpty(freespot);// calling the setEmpty function.
		
	}

	void print(const ParkingSpot& numberplate) {

		cout << numberplate.model_of_car <<", plate number: " << numberplate.license_plate_of_car << endl; // prompt to enter plate number.
	}
	
	void parkCar(ParkingSpot& modelname) {
		modelname.model_of_car = new char[61];
		cout << "Make and Model: ";
		read(modelname.model_of_car, 61, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
		cout << "License Plate: ";
		read(modelname.license_plate_of_car, 9, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");
		
	}
}

