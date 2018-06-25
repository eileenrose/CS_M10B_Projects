#include "MAZE.h"

using namespace std;

int main() {

	MAZE maze; // instance of the maze class with most of the functions

	bool repeat = true; // a bool to keep the while loop on repeat

	maze.inputMaze(); // asks user for the maze file

	

	while (repeat) {

		

		maze.moveMouse(); // first so that the mouse can get into the entrance


		maze.displayMaze(); 


		Sleep(10);

		repeat = maze.mouseEnd(); // checks to see if should end the while loop
	}


	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, 15);
	cout << endl;
	return 0;
}