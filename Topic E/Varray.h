//Eileen Buenaflor Fall 2016 CSM10B

#pragma once
#include <iostream>
using namespace std;

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

#ifndef Varray_h
#define Varray_h

class Varray {

	friend ostream & operator << (ostream &, const Vehicle &);

public:
	Varray( int size = 0 );
	~Varray();

	void set( int );
	void type( int );

	Vehicle& operator[]( int );

	Vehicle** ptr;

private:

	int size;
	int remain;
	
	Varray( const Varray &y );
	// copy constructor private so client cannot use
};

#endif