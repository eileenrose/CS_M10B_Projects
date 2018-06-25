#pragma once
#include <windows.h>
#include <set>
#include <iostream>
#include <fstream>
#include <string>

#include "STACK.h"

using namespace std;

class MAZE {
public:

	void displayMaze(); // displays the maze, but only reprints the parts that were changed
	void display(); // displays the maze, but reprints the entire maze
	

	void inputMaze(); // reads from file the map of the maze and inputs it into the array

	bool mouseEnd(); // check to see whether the mouse has reached the end to terminate the while loop

	void moveMouse(); // move the mouse

private:

	void gotoXY(int, int); // helps display the maze
	

	void moveMouseHelper(int, int, int&, int&); // don't have to repeat code

	void hitBomb(); // when a landmine is hit, ends the game
	void setColor(unsigned short); // sets the color of the text
	void colorfulMaze(int, int); // makes the maze look prettier

	


	char mapMaze[30][100]; // the 2D array of the maze



	int cols;
	int rows;
	// allows smaller mazes to be created
	// since kept track of how many columns and rows were input from the file

	pair<int, int> exitMaze; // location of the maze for mouseEnd()
	pair<int, int> mouseLoc = make_pair(1, 0); // where the mouse begins

	STACK mouseMovement; // custom stack for movement of the mouse

	set< pair<int, int> > visitedNode; // STL set to keep track of nodes visited

	// i used pairs of ints since i didn't want to make a new class for the x and y positions

};