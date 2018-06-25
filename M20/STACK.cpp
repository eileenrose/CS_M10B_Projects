#include "STACK.h"

using namespace std;

bool STACK::isEmpty() { // returns a bool if stack is empty
	return stack.empty(); // uses vector function that checks if vector is empty
}

void STACK::push(pair<int, int> p) { // adds element onto top of stack
	stack.push_back(p); // uses vector function that adds element onto the back
}

pair<int, int>& STACK::top() { // accesses the last element
	return stack.back(); // uses vector function that can see the last element
}

void STACK::pop() { // remove the last element from the stack
	if (!isEmpty()) { // first we need to check if the stack is full
		stack.pop_back(); // then we remove
	}
}
