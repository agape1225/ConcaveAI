#include "ConcavePvP.h"

ConcavePvP::ConcavePvP()
{
	printInfo();
	printBord();
}

ConcavePvP::~ConcavePvP()
{
}

void ConcavePvP::moveDir() {
	while (true) {
		int dir;
		dir = getch();

		switch (dir) {

		case 'w': moveX(-1);
			break;
		case 's': moveX(1);
			break;
		case 'a': moveY(-1);
			break;
		case 'd': moveY(1);
			break;
		case 'h': return;

		default:
			printfMessage("올바른 키를 입력해주세요!", getY() * 2, getX());
		}
		gotoXY(getY() * 2, getX());
	}
}

void ConcavePvP::playConcave() {

	gotoXY(0, 0);

	while (1) {

		if (getColor())
			printfMessage("흑돌의 순서입니다.", getY() * 2, getX());
		else
			printfMessage("백돌의 순서입니다.", getY() * 2, getX());

		moveDir();

		if (getColor())
			printf("○");
		else
			printf("●");

		changeBord(getX(), getY(), getColor());
		if (checkWin()) {
			if (getColor())
				printfMessage("흑돌이 승리하였습니다.", getY() * 2, getX());
			else
				printfMessage("백돌이 승리하였습니다.", getY() * 2, getX());
			return;
		}
		reverseColor();
	}
}