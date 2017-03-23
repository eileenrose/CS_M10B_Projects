/*********************************************************
Eileen Buenaflor
CS M10B		Fall 2016
Topic C Project

Used Topic B Solution as base
*******************************************************/

#pragma once

#include <string>
#include <iostream>
using namespace std;

#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{

	friend ostream& operator<<( ostream&, const Rational& );

public:
	Rational( int num = 1, int dem = 1 );
	Rational( const Rational& ); // copy constructor
	~Rational(); // deconstructor

	inline int getDenominator() const {
		return denom;
	};
	inline int getNumerator() const {
		return *numer;
	};

	void setFraction( int num, int dem );
	Rational getFraction() const; 
	// I'm not sure if I can inline this since it's creating an object which might be too big


	Rational operator+( const Rational& ) const;
	Rational operator-( const Rational& ) const;
	Rational operator*( const Rational& ) const;
	Rational operator/( const Rational& ) const;

	// not const because data being modified
	Rational& operator+=( const Rational& );
	Rational& operator-=( const Rational& );
	Rational& operator*=( const Rational& );
	Rational& operator/=( const Rational& );
	
	const Rational& operator=( const Rational& );

	Rational& operator++(); // prefix
	Rational operator++( int ); // postfix

	bool operator==( const Rational& ) const;
	bool operator!=( const Rational& ) const;

	string toRationalString() const;
	void printAsDec() const;

	double toDouble() const;
	void printAsFract() const;

private:

	int* numer = new int;		
	int denom;

	void reduce();
};

#endif