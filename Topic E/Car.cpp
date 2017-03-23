//Eileen Buenaflor Fall 2016 CSM10B

#include <iostream>
using namespace std;

#include "Car.h"

Car::Car( int p ) {
	col = p;
} //dummy value

string Car::draw() const {
	string starting = "";
	for ( int i{ 0 }; i < col; ++i ) {
		starting += " ";
	}

	string image = "";
	image += starting;
	image += "      |-------|\n";
	image += starting;
	image += "      |       |\n";
	image += starting;
	image += "      |       |\n";
	image += starting;
	image += "      |       |\n";
	image += starting;
	image += "|-------------------|\n";
	image += starting;
	image += "|                   |\n";
	image += starting;
	image += "|                   |\n";
	image += starting;
	image += "|-------------------|\n";
	image += starting;
	image += "     0            0\n";
	
	return image;
}

void Car::set() {
	string m;
	cout << "What model is the car -->  ";
	cin >> m;
	model = m;
}

//dummy value to overload
void Car::set( int ) {
	int column;
	bool valid = true;
	
	do {
		cout << "In which column should the display start (less than or equal to 53) -->  ";
		cin >> column;
		col = column;
		if ( column > 53 ) {
			cout << column << " cannot be used as a starting column for the display.\n" <<
				"Choose a value of 0 up to the correct limit." << endl;
		}
		if ( column <= 53 ) {
			col = column;
			valid = false;
		}
	} while ( valid );
}



string Car::get() const {
	string space;
	for ( int i{ 0 }; i < col; ++i ) {
		space += " ";
	}
	return space + "Car model is " + model + "\n";
}