#include <conio.h>
#include "Concave.h"
#include "InfoWindow.h"

#pragma once
class ConcavePvP : Concave, InfoWindow
{
private:
	void moveDir();
public:
	ConcavePvP();
	~ConcavePvP();
	void playConcave();
};

