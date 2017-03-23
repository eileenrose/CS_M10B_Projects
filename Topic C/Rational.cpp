/*********************************************************
Eileen Buenaflor
CS M10B		Fall 2016
Topic C Project

Used Topic B Solution as base
*******************************************************/


#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#include "Rational.h"

Rational::Rational( int num, int dem )
{
	setFraction( num, dem );
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
	return Rational( *numer, denom );  
}

void Rational::printAsDec() const
{
	cout << fixed << setprecision( 2 ) << toDouble() << endl;
	cout.unsetf( ios::fixed );
}

double Rational::toDouble() const
{
	return ( static_cast< double >( *numer ) / denom );   
}


void Rational::printAsFract() const
{
	cout << toRationalString() << endl;
}


string Rational::toRationalString() const
{
	string res{ "" };  

	if ( ( *numer < 0 || denom < 0 ) && !( *numer < 0 && denom < 0 ) )
		res = "-";

	res += to_string( abs( *numer ) ) + "/" + to_string( abs( denom ) );

	return res;
}




void Rational::reduce()
{  
	int n{ *numer }, d{ denom };

	if ( n == 0 )  
		return;

	
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

/***************************************************************/// My additions below

//create copy of object
Rational::Rational( const Rational& copy )
	: numer{ new int { copy.getNumerator() } }, denom{ copy.denom } {

}

// deallocates dynamic memory at end of lifetime
Rational::~Rational() {
	delete numer;
	numer = nullptr;
}


// overloads + using Topic B Solution addition function
Rational Rational::operator+( const Rational& rat ) const {
	Rational temp;
	*( temp.numer ) = ( *numer * rat.denom ) + ( rat.getNumerator() * denom );
	temp.denom = denom * rat.denom;
	temp.reduce();
	Rational ctemp( temp );
	return ctemp;
}

// overloads - using Topic B Solution subtraction function
Rational Rational::operator-( const Rational& rat ) const {
	Rational temp;
	*( temp.numer ) = ( *numer * rat.denom ) - ( rat.getNumerator() * denom );
	temp.denom = denom * rat.denom;
	temp.reduce();
	Rational ctemp( temp );
	return ctemp;

}

// overloads * using Topic B Solution multiplication function
Rational Rational::operator*( const Rational& rat ) const {
	Rational temp;
	*( temp.numer ) = ( *numer * rat.getNumerator() );
	temp.denom = denom * rat.denom;
	temp.reduce();
	Rational ctemp( temp );
	return ctemp;
}

// overloads / using Topic B Solution division function
Rational Rational::operator/( const Rational& rat ) const {
	Rational temp;
	*( temp.numer ) = ( *numer * rat.denom );
	temp.denom = denom * rat.getNumerator();
	temp.reduce();
	Rational ctemp( temp );
	return ctemp;
}

// overloads prefix ++
Rational& Rational::operator++() {
	*numer = *numer + denom;
	reduce();
	return *this;
}

// overloads postfix ++
Rational Rational::operator++( int ) {
	Rational temp{ *this };
	*numer = *numer + denom;
	reduce();
	temp.reduce();
	return temp;
}

// overloads =
const Rational& Rational::operator=( const Rational& rat ) {
	if ( &rat != this ) {
		*numer = rat.getNumerator();
		denom = rat.denom;
	}
	return *this;
}

// overloads +=
Rational& Rational::operator+=( const Rational& rat ) {
	*this = operator+( rat );
	return *this;
}

// overloads -=
Rational& Rational::operator-=( const Rational& rat ) {
	*this = operator-( rat );
	return *this;
}

// overloads *=
Rational& Rational::operator*=( const Rational& rat ) {
	*this = operator*( rat );
	return *this;
}

// overloads /=
Rational& Rational::operator/=( const Rational& rat ) {
	*this = operator/( rat );
	return *this;
}

// overloads ==
bool Rational::operator==( const Rational& rat ) const{
	if ( *numer == rat.getNumerator() && denom == rat.denom ) {
		return true;
	}
	else {
		return false;
	}
}

// overloads !=
bool Rational::operator!=( const Rational& rat ) const {
	return !( operator==( rat ) );
}

// overloads <<, prints out decimal and fraction form
ostream& operator<<( ostream& output, const Rational& r ) {
	output << r.toRationalString() << endl << setprecision( 2 ) << fixed << r.toDouble() << endl;
	return output;
}