#pragma once
#include "Concave.h"
#include "InfoWindow.h"
#include <conio.h>

class ConcaveAI : Concave, InfoWindow
{
private:
	array<array<int, SIZE>, SIZE> weight;
	bool player;
	const char *black;
	const char *white;
	bool state;
	void moveDir();
	void setWeight();
	void setAI();
	void setX(int x) { posX = x; }
	void setY(int y) { posY = y; }
	void printWeight();

public:
	ConcaveAI();
	~ConcaveAI();
	void playConcave();
};

