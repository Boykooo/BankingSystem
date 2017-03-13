// BankingSystem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace UI;
using namespace BankingSystem;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char* menu = "\n1. Вывести список банков \n0. Выход";

	BankingController *bankingController = new BankingController();

	while (true)
	{
		cout << menu;
		cout << "\nВведите команду : ";
		int command = getInt();
		if (command == 0)
		{
			break;
		}
		else
		{
			bankingController->showBanksList();
		}
	}
	
	delete bankingController;

	return 0;
}
