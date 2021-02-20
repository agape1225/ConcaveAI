#include "ConcavePvP.h"
#include "ConcaveAI.h"

int main(void) {
	printf("----------------------------------------------\n\n");  
	printf("\t1. PvP ���"); 
	printf("\t2. AI  ���"); 
	printf("\n\n----------------------------------------------"); 
	char input = getche();

	system("cls");

	if (input == '1') {
		ConcavePvP concave;
		concave.playConcave();
	}
	else {
		ConcaveAI concave;
		concave.playConcave();
	}

	Sleep(5000);
	system("cls");

	return 0;
}