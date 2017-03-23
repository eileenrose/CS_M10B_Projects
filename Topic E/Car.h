//Eileen Buenaflor Fall 2016 CSM10B

#pragma once
#include <string>
using namespace std;
#include "Vehicle.h"


#ifndef Car_h
#define Car_h

class Car : public Vehicle {

public:

	Car( int = 0 );

	virtual string draw() const override;
	virtual void set() override;
	virtual void set( int ) override;
	virtual string get() const override;

private:

	string model;
	int col;
};


#endif