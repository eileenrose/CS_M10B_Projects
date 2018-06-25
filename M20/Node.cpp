#include <conio.h>

#include "Node.h"

using namespace std;

Node::Node(char c) {
	letter = c;
}

Node::Node() {
	change_char();
}

void Node::change_char() {
	letter = _getch();
}

void Node::change_nextptr(Node* n) {
	next_pointer = n->get_prevptr();
}

void Node::change_prevptr(Node* n) {
	prev_pointer = n->get_nextptr();
}

Node* Node::get_nextptr() const {
	return next_pointer;
}

Node* Node::get_prevptr() const {
	return prev_pointer;
}

char Node::get_letter() const {
	return letter;
}

Node::~Node() {
	delete next_pointer;
	delete prev_pointer;

	next_pointer = nullptr;
	prev_pointer = nullptr;
}