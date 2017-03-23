//Eileen Buenaflor Fall 2016 CSM10B

#pragma once
#include <string>
using namespace std;

#include "Vehicle.h"

#ifndef Truck_h
#define Truck_h

class Truck : public Vehicle {

public:

	Truck( int = 0 );

	virtual string draw() const override;
	virtual void set() override;
	virtual void set(int) override;
	virtual string get() const override;

private:

	int gross;
	int net;
	int col;
	
};

#endif