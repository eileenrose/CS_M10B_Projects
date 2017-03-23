//Eileen Buenaflor Topic A Project

//Status: Compiles and works. Extra credit version.

/*
This program:
1) Takes in user input to create a two-dimensional, rectangular array
2) Reverses the array
3) Displays the array
*/

#include <iostream> 
#include <string>
#include <sstream>
#include <vector>

using namespace std;


// Allocates memory for these variables
void allocate( int**** &s, int**** &t, int** &u, int** &v, int* &len ) {

	int rows, cols;
	bool reset{ true };
	while ( reset ) {
		cout << "How many rows should the array have (at least 2) --> ";
		cin >> rows;
		if ( rows < 2 ) {
			cout << rows << " is an invalid value. Please re - enter a value 2 or greater." << endl;
		}
		else {
			break;
		}
	}
	while ( reset ) {
		cout << "How many columns should the array have (at least 2) --> ";
		cin >> cols;
		if ( cols < 2 ) {
			cout << cols << " is an invalid value. Please re - enter a value 2 or greater." << endl;
		}
		else {
			break;
		}
	}

	len = new int[ 2 ];
	len [ 0 ] = rows;
	len [ 1 ] = cols;
	
	s = new int***;
	*s = new int**;
	**s = new int*[ rows ];
	// It took me 2 hours to realize that not all of the rows were pointing to an array of ints
	for ( int i{ 0 }; i < rows; ++i ) {
		*( **s + i ) = new int[ cols ];
	}

	t = s;
	*t = *s;
	**t = **s;
	***t = ***s;
	u = new int*;
	*u = ***s;
	v = u;
	*v = *u;

	cout << "\n";

}

// Takes in values inputted from the user and stores them into the array
void input( int**** &s, int* len ) {

	// c is used as a counter for the if-statement on line 79
	int c{ 0 };
	for ( int i{ 0 }; i < *len; ++i ) {
		string values;
		vector<int> vals;
		cout << "For row " << i + 1 << " enter " << *(len + 1) << " values separated by spaces --> ";
		if ( c == 0 ) {
			/*
			cin.ignore() gives a pause. Without it, it would display row 1
			then immediately display row 2. However, in the following rows,
			the stream would not obtain the first integer, thus leaving one 
			column empty. Thus, the if statement. Only having cin.ignore() in the
			first row fixed the problem.
			*/
			cin.ignore();
			++c;
		}
		getline( cin, values );
		stringstream stream ( values );
		int num;
		while ( stream >> num ) {
			vals.push_back( num );
		}
		for ( unsigned int j{ 0 }; j < vals.size(); ++j ) {
			*(*( **s + i ) + j ) = vals[ j ];
		}
		cout << "\n" << endl;			
	}

}

// Reverses the order of the array
void reverse( int* len, int**** &t, bool &wasReversed ) {

	/*
	Extra credit: No extra array created. Used source array.

	I used the swap algorithm used in sorting. I'm not sure if it also applies to C++, 
	but I know in Java, a temporary value must be created in order to swap order.
	So I created the int temp to hold the beginning element while I put the end element in the
	order of the beginnig element, then put the beginning element held in the temp into the end 
	position. I did this until I got to half of the array, because if I continued on until the 
	last element, it would just reverse back to its original order. Originally, I had two if statements
	that if the columns was even I would half the size plus one, but after several testing, I noticed 
	that whenever I had an odd number of rows and 2 columns, it wouldn't reverse. Then after trying 
	to fix that, I noticed that I didn't even need if statements.
	
	*/


	for (int i{ 0 }; i < len[0]; ++i) {
		for (int j{ 0 }; j < len[1] / 2; ++j) {
			int temp = (**t)[i][j];
			(**t)[i][j] = (**t)[i][(len[1] - 1 - j)];
			(**t)[i][(len[1] - 1 - j)] = temp;
		}
	}

	// Created to help with display function
	wasReversed = true;

}

// Displays the contents of the array
void display( bool wasReversed, int**** s, int* len, int** &v ){

	//I used conditionals to print the statements that occured after reversal
	if ( wasReversed ) {
		cout << "\n" << "After reversing:" << "\n\n" << endl;
	}

	for ( int i{ 0 }; i < len[ 0 ]; ++i ) {
		cout << "For row " << i + 1 << " here are the values in the array:" << endl;
		for ( int j{ 0 }; j < len[ 1 ]; ++j ) {
			cout << *(*( **s + i ) + j ) << " ";
		}
		cout << "\n" << endl;
	}

	if ( wasReversed ) {
		cout << "Display first row using v:" << endl;
		for ( int k{ 0 }; k < len[ 1 ]; ++k ) {
			cout << (*v)[ k ] << " ";
		}
		cout << "\n\n" << endl;
	}
}

// Deallocates memory previously allocated
void deallocate( int**** &s, int**** &t, int** &u, int** &v, int* &len ) {
	for (int i{ 0 }; i < *len; i++) {
		delete *( **s + i );
	}
	delete **s;
	delete *s;
	delete s;
	s = nullptr;
	*u = nullptr;
	delete *u;
	delete u;
	u = nullptr;
	delete len;
	len = nullptr;

}



int main() {
	int**** s;
	int**** t;
	int** u;
	int** v;

	int* len;
	bool wasReversed = false;

	allocate( s, t, u, v, len );
	input( s, len );
	display( wasReversed, s, len, v );
	reverse( len, t, wasReversed );
	display( wasReversed, s, len, v );
	deallocate( s, t, u, v, len );
	
	cout << "Program Ending" << endl;
	return 0;
}