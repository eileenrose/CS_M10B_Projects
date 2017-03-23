// Eileen Buenaflor Fall 2016 CSM10B

#include <string>
using namespace std;

#include "Varray.h"

Varray::Varray( const int s ) {
	size = s;
	ptr = new Vehicle*[ s ];	
}

Varray::~Varray() {
	for ( int i{ 0 }; i < remain; ++i ) {
			delete ptr[ i ];
	} 
	delete [] ptr;
	ptr = nullptr;	
}

// I made a set function to get the remainder of size
// if user chose to not fill the allocated array
// I tried to use conditionals with nullptrs for deallocation but it didn't work
void Varray::set( int temp ) {
	remain = temp;
}

void Varray::type( int i ) {
	char type;
	bool valid = true;

	do {
		cout << "What kind of vehicle - car(c) or truck(t) -->  ";
		cin >> type;
		if ( type == 'c' ) {
			ptr[ i ] = new Car();
			valid = false;
		}
		else if ( type == 't' ) {
			*( ptr + i ) = new Truck();
			valid = false;
		}
		else {
			cout << type << " is not a legal vehicle type" << endl;
		}
	} while ( valid );
}


ostream & operator << ( ostream &out, const Vehicle &v ) {
	cout << v.draw() << endl << v.get();
	return out;
}

Vehicle& Varray::operator [] ( int element ) {
	return *( ptr[ element ] );
	// placement of parentheses can save coders 2 hours 
}