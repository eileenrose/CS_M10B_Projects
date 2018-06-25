
//#include "stdafx.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

#include <stdlib.h>

#include "Node.h"
#include "LinkedList.h"



using namespace std;


int main() {

	/*bool repeat = true;
	int input;

	cout << "[1]Exit\n" << "[2]New\n" << "[3]Open\n" << endl;

	do {

		cin >> input;

		switch (input) {
		case 1:
			repeat = false;
			break;
		case 2:
			system("cls");
			break;
		case 3:
			break;
		}

	} while (repeat);

	bool repeat = true;
	LinkedList list;

	do {
		cout << "[1]New\n[2]Open\n[3]Exit" << endl;
		int input;
		cin >> input;
		if (input == 1) {
			system("cls");
			
		}
		else if (input == 2) {
			system("cls");
		}
		else {
			repeat = false;
		}

	} while (repeat);*/

	LinkedList list;
	bool repeat = true;

	int chara;

	do {

		cout << "Enter character" << endl;
		chara = _getch();

		cout << char(chara) << endl;

		list.insert_Node(chara);

		cout << list.rows[0]->get_letter() << endl;


		if (chara == 27) {
			repeat = false;
		}



	} while (repeat);



	cout << "Enter\n";
	cin.ignore();
	return 0;
	

}

