#pragma once

using namespace std;

class Node {

public:
	Node(char);
	Node();
	~Node();

	void change_nextptr(Node*);
	void change_prevptr(Node*);
	void change_char();

	Node* get_nextptr() const;
	Node* get_prevptr() const;
	char get_letter() const;

private:

	Node* next_pointer = nullptr;
	Node* prev_pointer = nullptr;
	char letter;

};