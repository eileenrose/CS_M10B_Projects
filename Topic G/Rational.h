/*****************************************************
	CS M10B
	Topic C Project

	Rational class header file
*******************************************************/

#include <iostream>

using namespace std;

class Rational
{
	friend ostream & operator << ( ostream &, const Rational & );

public:
	Rational( int , int );
	inline Rational() {
		numer = new int{ 1 };
		denom = 1;
	}
	Rational( const Rational &r );
	~Rational() { delete numer; }

	int getDenominator() const
		{ return denom; }
	int getNumerator() const
		{ return *numer; }
	void setFraction( int num, int dem );
	Rational getFraction() const;

	Rational operator + ( const Rational &fract ) const;
	Rational operator - ( const Rational &fract ) const;
	Rational operator * ( const Rational &fract ) const;
	Rational operator / ( const Rational &fract ) const;

	const Rational & operator = ( const Rational & );
	const Rational & operator += ( const Rational & );
	const Rational & operator -= ( const Rational & );
	const Rational & operator *= ( const Rational & );
	const Rational & operator /= ( const Rational & );

	Rational & operator ++ ();
	Rational operator ++ ( int );

	bool operator == ( const Rational & ) const;
	bool operator != ( const Rational & ) const;

	string  toRationalString() const;
	double toDouble() const;

private:
	int *numer, denom;
	void reduce();
	void printAsFract( ostream & ) const;
	void printAsDec( ostream & ) const;

};