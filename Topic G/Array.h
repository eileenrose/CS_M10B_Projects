#pragma once
/*
Eileen Buenaflor

Topic G Project: Array.h
Incorporated Rational.cpp and Rational.h from Topic C Solution
*/

#include <iostream>
#include <stdexcept>

#include <iomanip>
#include <cmath>
#include <string>


using namespace std;


class OutOfRange : public runtime_error {
public:
	OutOfRange() : runtime_error{ "invalid as a subscript" } {}
};

class NegativeLength : public runtime_error {
public:
	NegativeLength() : runtime_error{ " is an illegal length for an array" } {}
};

template < typename T >
class Array {


public:


	Array( int );
	Array();
	Array( const Array& a ) {
		*this = a;
	}
	~Array() = default;
	/*
	If I put {delete [] ptr;} it causes heap corruption, and I Googled
	that was because two Array objects could be pointing at the same data
	thus get deleted twice. So it might have to do with the assignment operator?
	I am unsure why an error occurs after the program ends. 
	*/

	size_t getSize() const {
		return size;
	}

	const Array& operator = ( const Array& );

	bool operator == ( const Array& ) const;
	bool operator != ( const Array& comp ) const {
		return !( *this == comp );
	}

	T& operator [] ( int subscript ) {
		return ptr[ subscript ];
	}
	T operator [] ( int subscript ) const {
		return ptr[ subscript ]
	}


private:
	size_t size;
	T* ptr;

};

template < typename T >
Array< T >::Array( int num ) {
	size = num;
	ptr = new T [ size ];
}

template < typename T >
Array< T >::Array() {
	size = 10;
	ptr = new T [ size ];
}



template < typename T >
bool Array< T >::operator==( const Array& comp ) const {
	if ( size != comp.size ) {
		return false;
	}

	for ( size_t i{ 0 }; i < size; ++i ) {
		if ( ptr[ i ] != comp.ptr[ i ] ) {
			return false;
		}
	}

	return true;
}

template < typename T >
const Array< T >& Array< T >::operator=( const Array<T>& comp ) {

	if ( &comp != this ) {
		if ( size != comp.size ) {
			delete [] ptr;
			size = comp.size;
			ptr = new T [ size ];
		}
		for ( size_t i{ 0 }; i < size; ++i ) {
			ptr[ i ] = comp.ptr [i ];
		}
	}

	return *this;
}






//////////////////////////////////////////////////////////////////////////
// Rational.h and Rational.cpp from Topic C




class Rational
{
	friend ostream & operator << (ostream &, const Rational &);

public:
	Rational(int, int);
	inline Rational() {
		numer = new int{ 1 };
		denom = 1;
	}
	Rational(const Rational &r);
	~Rational() { delete numer; }

	int getDenominator() const
	{
		return denom;
	}
	int getNumerator() const
	{
		return *numer;
	}
	void setFraction(int num, int dem);
	Rational getFraction() const;

	Rational operator + (const Rational &fract) const;
	Rational operator - (const Rational &fract) const;
	Rational operator * (const Rational &fract) const;
	Rational operator / (const Rational &fract) const;

	const Rational & operator = (const Rational &);
	const Rational & operator += (const Rational &);
	const Rational & operator -= (const Rational &);
	const Rational & operator *= (const Rational &);
	const Rational & operator /= (const Rational &);

	Rational & operator ++ ();
	Rational operator ++ (int);

	bool operator == (const Rational &) const;
	bool operator != (const Rational &) const;

	string  toRationalString() const;
	double toDouble() const;

private:
	int *numer, denom;
	void reduce();
	void printAsFract(ostream &) const;
	void printAsDec(ostream &) const;

};

Rational::Rational(int num, int dem) : numer(new int)
{
	setFraction(num, dem);
}


Rational::Rational(const Rational &r) : numer(new int)
{
	*this = r;
}


void Rational::setFraction(int num, int dem)
{
	if (dem == 0)
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
	return Rational(*numer, denom);  // anonymous object creation
}

Rational Rational::operator + (const Rational &fract) const
{
	Rational res;

	res.numer = new int((*numer * fract.denom) + (*(fract.numer) * denom));

	res.denom = denom * fract.denom;

	res.reduce();

	return res;
}

// always this object minus the other object
Rational Rational::operator - (const Rational &fract) const
{
	Rational res;

	res.numer = new int((*numer * fract.denom) - (*(fract.numer) * denom));
	res.denom = denom * fract.denom;

	res.reduce();

	return res;
}

Rational Rational::operator * (const Rational &fract) const
{
	Rational res{ *numer * (*(fract.numer)), denom * fract.denom };

	res.reduce();

	return res;
}

// always this object divided by other object
Rational Rational::operator / (const Rational &fract) const
{
	Rational res{ *numer * fract.denom, denom * (*(fract.numer)) };

	res.reduce();

	return res;
}


const Rational & Rational::operator = (const Rational & r)
{
	if (this == &r)
		return *this;

	*numer = *(r.numer);

	denom = r.denom;

	return *this;
}

const Rational & Rational::operator += (const Rational & r)
{
	*this = *this + r;

	return *this;
}

const Rational & Rational::operator -= (const Rational & r)
{
	*this = *this - r;

	return *this;
}

const Rational & Rational::operator *= (const Rational & r)
{
	*this = *this * r;

	return *this;
}

const Rational & Rational::operator /= (const Rational & r)
{
	*this = *this / r;

	return *this;
}

Rational & Rational::operator ++ ()
{
	operator += (Rational());
	return *this;
}

Rational Rational::operator ++ (int)
{
	Rational temp{ *this };

	++(*this);

	return temp;
}

bool Rational::operator == (const Rational & r) const
{
	if (*numer == *r.numer && denom == r.denom)
		return true;
	else
		return false;
}

bool Rational::operator != (const Rational & r) const
{
	return !(*this == r);
}


ostream & operator << (ostream & out, const Rational & r)
{
	r.printAsFract(out);
	out << endl;

	r.printAsDec(out);
	out << endl;

	return out;
}

void Rational::printAsDec(ostream & out) const
{
	cout << fixed << setprecision(2) << toDouble();
	cout.unsetf(ios::fixed);
}

double Rational::toDouble() const
{
	return (static_cast<double>(*numer) / denom);
}

void Rational::printAsFract(ostream & out) const
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

	if (n == 0)  // if numerator is 0, there is nothing to do
		return;

	// check for negative values
	if (n < 0)
	{
		n *= -1;
	}

	if (d < 0)
	{
		d *= -1;
	}

	while (n != d)
	{
		if (n > d)
			n -= d;
		else
			d -= n;
	}

	*numer /= n;
	denom /= n;
}




