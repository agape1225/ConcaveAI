#include "InfoWindow.h"

InfoWindow::InfoWindow()
{
	startLocationX = 35;
	startLocationY = 0;
}

InfoWindow::~InfoWindow()
{
}

void InfoWindow::printInfo() {
	gotoXY(startLocationX, startLocationY);
	for (int i = 0; i < 40; i++) {
		printf("-");
	}
	for (int i = 1; i < 14; i++) {
		gotoXY(startLocationX, startLocationY + i);
		printf("|");
		for (int i = 0; i < 38; i++) {
			printf(" ");
		}
		printf("|");
	}
	gotoXY(startLocationX, startLocationY + 14);
	for (int i = 0; i < 40; i++) {
		printf("-");
	}

	gotoXY(startLocationX + 3, startLocationY + 8);
	printf("w : À§·Î ÇÑÄ­ ÀÌµ¿.");
	gotoXY(startLocationX + 3, startLocationY + 9);
	printf("a : ¿ÞÂÊÀ¸·Î ÇÑÄ­ ÀÌµ¿.");
	gotoXY(startLocationX + 3, startLocationY + 10);
	printf("s : ¾Æ·¡·Î ÇÑÄ­ ÀÌµ¿.");
	gotoXY(startLocationX + 3, startLocationY + 11);
	printf("d : ¿À¸¥ÂÊÀ¸·Î ÇÑÄ­ ÀÌµ¿.");
	gotoXY(startLocationX + 3, startLocationY + 12);
	printf("h : Âø¼ö");

}

void InfoWindow::printfMessage(const char *msg, int originX, int originY) {
	gotoXY(startLocationX + 2, startLocationY + 4);
	for (int i = 0; i < 37; i++)
		printf(" ");
	gotoXY(startLocationX + 1, startLocationY + 4);
	printf("%s", msg);
	gotoXY(originX, originY);
}

void InfoWindow::gotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void InfoWindow::printBord() {
	gotoXY(0, 0);
	int i, j;
	printf("¦£");
	for (i = 0; i < SIZE - 2; i++)
		printf("-¦¨");
	printf("-¦¤\n");

	for (i = 0; i < SIZE - 2; i++) {
		printf("¦§");
		for (j = 0; j < SIZE - 2; j++)
			printf("-¦«");
		printf("-¦©\n");
	}
	printf("¦¦");
	for (i = 0; i < SIZE - 2; i++)printf("-¦ª");
	printf("-¦¥");
}