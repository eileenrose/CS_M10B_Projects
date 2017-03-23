/*
Eileen Buenaflor

Topic B Project			CSM10B			Fall 2016

Status: Compiles and works

The class member-function definitions of Rational class
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Rational.h"
using namespace std;

// constructor
Rational::Rational( int numerator, int denominator ) {
	setFrac( numerator, denominator );
}

// inputs the ints into fraction
void Rational::setFrac( int n, int d ) {
	int gc = gcd( n, d );
	if ( d == 0 ) {
		gc = 1;
	} 
	// gcd method would return n if d was 0
	// thus n / n was 1
	setNum( n, gc );
	setDen( d, gc );
}

// finds greatest common divisor
int Rational::gcd( int a, int b ) {
	if ( b == 0 ) {
		return a;
	}
	else {
		return gcd( b, a % b );
	}
}

// finds the least common multiple
int Rational::lcm( int a, int b ) {
	return a / gcd( a, b ) * b;
}

// inputs and reduces the numerator
void Rational::setNum( int n, int gc ) {
	n /= gc;
	numerator = n;
}

// inputs and reduces the denominator
void Rational::setDen( int d, int gc ) {
	if ( d == 0 ) {
		denominator = 1;
		cout << "0 cannot be a denominator. Changing to 1\n" << endl;
	}
	else {
		d /= gc;
		denominator = d;
	}
}

// adds two non-pointer Rational classes
void Rational::add( Rational &r1, Rational &r2 ) {
	int d = lcm( r1.getDenominator(), r2.getDenominator() );
	int n = ( r1.getNumerator() * ( d / r1.getDenominator() ) ) 
		+ ( r2.getNumerator() * ( d / r2.getDenominator() ) );
	
	numerator = n;
	denominator = d;
}

// adds a pointer Rational class with a non-pointer
void Rational::add(Rational* &r1, Rational &r2) {
	int d = lcm( r1->getDenominator(), r2.getDenominator() );
	int n = ( r1->getNumerator() * ( d / r1->getDenominator() ) ) 
		+ ( r2.getNumerator() * ( d / r2.getDenominator() ) );

	numerator = n;
	denominator = d;
}

// subtracts two non-pointer Rational classes
void Rational::subtract( Rational &r1, Rational &r2 ) {
	int d = lcm( r1.getDenominator(), r2.getDenominator() );
	int n = ( r1.getNumerator() * ( d / r1.getDenominator() ) ) 
		- ( r2.getNumerator() * ( d / r2.getDenominator() ) );

	numerator = n;
	denominator = d;
}

// subtracts a pointer Rational class with a non-pointer
void Rational::subtract( Rational* &r1, Rational &r2 ) {
	int d = lcm( r1->getDenominator(), r2.getDenominator() );
	int n = ( r1->getNumerator() * ( d / r1->getDenominator() ) ) 
		- ( r2.getNumerator() * ( d / r2.getDenominator() ) );

	numerator = n;
	denominator = d;
}

// multiplies two non-pointer Rational classes
void Rational::multiply( Rational &r1, Rational &r2 ) {
	int num = r1.getNumerator() * r2.getNumerator();
	int den = r1.getDenominator() * r2.getDenominator();
	int gc = gcd( num, den );

	numerator = num / gc;
	denominator = den / gc;
}

// multiplies a pointer Rational class with a non-pointer
void Rational::multiply( Rational* &r1, Rational &r2 ) {
	int num = r1->getNumerator() * r2.getNumerator();
	int den = r1->getDenominator() * r2.getDenominator();
	int gc = gcd( num, den );

	numerator = num / gc;
	denominator = den / gc;
}

// divides two non-pointer Rational classes
void Rational::divide( Rational &r1, Rational &r2 ) {
	int num = r1.getNumerator() * r2.getDenominator();
	int den = r1.getDenominator() * r2.getNumerator();
	int gc = gcd( num, den );

	numerator = num / gc;
	denominator = den / gc;
}

// divides a pointer Rational class with a non-pointer
void Rational::divide( Rational* &r1, Rational &r2 ) {
	int num = r1->getNumerator() * r2.getDenominator();
	int den = r1->getDenominator() * r2.getNumerator();
	int gc = gcd( num, den );

	numerator = num / gc;
	denominator = den / gc;
}

// converts the two ints into a fraction form using a string
string Rational::toRationalString() const{
	string numer{ to_string( abs( numerator ) ) };
	string denomin{ to_string( abs( denominator ) ) };

	if (numerator < 0 || denominator < 0) {
		return "-" + numer + "/" + denomin;
	}
	else {
		return numer + "/" + denomin;
	}
}

// turns the fraction into a double
double Rational::toDouble() const {
	return double( numerator ) / double( denominator );
}

// prints a fraction
void Rational::printAsFrac() const {
	cout << toRationalString() << endl;
}

// prints a decimal
void Rational::printAsDec() const {
	cout << setprecision( 2 ) << fixed << toDouble() << endl;
}

// retrieves private data member numerator
int Rational::getNumerator() const {
	return numerator;
}

// retrieves private data member denominator
int Rational::getDenominator() const {
	return denominator;
}


 