// Eileen Buenaflor Fall 2016 CSM10B
// Compiles and Works
// Drawing cars and trucks using inheritance and polymorphism

#include <iostream>
using namespace std;

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Varray.h"

int main() {

	int num = 0;

	do {
		cout << "What will be the maximum number of vehicles entered?\nNo less than 4 and no more than 10 -->  ";
		cin >> num;

		if ( num < 4 || num > 10 ) {
			cout << num << " is an incorrect amount \n" << endl;
		}

	} while ( num < 4 || num > 10 );

	Varray v{ num };

	cout << endl;

	bool cont = true;
	int k = 0;
	char yn;

	while ( cont ) {
		v.type( k );
		v[ k ].set();
		v[ k ].set( 0 );
		k++;

		cout << endl;

		if ( num > 4 && k > 3 ) {
			cout << "Enter another vehicle (y|n) -->  ";
			cin >> yn;
			cout << endl;

			if ( yn == 'n' ) {
				v.set( num - k );
				cont = false;
			}
		}

		if ( k == 3 && num == 4 ) {
			cont = false;
		}

	}

	cout << endl << endl;


	for ( int j{ 0 }; j < k; ++j ) {
		cout << v[ j ] << endl << endl << endl;
	}


	cout << "Press Enter to end program -->  ";
	cin.ignore();
	cout << endl;
	return 0;
}