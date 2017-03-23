/*
Eileen Buenaflor Topic G
Status: Compiles and works

Uses Array class from Ch 10 and makes it into a template

Instead of a few elements on one line
I put each element in a separate new line
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "Array.h"


void printInts (Array< int >& );
void allocateInts( Array< int >&, Array< int >& );
void allocateDou( Array< double >& );
void printDou( Array< double >& );
void allocateStr( Array< string >& );
void printStr( Array< string >& );
void printRat( Array< Rational >& );
void allocateRat( Array< Rational >& );


int main() {

	cout << "Adapting the Chapter 10 Array Class>topicg" << endl;
	cout << "Create two arrays, integers1 - 7 elements, integers2 - default size\n\n" << endl;
	
	Array< int > integers1{ 7 };
	Array< int > integers2{};

	cout << "Reading 17 integers from file TopicGin.txt:\n" << endl;
	cout << "After input, the Arrays contain:" << endl;

	allocateInts( integers1, integers2 );

	cout << "integers1:" << endl;
	printInts( integers1 );
	cout << "integers2:" << endl;
	printInts( integers2 );

	cout << "\n\nEvaluating: integers1 != integers2" << endl;
	if ( integers1 != integers2 )
	cout << "integers1 and integers2 are not equal" << endl;
	else
	cout << "integers1 and integers2 are equal" << endl;

	cout << "\nCreate Array integers3 from integers1\n\n" << endl;
	// what does create mean? like manually assign all values?
	cout << "Size of Array integers3 is 7" << endl;
	Array< int > integers3{ 7 };
	integers3 = integers1;
	// used assignment operator because faster than for loop
	cout << "Array after initialization:" << endl;
	printInts( integers3 );

	cout << "\n\nAssigning integers2 to integers1 (integers1 = integers2}:\nintegers1:" << endl;
	integers1 = integers2;
	printInts( integers1 );
	cout << "\nintegers2:" << endl;
	printInts( integers2 );

	cout << "\n\nEvaluating: integers1 == integers2" << endl;
	if ( integers1 == integers2 )
		cout << "\nintegers1 and integers2 are equal" << endl;
	else
		cout << "\nintegers1 and integers2 are not equal" << endl;

	cout << "\n\nintegers1[5] is " << integers1[ 5 ] << endl;
	cout << "\nAssigning 1000 to integers1[5]\nintegers1:" << endl;
	integers1[ 5 ] = 1000;
	printInts( integers1 );

	cout << "\n\nAttempt to assign 1000 to integers1[15]" << endl;
	int try1 = 15;
	try {
		if ( try1 >= integers1.getSize() )
			throw OutOfRange{};
	}
	catch( const OutOfRange& wat ){
	cout << try1 << " is beyond the end of the array and therefore " << wat.what() << endl;
	}

	cout << "\nAttempt to create array with a negative length\n\n" << endl;
	int try2 = -7;
	try {
		if ( try2 < 0 )
			throw NegativeLength{};
	}
	catch ( const NegativeLength& idk ) {
		cout << try2 << idk.what() << endl;
	}

	cout << endl << endl << "Create doubleArray with default length" << endl;
	Array< double > doubleArray{};
	cout << "Reading 10 numbers from file TopicGin.txt:\n\nDisplay doubleArray:" << endl;
	allocateDou( doubleArray );
	printDou( doubleArray );

	cout << "\nSet the first two elements to 2.7 and 3.4" << endl;
	doubleArray[ 0 ] = 2.7;
	doubleArray[ 1 ] = 3.4;
	cout << "\n\nDisplay double array:" << endl;
	printDou( doubleArray );

	cout << "\n\nCreate stringArray of length 5\nReading 5 words from file TopicGin.txt:" << endl;
	Array< string > stringArray{ 5 };
	allocateStr( stringArray );
	cout << "\nDisplay string array:" << endl;
	printStr( stringArray );

	cout << "\n\n\nCreate an array of 6 default Rational objects" << endl;
	Array< Rational > rat{ 6 };
	// dumped Rational.h and Rational.cpp in Array.h after much frustration
	// probably worked because template needs both implementation and interface
	cout << "\nDisplay Rational array:" << endl;
	printRat( rat );

	cout << "\n\nRead in values from the file\nDisplay Rational array:" << endl;
	allocateRat( rat );
	printRat( rat );

	cout << "\n\nAdd first and second elements and assign result to third element" << endl;
	cout << "Display Rational array:" << endl;
	rat[ 2 ] = rat[ 0 ] + rat[ 1 ];
	printRat( rat );

	cout << "\n\n\n\nSubtract fourth element from third element and store in fifth element" << endl;
	cout << "Display Rational array:" << endl;
	rat[ 4 ] = rat[ 2 ] - rat[ 3 ];
	printRat( rat );

	cout << "\n\n\nPress Enter to end -->  ";
	cin.ignore();
	cout << endl;

	return 0;
}

void allocateInts( Array< int > &integers1, Array< int > &integers2 ) {

	ifstream theFile( "TopicGin.txt" );
	if ( !theFile ) {
		cerr << "File cannot be opened." << endl;
		exit( EXIT_FAILURE );
	}

	int integer;
	int count = 0;
	int k1 = 0;
	int k2 = 0;

	while ( theFile >> integer ) {
		if ( count < 7 ) {
			integers1[ k1 ] = integer;
			k1++;
			count++;
		}
		else {
			integers2[ k2 ] = integer;
			k2++;
		}
	}
}

void printInts( Array<int> &integers ) {

	for ( int i{ 0 }; i < integers.getSize(); ++i ) {
		cout << integers[ i ] << endl;
	}
}

void allocateDou( Array< double > &d ) {

	ifstream theFile( "TopicGin.txt" );
	if ( !theFile ) {
		cerr << "File cannot be opened." << endl;
		exit(EXIT_FAILURE);
	}

	double decimal = 0.0;

	vector< double > doubs;
	// used vector instead of overloading >>
	// because I don't know and don't understand Complex classes

	while ( theFile >> decimal ) {
		doubs.push_back( decimal );
	}

	for ( int j{ 0 }; j < d.getSize(); ++j ) {
		d[ j ] = doubs[ 17 + j ];
	}
}

void printDou( Array< double > &d ) {

	for ( int i{ 0 }; i < d.getSize(); ++i ) {
		cout << d[ i ] << endl;
	}
}

void allocateStr( Array< string > &s ) {

	ifstream theFile( "TopicGin.txt" );
	if ( !theFile ) {
		cerr << "File cannot be opened." << endl;
		exit( EXIT_FAILURE );
	}

	string str;

	vector< string > stngs;

	while ( theFile >> str ) {
		stngs.push_back( str );
	}

	for ( int j{ 0 }; j < s.getSize(); ++j ) {
		s[ j ] = stngs[ j + 27 ];
	}
}

void printStr( Array< string > &s ) {

	for ( int i{ 0 }; i < s.getSize(); ++i ) {
		cout << s[ i ] << endl;
	}
}

void printRat( Array<Rational> &r ) {

	for ( int i{ 0 }; i < r.getSize(); ++i ) {
		cout << r[ i ] << endl;
	}
}

void allocateRat( Array<Rational> &r ) {

	ifstream theFile( "TopicGin.txt" );
	if ( !theFile ) {
		cerr << "File cannot be opened." << endl;
		exit( EXIT_FAILURE );
	}

	string num;

	vector< string > temp;

	while ( theFile >> num ) {
		temp.push_back( num );
	}

	int k = 0;

	for ( int i{ 0 }; i < r.getSize(); ++i ) {
		r[ i ].setFraction( stod( temp[ 32 + k ] ), stod( temp[ 32 + k + 1] ) );
		k += 2;
	}
}

