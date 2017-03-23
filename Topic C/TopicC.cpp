/******************************************************
Eileen Buenaflor
CS M10B			Fall 2016

Topic C Project

Includes:
* Overloading +, -, *, /, << , ++, ==, !=, +=, -=, *=, /= operators
* Numer in Rational class is a pointer to an int
* r9 is a pointer to a pointer to a Rational class
********************************************************/

#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

int main() {

	cout << "r1, r4, r5, r6 use default settings,";
	cout << " r2 has the value 3 as the only parameter, ";
	cout << " r3 has 12 and 16 as parameters\n" << endl;
	Rational r1, r2{ 3 }, r3{ 12, 16 }, r4, r5, r6;

	cout << "Display\nr1 is " << r1;
	cout << "\nr2 is " << r2;
	cout << "\nr3 is " << r3;
	cout << "\nr4 is " << r4;

	cout << "\n\n\nIs r1 == r4?:\n";
	if ( r1 == r4 ) {
		cout << "	r1 is equal to r4\n";
	}
	else {
		cout << "	r1 is NOT equal to r4\n";
	}
	cout << "\nIs r1 == r2?:\n";
	if  (r1 == r2 ) {
		cout << "	r1 is equal to r2\n";
	}
	else {
		cout << "	r1 is NOT equal to r2\n";
	}
	cout << "\nIs r1 != r4?:\n";
	if ( r1 != r4 ) {
		cout << "	r1 is NOT equal to r4\n";
	}
	else {
		cout << "	r1 is equal to r4\n";
	}
	cout << "\nIs r1 != r2?:\n";
	if ( r1 != r2 ) {
		cout << "	r1 is NOT equal to r4\n";
	}
	else {
		cout << "	r1 is equal to r4\n";
	}

	cout << "\n\nSet r2 to 3/8";
	r2.setFraction( 3, 8 );

	cout << "\n\nr1 = r2 + r3, r4 = r2 - r3, r5 = r2 * r3, r6 = r2 / r3";
	r1 = r2 + r3;
	r4 = r2 - r3;
	r5 = r2 * r3; 
	r6 = r2 / r3;

	cout << "\n\nr2 is " << r2;
	cout << "\nr3 is " << r3;
	cout << "\nr1 is " << r1;
	cout << "\nr4 is " << r4;
	cout << "\nr5 is " << r5;
	cout << "\nr6 is " << r6;

	cout << "\n\n\n\nr5 += r1 = r2 + r3 - r4\n";
	r5 += r1 = r2 + r3 - r4;
	cout << "\nr2 is " << r2;
	cout << "\nr3 is " << r3;
	cout << "\nr4 is " << r4;
	cout << "\nr1 is " << r1;
	cout << "\nr5 is " << r5;

	Rational r7{ 0 };
	cout << "\n\nCreate a Rational, r7, with a 0 numerator:\n" << r7;
	
	cout << "\n\nCreate a Rational, r8, with a 0 denominator:\n";
	Rational r8{ 5, 0 };
	cout << r8;

	cout << "\n\n\nIncrement r8 as:   ++r8\n";
	++r8;
	cout << "r8 is: " << r8;
	cout << "\n\n\nIncrement r5 as:   ++r5\n";
	++r5;
	cout << "r5 is:    " << r5;

	cout << "\n\n\nIncrement r8 as:   r8++\nr8 is:	" << r8++;
	cout << "\nAfter the previous cout statement r8 is: " << r8;
	cout << "\n\n\nIncrement r5 as:   r5++\nr5 is: " << r5++;
	cout << "\nAfter the previous cout statement r5 is: " << r5;

	cout << "\n\nCreate a Rational pointer, r9, with values 5 and -9 as a pointer to a Rational object:\n"; 
	// I was confused on what this statement meant. Was it one level of indirection or two?
	Rational** r9 = ( new Rational *( ( new Rational{ 5, -9 } ) ) );
	cout << **r9;

	cout << "\n\nr2 is " << r2;

	cout << "\n\nr9 += r2:";
	**r9 += r2;
	cout << "\nr9 is " << **r9;
	cout << "\n\nr9 -= r2:";
	**r9 -= r2;
	cout << "\nr9 is " << **r9;
	cout << "\n\nr9 *= r2:";
	**r9 *= r2;
	cout << "\nr9 is " << **r9;
	cout << "\n\nr9 /= r2:";
	**r9 /= r2;
	cout << "\nr9 is " << **r9;
	

	cout << "\n\n\nSet r9 to values -5 and -10:\n";
	( *r9 )->setFraction( -5, -10 );
	cout << **r9;

	delete *r9;
	delete r9;
	r9 = nullptr;

	cout << "\nPress Enter to end -->  ";
	cin.ignore();
	cout << endl;
	return 0;

}