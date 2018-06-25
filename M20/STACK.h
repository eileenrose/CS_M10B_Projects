#pragma once
#include <vector>

using namespace std;

class STACK { // custom built stack
public:

	void pop(); // remove the top element
	void push(pair<int, int>); // add element into the rear
	pair<int, int>& top(); // see what the last element is

	bool isEmpty(); // checks to see if stack is empty

private:


	vector<pair <int, int> > stack; // the container used to implement the stack


};