#include "Concave.h"



Concave::Concave()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			bord[i][j] = 0;
	}
	posX = posY = 0;
	colorOfStone = true;
}


Concave::~Concave()
{
}

bool Concave::checkWin() {
	int state;
	if (colorOfStone)
		state = 1;
	else
		state = 2;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int buff = bord[i][j];

			if (buff == state && buff != 0) {

				int countStone = 1;

				if (checkRange(i + 1, j) && bord[i + 1][j] == buff) {
					countStone++;
					for (int k = 2; k < 5; k++) {

						if (checkRange(i + k, j) && bord[i + k][j] == buff) {
							countStone++;

						}
						else {

							break;
						}
					}
				}
				if (countStone == 5)
					return true;
				else
					countStone = 1;

				if (checkRange(i, j + 1) && bord[i][j + 1] == buff) {
					countStone++;
					for (int k = 2; k < 5; k++) {
						if (checkRange(i, j + k) && bord[i][j + k] == buff) {
							countStone++;

						}
						else {

							break;
						}
					}
				}
				if (countStone == 5)
					return true;
				else
					countStone = 1;

				if (checkRange(i + 1, j + 1) && bord[i + 1][j + 1] == buff) {
					countStone++;
					for (int k = 2; k < 5; k++) {
						if (checkRange(i + k, j + k) && bord[i + k][j + k] == buff) {
							countStone++;

						}
						else {

							break;
						}
					}
				}
				if (countStone == 5)
					return true;
				else
					countStone = 1;

				if (checkRange(i + 1, j - 1) && bord[i + 1][j - 1] == buff) {
					countStone++;
					for (int k = 2; k < 5; k++) {
						if (checkRange(i + k, j - k) && bord[i + k][j - k] == buff) {
							countStone++;

						}
						else {

							break;
						}
					}
				}
				if (countStone == 5)
					return true;
			}
		}
	}
	return false;
}

bool Concave::checkRange(int x, int y) {
	return !(x >= SIZE || x < 0 || y >= SIZE || y < 0);
}

bool Concave::changeBord(int x, int y, bool value) {

	if (checkRange(x, y))
		bord[x][y] = value ? 1 : 2;
	else
		return false;
	return true;
}

bool Concave::moveX(int direction) {
	if (posX + direction < 0 || posX + direction >= SIZE)
		return false;
	posX += direction;
	return true;
}

bool Concave::moveY(int direction) {
	if (posY + direction < 0 || posY + direction >= SIZE)
		return false;
	posY += direction;
	return true;
}

