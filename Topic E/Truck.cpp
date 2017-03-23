//Eileen Buenaflor Fall 2016 CSM10B

#include <iostream>
using namespace std;

#include "Truck.h"

Truck::Truck( int p ) {
	col = p;
}//dummy value

string Truck::draw() const {
	string starting = "";
	for ( int i{ 0 }; i < col; ++i ) {
		starting += " ";
	}

	string image = "";
	image += starting;
	image += "      |--------------------|\n";
	image += starting;
	image += "      |                    |\n";
	image += starting;
	image += "      |                    |\n";
	image += starting;
	image += "      |                    |\n";
	image += starting;
	image += "|--------------------------------|\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|                                |\n";
	image += starting;
	image += "|--------------------------------|\n";
	image += starting;
	image += " 0      00                  00\n";
	return image;
}

void Truck::set() {
	int g, n;
	bool valid = true;

	do {
		cout << "What is the gross tonnage of the truck(at least 1000) -->  ";
		cin >> g;
		cout << "What is the net tonnage of the truck (less than " << g << ") -->  ";
		cin >> n;
		if ( g < 1000 || n > g ) {
			cout << g << " and/or " << n << " are incorrect." << endl;
		}
		if ( g >= 1000 && n < g ) {
			gross = g;
			net = n;
			valid = false;
		}
	} while ( valid );
}

// dummy value to overload
void Truck::set( int ) {
	int column;
	bool valid = true;

	do {
		cout << "In which column should the display start (less than or equal to 35) -->  ";
		cin >> column;
		if ( column > 35 ) {
			cout << column << " cannot be used as a starting column for the display.\n" <<
				"Choose a value of 0 up to the correct limit." << endl;
		}
		if ( column <= 35 ) {
			col = column;
			valid = false;
		}
	} while ( valid );
}

string Truck::get() const {
	string space;
	for ( int i{ 0 }; i < col; ++i ) {
		space += " ";
	}
	return space + "Gross tonnage:  " + to_string( gross ) + "   Net tonnage:  " + to_string( net ) + "\n";
}