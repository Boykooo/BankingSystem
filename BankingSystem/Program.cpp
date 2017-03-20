// BankingSystem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace UI;
using namespace BankingSystem;

int main()
{
	//setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* menu = "\n1. Вывести список банков \n0. Выход";

	BankingController *bankingController = new BankingController();

	while (true)
	{
		cout << menu;
		cout << "\nВведите команду : ";
		if (getInt() == 0)
		{
			break;
		}

		bankingController->showBanksList();
	}
	
	delete bankingController;

	return 0;
}
