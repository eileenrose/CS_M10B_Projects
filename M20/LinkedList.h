#pragma once

#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Node.h"

using namespace std;

class LinkedList {

public:
	

	void insert_Node(int, int, char);
	void delete_Node(int, int);

	void gotoxy(int, int);

	int get_x();
	int get_y();

	Node* rows[5];


	void insert_Node(char);

private:

	

	int x = 1;
	int y = 1;


};