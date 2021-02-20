#include "ConcaveAI.h"

//���� ��
// 1, true, 225 : �浹 
// 2, false, 226: �鵹
// 


ConcaveAI::ConcaveAI()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			weight[i][j] = 0;
	}
	printInfo();
	printBord();
	printfMessage("�浹�� 0, �鵹�� 1�� �����ּ���!",getX(),getY());
	int buff;
	buff = getch();
	if (buff == '1') {
		player = false;
		black = "AI�� �����Դϴ�.";
		white = "player�� �����Դϴ�.";
	}
	else {
		player = true;
		black = "player�� �����Դϴ�.";
		white = "AI�� �����Դϴ�.";
	}
		
}

ConcaveAI::~ConcaveAI()
{
}

void ConcaveAI::moveDir() {
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

void ConcaveAI::setWeight() {
	int buff;
	if (getColor())
		weight[getX()][getY()] = 255;
	else
		weight[getX()][getY()] = 256;
	if (state) {
		buff = -1;
	}
	else {
		buff = 1;
	}

	if (checkRange(getX()-1, getY()-1) && weight[getX() - 1][getY() - 1] < 255)
		weight[getX()-1][getY()-1] += buff;

	if (checkRange(getX() - 1, getY()) && weight[getX() - 1][getY()] < 255)
		weight[getX() - 1][getY()] += buff;

	if (checkRange(getX() - 1, getY() + 1) && weight[getX() - 1][getY() + 1] < 255)
		weight[getX() - 1][getY() + 1] += buff;

	if (checkRange(getX(), getY() - 1) && weight[getX()][getY() - 1] < 255)
		weight[getX()][getY() - 1] += buff;

	if (checkRange(getX(), getY() + 1) && weight[getX()][getY() + 1] < 255)
		weight[getX()][getY() + 1] += buff;

	if (checkRange(getX() + 1, getY() - 1) && weight[getX() + 1][getY() - 1] < 255)
		weight[getX() + 1][getY() - 1] += buff;

	if (checkRange(getX() + 1, getY()) && weight[getX() + 1][getY()] < 255)
		weight[getX() + 1][getY()] += buff;

	if (checkRange(getX() + 1, getY() + 1) && weight[getX() + 1][getY() + 1] < 255)
		weight[getX() + 1][getY() + 1] += buff;


	for (int i = 0; i < SIZE; i++) {			//3�� ������ ���� �˻��ϴ� �ڵ�
		for (int j = 0; j < SIZE; j++) {
			if (weight[i][j] > 254) {
				int buff = weight[i][j];
				int countStone = 1;

				if (checkRange(i + 1, j) && weight[i + 1][j] == buff && 
					checkRange(i + 2, j) && weight[i + 2][j] == buff) {

					if (checkRange(i - 1, j) && weight[i - 1][j] < 255)
						weight[i - 1][j] += state ? -30 : 30;

					if (checkRange(i + 3, j) && weight[i + 3][j] < 255)
						weight[i + 3][j] += state ? -30 : 30;
				}

				if (checkRange(i, j + 1) && weight[i][j + 1] == buff &&
					checkRange(i, j + 2) && weight[i][j + 2] == buff) {

					if (checkRange(i, j - 1) && weight[i][j - 1] < 255)
						weight[i][j - 1] += state ? -30 : 30;

					if (checkRange(i, j + 3) && weight[i][j + 3] < 255)
						weight[i][j + 3] += state ? -30 : 30;
				}

				if (checkRange(i + 1, j + 1) && weight[i + 1][j + 1] == buff &&
					checkRange(i + 2, j + 2) && weight[i + 2][j + 2] == buff) {

					if (checkRange(i - 1, j - 1) && weight[i - 1][j - 1] < 255)
						weight[i - 1][j - 1] += state ? -30 : 30;

					if (checkRange(i + 3, j + 3) && weight[i + 3][j + 3] < 255)
						weight[i + 3][j + 3] += state ? -30 : 30;
				}

				if (checkRange(i + 1, j - 1) && weight[i + 1][j - 1] == buff &&
					checkRange(i + 2, j - 2) && weight[i + 2][j - 2] == buff) {

					if (checkRange( i - 1, j + 1) && weight[i - 1][j + 1] < 255)
						weight[i - 1][j + 1] += state ? -30 : 30;

					if (checkRange(i + 3, j - 3) && weight[i + 3][j - 3] < 255)
						weight[i + 3][j - 3] += state ? -30 : 30;
				}
			}
		}
	}
}

void ConcaveAI::setAI() {

	int buffX = 0, buffY = 0;
	int min = weight[buffX][buffY];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (weight[i][j] < min) {
				buffX = i;
				buffY = j;
				min = weight[i][j];
			}
		}
	}

	setX(buffX);
	setY(buffY);
	gotoXY(getY() * 2, getX());
}

void ConcaveAI::playConcave() {
	gotoXY(0, 0);
	while (true) {
		if (getColor()) {
			printfMessage(black, getX(), getY());
			state = getColor() == player;
			if (state) {
				moveDir();
			}
			else {
				setAI();
			}
		}
		else {
			printfMessage(white, getX(), getY());
			state = getColor() == player;
			if (state) {
				moveDir();
			}
			else {
				setAI();
			}
		}
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

		setWeight();
		reverseColor();
	}
}

void ConcaveAI::printWeight() {

	gotoXY(40, 40);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%4d ", weight[i][j]);
		}
		printf("\n");
	}

}