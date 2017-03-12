// BankingSystem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace BankingSystem;


BankingController::BankingController()
{
	menu = "\n1. Выбрать банк. \n2.Добавить новый банк. ";
}

BankingController::~BankingController()
{
}

char * BankingController::getMenu()
{
	return menu;
}

void BankingController::showBanksList()
{
	for (int i = 0; i < banksList.size(); i++)
	{
		cout << "\n" << i << ". " << banksList[i].getName();
	}

	BankingController::openMenu();
}

void BankingSystem::BankingController::openMenu()
{
	cout << menu;
	switch (UI::getCommand())
	{
		case 1:
			BankingController::chooseBank();
			break;
		case 2:
			break;
		default:
			break;
	}
}

void BankingController::chooseBank()
{
	int bankNumber = UI::getCommand();

	if (bankNumber >= 0 && banksList.size() < bankNumber)
	{
		banksList[bankNumber].showInfo();
	}
	else
	{
		cout << "Банк с таким индексом не существует";
	}
}


