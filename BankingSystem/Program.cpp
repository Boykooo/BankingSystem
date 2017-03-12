// BankingSystem.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include <cstdlib>

using namespace UI;

int main()
{
	UIController ui;
	ui.startUI();

	printf("\n");
	system("pause");
	return 0;
}
