#pragma once
#include <Windows.h>
#include <cstdio>

#define SIZE 15

using namespace std;
class InfoWindow
{
private:
	int startLocationX;
	int startLocationY;

public:
	InfoWindow();
	~InfoWindow();

protected:
	void printBord();
	void printInfo();
	void printfMessage(const char *msg, int originX, int originY);
	void gotoXY(int x, int y);
};

