#include "LinkedList.h"

using namespace std;


void LinkedList::delete_Node(int x, int y) {
	Node* start = rows[y];
	int count = 0;
	while (count != x) {
		start->change_nextptr(start->get_nextptr()->get_nextptr());
		count++;
	}
	if (start->get_nextptr() == nullptr) {
		Node* temp = new Node();
		temp = start;
		start->get_prevptr()->change_nextptr(nullptr);
		delete temp;
		temp = nullptr;
	}
	else {
		Node* temp = new Node();
		temp = start;
		start->get_prevptr()->change_nextptr(start->get_nextptr() );
		start->get_nextptr()->change_prevptr(start->get_prevptr() );
		delete temp;
		temp = nullptr;
	}
}



void LinkedList::insert_Node(int x, int y, char c) {
	Node* start = rows[y-1];
	int count = 0;
	if (start->get_nextptr() == nullptr) {
		Node* temp = new Node(c);
		start->change_nextptr(temp);
		temp = nullptr;
		return;
	}
	while (count != x) {
		start->change_nextptr( start->get_nextptr()->get_nextptr() );
		count++;
	}
	if (start->get_nextptr() == nullptr) {
		Node* temp = new Node();
		start->change_nextptr(temp);
		temp->change_prevptr(start);
		temp->change_nextptr(nullptr);
		temp = nullptr;
	}
	else {
		Node* temp = new Node();
		temp->change_nextptr(start->get_nextptr()->get_nextptr());
		temp->change_prevptr(start->get_nextptr());
		temp->get_nextptr()->change_prevptr(temp->get_nextptr());
		start->change_nextptr(temp->get_prevptr());
		temp = nullptr;
	}
}

void LinkedList::gotoxy(int x, int y) {

	COORD pos = { x, y };

	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output, pos);

}

int LinkedList::get_x() { //gets current console pos x
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	return csbi.dwCursorPosition.X;
}
int LinkedList::get_y() { //gets current console pos y
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	return csbi.dwCursorPosition.Y;
}

void LinkedList::insert_Node(char c) {
	Node* start = rows[0];
	if (start->get_nextptr() == nullptr) {
		Node* temp = new Node(c);
		start->change_nextptr(temp);
		temp = nullptr;
		return;
	}
}