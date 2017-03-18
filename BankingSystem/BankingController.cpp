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
	Bank *sber = new Bank("��������", 7520000023900.0, 8);
	Bank *vtb = new Bank("���", 8952100000101, 15);
	Bank *gaz = new Bank("�����������", 4200094214000, 34);

	Client *trust = new LegalPerson("�����", "123456789325", "���");
	Client *privatePerson = new PrivatePerson("����", "�������", "�����������", "21.06.1962", "1985 186725");


	sber->addUser(trust);
	sber->addUser(privatePerson);

	banksList->push_back(sber);
	banksList->push_back(vtb);
	banksList->push_back(gaz);
}

void BankingController::showBanksList()
{
	int command = 1;
	while (command)
	{
		cout << "\n\n������ ������ : ";
		for (int i = 0; i < banksList->size(); i++)
		{
			cout << "\n" << i + 1 << ". " << (*banksList)[i]->getName();
		}

		cout << "\n";

		cout << "\n��������� �������� :"
			<< "\n1. ������� ���� \n2. �������� ���� \n3. ������� ���� \n0. �����\n"
			<< "������� ������� : ";
		command = UI::getInt();
		switch (command)
		{
		case 0:
			break;
		case 1:
			BankingController::chooseBank();
			break;
		case 2:
			BankingController::newBank();
			break;
		case 3:
			BankingController::deleteBank();
			break;
		default:
			break;
		}
	}

}


void BankingController::chooseBank()
{
	int bankNumber = getBankIndex();

	if (bankNumber >= 0)
	{
		(*banksList)[bankNumber]->showInfo();
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

void BankingController::deleteBank()
{
	int bankNumber = getBankIndex();

	if (bankNumber >= 0)
	{
		delete (*banksList)[bankNumber];
		banksList->erase(banksList->begin() + bankNumber);
	}
}

int BankingController::getBankIndex()
{
	cout << "������� ������ ����� : ";
	int bankNumber = UI::getInt() - 1;

	if (bankNumber >= 0 && banksList->size() > bankNumber)
	{
		return bankNumber;
	}
	else
	{
		cout << "���� � ����� �������� �� ����������";
		return -1;
	}
}


