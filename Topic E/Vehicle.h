//Eileen Buenaflor Fall 2016 CSM10B

#pragma once

#include <string>
using namespace std;

#ifndef Vehicle_h
#define Vehicle_h

class Vehicle {
public:

	virtual string draw() const = 0;
	virtual void set() = 0;
	virtual void set( int ) = 0;
	virtual string get() const = 0;
	//abstract base class

};

#endif
