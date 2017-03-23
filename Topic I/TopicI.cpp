/*
Eileen Buenaflor			Fall CSM10B
Topic I Project
Status: Compiles and works

Reads data from a file and inputs it into a vector
Sorts it into a deque, mode calculated 
Written to a file

EC1, EC2, EC3 done
*/

#include <vector>
#include <deque>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void readInput( vector<int>&, int&, int& );
void calculateMode( int&, int&, deque<int>& );
void copyVtoD( const vector<int>&, deque<int>& );

//takes both deque and vector as parameter
template <typename T>
void writeToFile( const T&, ostream&, const int& );

//function object
class conObj {
public:
	conObj() {};

	void operator () ( const vector<int>&, ostream& );


private:

	int sum{ 0 };

};




int main() {

	cout << "All normal output will be written to the output file.\n";

	int max{ 0 }, index{ 0 }, sum{ 0 }, numCount{ 0 };
	vector<int> numVector;
	deque<int> sortDeq;

	readInput( numVector, sum, numCount );
	copyVtoD( numVector, sortDeq );
	calculateMode( max, index, sortDeq );

	ofstream outputFile( "TopicIout.txt" );

	outputFile << "Read values into the vector\n\nThe values read are:" << endl;
	writeToFile( numVector, outputFile, numCount );

	outputFile << "Total of values is " << sum << endl;
	outputFile << "The average of the values is " << ( sum / numCount ) << endl;

	outputFile << "\n\n\nThe sorted result in the deque is:\n" << endl;
	writeToFile( sortDeq, outputFile, numCount );
	outputFile << "The mode is " << index << " which appears " << max << " times.\n" << endl;

	

	outputFile << "EXTRA CREDIT:\n\nValues in the range 20 to 45, inclusive, in the vector:" << endl;
	conObj{}( numVector, outputFile );

	outputFile << "\n\nProgram Over";

	cout << "Program Over\nPress Enter --> ";
	cin.ignore();

	return 0;
}

// reads file and puts values in vectors
void readInput( vector<int> &numVector, int &sum, int &numCount ) {

	ifstream theFile( "TopicIin.txt" );

	if ( !theFile ) {
		cerr << "The input file could not be found. Program ending." << endl;
		exit( EXIT_FAILURE );
	}

	int number;

	while ( theFile >> number ) {
		numVector.push_back( number );
		sum += number;
		++numCount;
	}

}

void calculateMode( int &max, int &index, deque<int> &sortDeq ) {
	
	// sorts into ascending order
	sort( sortDeq.begin(), sortDeq.end() );

	int temp{ 0 };

	for ( int i{ sortDeq[ 0 ] }; i <= sortDeq[ sortDeq.size() - 1 ]; ++i ) {
		temp = count( sortDeq.begin(), sortDeq.end(), i );
		if ( temp > max ) {
			max = temp;
			index = i;
		}
	}

	/* condensed this into the one above
	int count{ 1 };
	for (int i{ 0 }; i < sortDeq.size() - 1; ++i) {
		if (sortDeq[i] != sortDeq[i + 1]) {
			if (count > max) {
				max = count;
				index = i;
			}
			count = 1;
		}
		else {
			count++;
		}
	}*/
}

// copies vector to deque
void copyVtoD( const vector<int> &numVector, deque<int> &sortDeq ) {
	for ( size_t i{ 0 }; i < numVector.size(); ++i ) {
		sortDeq.push_back( numVector[ i ] );
	}
}

template <typename T>
void writeToFile( const T &container, ostream &outputFile, const int &numCount ) {

	for ( size_t i{ 0 }; i < container.size(); ++i ) {
		outputFile << container[ i ] << " ";
	}

	outputFile << "\nNumber of values found: " << numCount << endl;
}

void conObj::operator()( const vector<int> &v, ostream &outputFile ) {
	
	// count finds how many times i appears
	for ( int i = 20; i <= 45; ++i ) {
		sum += count( v.begin(), v.end(), i );
	}

	vector<int> temp;

	for ( size_t j{ 0 }; j < v.size(); ++j ) {
		if ( v [j ] >= 20 && v[ j ] <= 45 ) {
			temp.push_back( v[ j ] );
		}
	}

	writeToFile( temp, outputFile, sum );
}
