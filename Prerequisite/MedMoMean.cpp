#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int readInput(vector<int> &numVector) {
	

	ifstream theFile("Projectin.txt");

	if (!theFile) {
		cerr << "File could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}
	int number;
	int sum{ 0 };

	while (theFile >> number) {
		numVector.push_back(number);
		sum += number;

	}
	return sum;

}

void sort(vector<int> &sortVector) {
	sort(sortVector.begin(), sortVector.end());
}

void copy(vector<int> &sortVector, int arr[1117]) {

	for (int i{ 0 }; i < sortVector.size(); ++i) {
		arr[i] = sortVector[i];
	}
}

void calculateMode(int &max, int arr[1117], int arrSize, int &index) {
	int count{ 1 };
	for (int i{ 0 }; i < arrSize - 1; ++i) {
		if (arr[i] != arr[i + 1]) {
			if (count > max) {
				max = count;
				index = i;
			}
			count = 1;
		}
		else {
			count++;
		}
	}
}

void writeToFile(ostream& outputFile, vector<int> &numVector) {
	
	for (int i{ 0 }; i < numVector.size(); ++i) {
		outputFile << numVector[i] << " ";
	}
	
}

void writeToFile(ostream& outputFile, int arr[1117], int arrSize) {
	
	for (int i{ 0 }; i < arrSize; ++i) {
		outputFile << arr[i] << " ";
	}

}


int main() {

	vector<int> numVector;
	int sum = readInput(numVector);
	const int arrSize = 1117;
	//array<int, arrSize> arr;
	int arr[1117];
	vector<int> sortVector(numVector);
	sort(sortVector);
	int max{ 0 }, index{ 0 }, median{ 0 };
	
	copy(sortVector, arr);
	calculateMode(max, arr, arrSize, index);

	
	if (arrSize % 2 == 0) {
		median = (arr[(arrSize - 2) / 2] + arr[(arrSize - 1) / 2]) / 2;
	}
	else {
		median = arr[(arrSize - 1) / 2];
	}
	
	ofstream outputFile("Projectout.txt");
	outputFile << "The values read are: " << endl;
	writeToFile(outputFile, numVector);
	outputFile << "\n\n\nAverage of values is " << (sum / numVector.size()) << endl;
	outputFile << "\n\nThe sorted result is: " << endl;
	writeToFile(outputFile, arr, arrSize);
	outputFile << "\n\nThe median of the values is:	" << median << endl;
	outputFile << "\nThe mode of the values is " << arr[index] << " which occurs " << max << " times." << endl;
	outputFile << "\n\nProgram over." << endl;

	cout << "All normal output will be written to the output file. \n\n" << endl;
	cout << "Program Over" << endl;
	return 0;

}