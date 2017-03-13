// BankingSystem.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace BankingSystem;


BankingController::BankingController()
{
	banksList = new vector<Bank*>();
	initBanks();
}

BankingController::~BankingController()
{

}

void BankingSystem::BankingController::initBanks()
{
	Bank *sber = new Bank("��������", 7520000023900, 8);
	Bank *vtb = new Bank("���", 8952100000101, 15);
	Bank *gaz = new Bank("�����������", 4200094214000, 11);


	banksList->push_back(sber);
	banksList->push_back(vtb);
	banksList->push_back(gaz);
}

void BankingController::showBanksList()
{
	for (int i = 0; i < banksList->size(); i++)
	{
		cout << "\n" << i + 1 << ". " << (*banksList)[i]->getName();
	}

	cout << "\n";
	BankingController::openMenu();
}



void BankingSystem::BankingController::openMenu()
{
	cout << "\n1. ������� ���� \n2. �������� ���� \n3. ������� ���� \n0. �����\n";
	switch (UI::getInt())
	{
	case 0:
		break;
	case 1:
		BankingController::chooseBank();
		break;
	case 2:
		BankingController::newBank();
		break;
	default:
		break;
	}
}

void BankingController::chooseBank()
{
	int bankNumber = UI::getInt();

	if (bankNumber >= 0 && banksList->size() < bankNumber)
	{
		(*banksList)[bankNumber]->showInfo();
	}
	else
	{
		cout << "���� � ����� �������� �� ����������";
	}
}

void BankingController::newBank()
{
	cout << "������� ��� �����\n";
	string bankName;
	getline(cin >> ws, bankName);
	cout << "������� ��������� ���� �����\n";
	double account = UI::getDouble();
	cout << "������� ���������� ������ �����\n";
	double persent = UI::getDouble();

	Bank *bank = new Bank(bankName, account, persent);

	banksList->push_back(bank);

}