#include <array>
#include "InfoWindow.h"
#define SIZE 15
#define LOCATION 15

using namespace std;

#pragma once

class Concave
{
private:
	array<array<int, SIZE>, SIZE> bord;
	bool colorOfStone;

public:
	Concave();
	~Concave();

protected:
	int posX;
	int posY;
	bool checkWin();
	bool checkRange(int x, int y);
	bool changeBord(int x, int y, bool value);
	bool moveX(int direction);
	bool moveY(int direction);
	int getX() { return posX; }
	int getY() { return posY; }
	void reverseColor() { colorOfStone = !colorOfStone; }
	bool getColor() { return colorOfStone; }
};

