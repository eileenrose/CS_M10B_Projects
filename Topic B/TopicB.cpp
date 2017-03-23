/*
Eileen Buenaflor

Topic B Project			CSM10B			Fall 2016

Status: Compiles and works

The test program to make sure the Rational class works as programmed:
1) Adding, subtracting, multiplying, dividing rational numbers
2) Printing them as a fraction or double
Uses printAsFrac and printAsDec in main function
*/

#include <iostream>
#include "Rational.h"
using namespace std;

int main() {

	cout << "r1, r4, r5, r6 use default settings, r2 has the value 3 as the only parameter," << endl;
	cout << "r3 has 12 and 16 as parameters\n" << endl;


	Rational r1;
	Rational r2{ 3 };
	Rational r3{ 12, 16 };
	Rational r4;
	Rational r5;
	Rational r6;


	cout << "Display as fractions" << endl;
	
	cout << "r1 is ";
	r1.printAsFrac();

	cout << "r2 is "; 
	r2.printAsFrac();

	cout << "r3 is "; 
	r3.printAsFrac();
	cout << endl;


	cout << "Display as decimals" << endl;

	cout << "r1 is ";
	r1.printAsDec();

	cout << "r2 is ";
	r2.printAsDec();

	cout << "r3 is ";
	r3.printAsDec();


	cout << "\nSet r2 to 3/8\n" << endl;
	r2.setFrac( 3, 8 );


	cout << "r1 = r2 + r3, r4 = r2 - r3, r5 = r2 * r3, r6 = r2 / r3\n" << endl;
	r1.add( r2, r3 );
	r4.subtract( r2, r3 );
	r5.multiply( r2, r3 );
	r6.divide( r2, r3 );

	// printing fractions
	cout << "r2 is ";
	r2.printAsFrac();

	cout << "r3 is ";
	r3.printAsFrac();

	cout << "r1 is ";
	r1.printAsFrac();

	cout << "r4 is ";
	r4.printAsFrac();

	cout << "r5 is ";
	r5.printAsFrac();

	cout << "r6 is ";
	r6.printAsFrac();

	// printing decimals
	cout << "\nr2 is ";
	r2.printAsDec();

	cout << "r3 is ";
	r3.printAsDec();

	cout << "r1 is ";
	r1.printAsDec();

	cout << "r4 is ";
	r4.printAsDec();

	cout << "r5 is ";
	r5.printAsDec();

	cout << "r6 is ";
	r6.printAsDec();


	cout << "\nCreate a Rational, r7, with a 0 numerator:" << endl;
	Rational r7{ 0 };
	r7.printAsFrac();
	r7.printAsDec();


	cout << "\nCreate a Rational, r8, with a 0 denominator:" << endl;
	Rational r8{ 5, 0 };
	r8.printAsFrac();
	r8.printAsDec();


	cout << "\nCreate r9, a pointer to a Rational object with values 5 and -9:" << endl;
	Rational* r9 = new Rational( 5, -9 );
	r9->printAsFrac();
	r9->printAsDec();



	cout << "\nr1 = r9 + r2, r4 = r9 - r2, r5 = r9 * r2, r6 = r9 / r2" << endl;
	cout << "Pay particular attention to the operand order\n\n" << endl;
	r1.add( r9, r2 );
	r4.subtract( r9, r2 );
	r5.multiply( r9, r2 );
	r6.divide( r9, r2 );

	// printing fractions
	cout << "r2 is ";
	r2.printAsFrac();

	cout << "r9 is ";
	r9->printAsFrac();

	cout << "r1 is ";
	r1.printAsFrac();

	cout << "r4 is ";
	r4.printAsFrac();

	cout << "r5 is ";
	r5.printAsFrac();

	cout << "r6 is ";
	r6.printAsFrac();

	// printing decimals
	cout << "\n\nr2 is ";
	r2.printAsDec();

	cout << "r9 is ";
	r9->printAsDec();

	cout << "r1 is ";
	r1.printAsDec();

	cout << "r4 is ";
	r4.printAsDec();

	cout << "r5 is ";
	r5.printAsDec();

	cout << "r6 is ";
	r6.printAsDec();


	cout << "\nSet r9 to values -5 and -10:" << endl;
	r9->setFrac( -5, -10 );
	r9->printAsFrac();
	r9->printAsDec();
	

	delete r9;
	r9 = nullptr;


	cout << "\nPress Enter to end -->  ";
	cin.ignore();
	cout << endl;


	return 0;
}