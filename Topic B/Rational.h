/*
Eileen Buenaflor

Topic B Project			CSM10B			Fall 2016

Status: Compiles and works

The class declaration of Rational class
*/

#pragma once

#include <string>

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {

public:

	explicit Rational( int = 1, int = 1 ); // default constructor

	// set methods to change private data members
	void setFrac( int, int );
	void setNum( int, int );
	void setDen( int, int );

	// uses & to save memory
	void add( Rational&, Rational&);
	void subtract( Rational&, Rational& );
	void multiply( Rational&, Rational& );
	void divide( Rational&, Rational& );

	// overloading for pointer Rational
	void add( Rational*&, Rational& );
	void subtract( Rational*&, Rational& );
	void multiply( Rational*&, Rational& );
	void divide( Rational*&, Rational& );

	// accessor methods so that data is not accidentally modified
	int getNumerator() const;
	int getDenominator() const;

	std::string toRationalString() const; // conversion to string
	double toDouble() const; // conversion to double

	// print methods as instructed
	void printAsFrac() const;
	void printAsDec() const;

private:

	int numerator{ 1 };
	int denominator{ 1 };

	// helper functions
	int gcd( int, int );
	int lcm( int, int );
	// private since GCD and LCM aren't characteristics of the Rational class
};

#endif