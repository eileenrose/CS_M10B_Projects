/**********************************************************
	CS M10B
	Topic C Project

	Rational class implementation file
*******************************************************/

#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#include "Rational.h"

Rational::Rational(int num, int dem) : numer( new int ) 
{
	setFraction( num, dem );
}


Rational::Rational(const Rational &r) : numer(new int)
{
	*this = r;
}


void Rational::setFraction( int num, int dem )
{
	if ( dem == 0 )
	{
		cout << dem << " cannot be a denominator.  Changing to 1\n" << endl;
		denom = 1;
	}
	else
		denom = dem;

	*numer = num;

	reduce();
}

Rational Rational::getFraction() const
{
	return Rational( *numer, denom );  // anonymous object creation
}

Rational Rational::operator + ( const Rational &fract ) const
{
	Rational res;

	res.numer = new int( ( *numer * fract.denom ) + ( *(fract.numer) * denom ) );

	res.denom = denom * fract.denom;

	res.reduce();

	return res;
}

// always this object minus the other object
Rational Rational::operator - ( const Rational &fract ) const
{
	Rational res;
	
	res.numer = new int( ( *numer * fract.denom ) - ( *(fract.numer) * denom ) );
	res.denom = denom * fract.denom;

	res.reduce();

	return res;
}

Rational Rational::operator * ( const Rational &fract ) const
{
	Rational res{ *numer * (*(fract.numer)), denom * fract.denom };

	res.reduce();

	return res;
}

// always this object divided by other object
Rational Rational::operator / ( const Rational &fract ) const
{
	Rational res{ *numer * fract.denom, denom * (*(fract.numer)) };

	res.reduce();

	return res;
}


const Rational & Rational::operator = ( const Rational & r )
{
	if ( this == &r  )
		return *this;

	*numer = *(r.numer);
	
	denom = r.denom;

	return *this;
}

const Rational & Rational::operator += ( const Rational & r )
{
	*this = *this + r;

	return *this;
}

const Rational & Rational::operator -= ( const Rational & r )
{
	*this = *this - r;

	return *this;
}

const Rational & Rational::operator *= ( const Rational & r )
{
	*this = *this * r;

	return *this;
}

const Rational & Rational::operator /= ( const Rational & r )
{
	*this = *this / r;

	return *this;
}

Rational & Rational::operator ++ ()
{
	operator += ( Rational() );
	return *this;
}

Rational Rational::operator ++ ( int )
{
	Rational temp{ *this };

	++(*this);

	return temp;
}

bool Rational::operator == ( const Rational & r ) const
{
	if ( *numer == *r.numer && denom == r.denom )
		return true;
	else
		return false;
}

bool Rational::operator != ( const Rational & r ) const
{
	return !( *this == r );
}


ostream & operator << ( ostream & out, const Rational & r )
{
	r.printAsFract( out );
	out << endl;

	r.printAsDec( out );
	out << endl;

	return out;
}

void Rational::printAsDec( ostream & out ) const
{
	cout << fixed << setprecision( 2 ) << toDouble();
	cout.unsetf( ios::fixed );
}

double Rational::toDouble() const
{
	return (static_cast<double>(*numer) / denom);
}

void Rational::printAsFract( ostream & out ) const
{
	out << toRationalString();
}

string Rational::toRationalString() const
{
	string res{ "" }; 

	if ((*numer < 0 || denom < 0) && !(*numer < 0 && denom < 0))
		res = "-";

	res += to_string(abs(*numer)) + "/" + to_string(abs(denom));

	return res;
}


void Rational::reduce()
{  // use Euclidean algorithm, modified for 0 and negative values
	int n = *numer, d = denom;

	if ( n == 0 )  // if numerator is 0, there is nothing to do
		return;

	// check for negative values
	if ( n < 0 )
	{
		n *= -1;
	}

	if ( d < 0 )
	{
		d *= -1;
	}

	while ( n != d )
	{
		if ( n > d )
			n -= d;
		else
			d -= n;
	}

	*numer /= n;
	denom /= n;
}



		
