// BankingSystem.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	char* menu = "\n1. ������� ������ ������ \n0. �����";

	BankingController *bankingController = new BankingController();

	while (true)
	{
		cout << menu;
		cout << "\n������� ������� : ";
		if (getInt() == 0)
		{
			break;
		}

		bankingController->showBanksList();
	}
	
	delete bankingController;

	return 0;
}
