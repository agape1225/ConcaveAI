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
			printfMessage("�ùٸ� Ű�� �Է����ּ���!", getY() * 2, getX());
		}
		gotoXY(getY() * 2, getX());
	}
}

void ConcavePvP::playConcave() {

	gotoXY(0, 0);

	while (1) {

		if (getColor())
			printfMessage("�浹�� �����Դϴ�.", getY() * 2, getX());
		else
			printfMessage("�鵹�� �����Դϴ�.", getY() * 2, getX());

		moveDir();

		if (getColor())
			printf("��");
		else
			printf("��");

		changeBord(getX(), getY(), getColor());
		if (checkWin()) {
			if (getColor())
				printfMessage("�浹�� �¸��Ͽ����ϴ�.", getY() * 2, getX());
			else
				printfMessage("�鵹�� �¸��Ͽ����ϴ�.", getY() * 2, getX());
			return;
		}
		reverseColor();
	}
}