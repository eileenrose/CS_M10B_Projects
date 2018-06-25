#include "MAZE.h"

void MAZE::moveMouse() { // all the code to make the mouse move

	if (mapMaze[mouseLoc.first][mouseLoc.second] == '2') {
		hitBomb(); // if mouse location on a 2, then activate bomb
	}

	/*if (!mouseMovement.isEmpty()) {
		mapMaze[mouseMovement.top().first][mouseMovement.top().second] = '~';
	}  can uncomment to see a trail that the mouse leaves behind
		works best if reprints the whole maze though
	*/

	mapMaze[mouseLoc.first][mouseLoc.second] = '@'; // move mouse to this location

	//gotoXY(mouseLoc.first, mouseLoc.second);
	// removed this since caused the cursor to shift the screen if maze was too big


	visitedNode.insert(make_pair(mouseLoc.first, mouseLoc.second)); // adds the coordinate to visited
	mouseMovement.push(make_pair(mouseLoc.first, mouseLoc.second)); // adds coordinate to movement of mouse


	//int x = getX();
	//int y = getY();
	// removed this since caused the cursor to shift the screen if maze was too big

	int x = mouseLoc.first;
	int y = mouseLoc.second;
	// used the 2D array to determine movement instead

	int newX = mouseLoc.first;
	int newY = mouseLoc.second;
	// used these variables to see whether or not the mouse changed positions

	bool cornerChecked = true;
	// if mouse was in corner or edge, then would skip the checking of all around it
	
// many, many if statements to check if the mouse was at any edge of the maze
	if (x == 0) { // if mouse was in the top row of the maze
		if (y == 0) { // if mouse was on the leftmost column of the maze
			if (mapMaze[x+1][y] == '0' || mapMaze[x + 1][y] == '3' || mapMaze[x + 1][y] == '2') {
				if (!(visitedNode.find(make_pair(x + 1, y)) != visitedNode.end())) { 
					// tried to find if pair was a member of the set
					moveMouseHelper(x + 1, y, newX, newY);
					cornerChecked = false;
				}
			}
			else if (mapMaze[x][y+1] == '0' || mapMaze[x][y + 1] == '3' || mapMaze[x][y + 1] == '2') {
				if (!(visitedNode.find(make_pair(x, y + 1)) != visitedNode.end())) {
					moveMouseHelper(x, y+1, newX, newY);
					cornerChecked = false;
				}
			}
		}
		if (y == rows) { // if mouse was at rightmost column of maze
			if (mapMaze[x+1][y] == '0' || mapMaze[x + 1][y] == '3' || mapMaze[x + 1][y] == '2') {
				if (!(visitedNode.find(make_pair(x + 1, y)) != visitedNode.end())) {
					moveMouseHelper(x + 1, y, newX, newY);
					cornerChecked = false;
				}
			}
			else if (mapMaze[x][y-1] == '0' || mapMaze[x][y - 1] == '3' || mapMaze[x][y - 1] == '2') {
				if (!(visitedNode.find(make_pair(x, y - 1)) != visitedNode.end())) {
					moveMouseHelper(x, y-1, newX, newY);
					cornerChecked = false;
				}
			}
		}
	}
	if (x == cols) { // if mouse was on the bottom row
		if (y == 0) { // if mouse was on the leftmost column of the maze
			if (mapMaze[x][y + 1] == '0' || mapMaze[x][y + 1] == '3' || mapMaze[x][y + 1] == '2') {
				if (!(visitedNode.find(make_pair(x, y + 1)) != visitedNode.end())) {
					moveMouseHelper(x, y+1, newX, newY);
					cornerChecked = false;
				}
			}
			else if (mapMaze[x - 1][y] == '0' || mapMaze[x - 1][y] == '3' || mapMaze[x - 1][y] == '2') {
				if (!(visitedNode.find(make_pair(x - 1, y)) != visitedNode.end())) {
					moveMouseHelper(x - 1, y, newX, newY);
					cornerChecked = false;
				}
			}
		}
		if (y == rows) { // if mouse was at rightmost column of maze
			if (mapMaze[x][y - 1] == '0' || mapMaze[x][y - 1] == '3' || mapMaze[x][y - 1] == '2') {
				if (!(visitedNode.find(make_pair(x, y - 1)) != visitedNode.end())) {
					moveMouseHelper(x, y-1, newX, newY);
					cornerChecked = false;
				}
			}
			else if (mapMaze[x - 1][y] == '0' || mapMaze[x - 1][y] == '3' || mapMaze[x - 1][y] == '2') {
				if (!(visitedNode.find(make_pair(x - 1, y)) != visitedNode.end())) {
					moveMouseHelper(x - 1, y, newX, newY);
					cornerChecked = false;
				}
			}
		}
	}

// i checked to see if the mouse was in the top or bottom row first
// but i didn't check to see what if they were on the leftmost or rightmost column but not in the top or bottom row
	if (y == 0) { // if mouse in leftmost column
		if (mapMaze[x][y + 1] == '0' || mapMaze[x][y + 1] == '3' || mapMaze[x][y + 1] == '2') {
			if (!(visitedNode.find(make_pair(x, y + 1)) != visitedNode.end())) {
				moveMouseHelper(x, y+1, newX, newY);
				cornerChecked = false;
			}
		}
		else if (mapMaze[x + 1][y] == '0' || mapMaze[x + 1][y] == '3' || mapMaze[x + 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x + 1, y)) != visitedNode.end())) {
				moveMouseHelper(x + 1, y, newX, newY);
				cornerChecked = false;
			}
		}
		else if (mapMaze[x - 1][y] == '0' || mapMaze[x - 1][y] == '3' || mapMaze[x - 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x - 1, y)) != visitedNode.end())) {
				moveMouseHelper(x - 1, y, newX, newY);
				cornerChecked = false;
			}
		}
	}
	if (y == rows) { // if mouse was at rightmost column of maze
		if (mapMaze[x][y - 1] == '0' || mapMaze[x][y - 1] == '3' || mapMaze[x][y - 1] == '2') {
			if (!(visitedNode.find(make_pair(x, y - 1)) != visitedNode.end())) {
				moveMouseHelper(x, y-1, newX, newY);
				cornerChecked = false;
			}
		}
		else if (mapMaze[x + 1][y] == '0' || mapMaze[x + 1][y] == '3' || mapMaze[x + 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x + 1, y)) != visitedNode.end())) {
				moveMouseHelper(x + 1, y, newX, newY);
				cornerChecked = false;
			}
		}
		else if (mapMaze[x - 1][y] == '0' || mapMaze[x - 1][y] == '3' || mapMaze[x - 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x - 1, y)) != visitedNode.end())) {
				moveMouseHelper(x - 1, y, newX, newY);
				cornerChecked = false;
			}
		}
	}

// if bool failed to be changed to false, then mouse was not in any of the edges
	// proceed to regular checking of all sides
	if (cornerChecked) {
		if (mapMaze[x][y + 1] == '0' || mapMaze[x][y + 1] == '3' || mapMaze[x][y + 1] == '2') {
			if (!(visitedNode.find(make_pair(x, y + 1)) != visitedNode.end())) {
				moveMouseHelper(x, y+1, newX, newY);
			}
		}
		if (mapMaze[x + 1][y] == '0' || mapMaze[x + 1][y] == '3' || mapMaze[x + 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x + 1, y)) != visitedNode.end())) {
				moveMouseHelper(x + 1, y, newX, newY);
			}
		}
		if (mapMaze[x][y - 1] == '0' || mapMaze[x][y - 1] == '3' || mapMaze[x][y - 1] == '2') {
			if (!(visitedNode.find(make_pair(x, y - 1)) != visitedNode.end())) {
				moveMouseHelper(x, y-1, newX, newY);
			}
		}
		if (mapMaze[x - 1][y] == '0' || mapMaze[x - 1][y] == '3' || mapMaze[x - 1][y] == '2') {
			if (!(visitedNode.find(make_pair(x - 1, y)) != visitedNode.end())) {
				moveMouseHelper(x - 1, y, newX, newY);
			}
		}
	}

/*it occurred to me it would have been much shorter and simpler if i had checked for
	if (mapMaze[x][y] != '1')	
i tried to implement it but it caused errors and due to lack of time, i am not changing it*/

	if (newX == mouseLoc.first && newY == mouseLoc.second) { // if mouse did not move at all
		// start popping to backtrack since this means mouse did not move
		mouseMovement.pop();
		mouseLoc = make_pair(mouseMovement.top().first, mouseMovement.top().second);
		mouseMovement.pop();
		mapMaze[newX][newY] = '0';
		// newX and newY still retains mouse's old position, so change back to open path
	}
	else { // if mouse moved to a new location
		mouseLoc = make_pair(newX, newY); // make the new location the mouse location
	}

	gotoXY(0, 0); // keeps maze at consistent location
}

void MAZE::moveMouseHelper(int x, int y, int& newX, int& newY) {
	/*
	since i originally tried to use the coordinates as a means of moving my mouse
	I had a lot of repeat code with gotoXY and getX, so i made it into a helper function
	but since i decided to use the array, i no longer needed this function
	but i don't want to go back and change everything so i'm keeping it

	gotoXY(x, y);
	newX = getX();
	newY = getY();
	*/
	newX = x;
	newY = y;
}

void MAZE::inputMaze() { // function that reads from file of maze and inputs into the array

	string fileName;

	cout << "Input file name: ";
	cin >> fileName;

	string line_content; // able to treat the string like an array

	ifstream theFile(fileName + ".txt"); // reads file

	if (!theFile) {
		cerr << "File could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	int j = 0; // keeps count on how many rows there are
	while (getline(theFile, line_content)) { // getline gets all the characters until a new line


		for (int i = 0; i < line_content.length(); i++) {
			mapMaze[j][i] = line_content[i]; // inputs the char into the array
			if (line_content[i] == '3') {
				exitMaze = make_pair(j, i); // keep track of the exit
			}
		}
		j++;
	
	}
	cols = line_content.length();
	rows = j;
	// able to make smaller mazes

	system("cls"); // remove the text asking for file name

	gotoXY(0, 0);
	

	// since i decided to reprint some parts of the maze
	// i decided to print the entire maze in this function
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			colorfulMaze(i, j);
		}
			cout << endl;		
	}

	
}

void MAZE::display() { // this function reprints the whole maze
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			colorfulMaze(i, j);
		}
		if (i < rows - 1) {
			cout << endl;
		}
	}

}

// this function is preferred because it takes less time
void MAZE::displayMaze() { // this function only reprints the rows around the mouse
	if (mouseLoc.first == 0) { // if mouse is in the top row
		gotoXY(0, mouseLoc.first);
		for (int i = mouseLoc.first; i < mouseLoc.first + 2; i++) {
			for (int j = 0; j < cols; j++) {
				colorfulMaze(i, j);
			}
			cout << endl;
		}
	}
	else if (mouseLoc.first >= (rows - 2 )) { // if mouse is near the bottom row
		gotoXY(0, mouseLoc.first - 1);
		for (int i = mouseLoc.first - 1; i < mouseLoc.first + 1; i++) {
			for (int j = 0; j < cols; j++) {
				colorfulMaze(i, j);
			}
			if (i != (rows - 1)) {
				cout << endl;
			}
		}
	}
	else { // mouse anywhere else
		gotoXY(0, mouseLoc.first - 1);
		for (int i = mouseLoc.first - 1; i < mouseLoc.first + 2; i++) {
			for (int j = 0; j < cols; j++) {
				colorfulMaze(i, j);
			}
			cout << endl;
		}
	}
}

void MAZE::colorfulMaze(int i, int j) { // allows the maze to be in color
	if (mapMaze[i][j] == '1') {
		setColor(0);
		cout << mapMaze[i][j];
	}
	else if (mapMaze[i][j] == '0') {
		setColor(153); 
		cout << mapMaze[i][j];
	}
	else if (mapMaze[i][j] == '2') {
		setColor(204);
		cout << mapMaze[i][j];
	}
	else if (mapMaze[i][j] == '@') {
		setColor(112);
		cout << mapMaze[i][j];
	}
	else if (mapMaze[i][j] == '3') {
		setColor(170);
		cout << mapMaze[i][j];
	}
	else if (mapMaze[i][j] == '~') {
		setColor(136);
		cout << mapMaze[i][j];
		cout << flush;
	} // makes the trail of the mouse a different color
}

void MAZE::hitBomb() { // function that activates when bomb is hit
	system("cls");

		// make the text bigger and fancier
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 24;
	cfi.dwFontSize.Y = 48;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	
	for (int k = 0; k < 3; k++) {

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				setColor(rand() % 256);
				gotoXY(rand() % 50, rand() % 50);
				cout << "BOOM!";
			}
		} // prints randomly colored BOOM! in random locations on screen


		Sleep(500);
		system("cls");
	}


	system("cls");

	cfi.dwFontSize.X = 48;
	cfi.dwFontSize.Y = 96;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	cout << "GAME OVER" << endl;

	Sleep(3000);
	exit(EXIT_FAILURE);
}

void MAZE::setColor(unsigned short color) { // changes the console text color
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}


bool MAZE::mouseEnd() { // checks to see if mouse reached the exit
	if (mouseLoc.first == exitMaze.first && mouseLoc.second == exitMaze.second) {
		return false;
	}
	else {
		return true;
	}
}


void MAZE::gotoXY(int x, int y) { // helps with console manipulation and graphics
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
/*
i got into a lot of trouble using gotoXY to determine the mouse location because then the console cursor
may have shifted the buffer screen, so the maze began to flicker and gave me a headache, 
so i switched to just relying on the 2D array
i also removed the getX() and getY() functions
*/