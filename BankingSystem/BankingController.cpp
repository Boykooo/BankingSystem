// BankingSystem.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace BankingSystem;


BankingController::BankingController()
{
	initBanks();
}

BankingController::~BankingController()
{
	vector<Bank*>::iterator it = banksList.begin();
	while (it != banksList.end())
	{
		delete *it;
		it = banksList.erase(it);
	}
}

void BankingSystem::BankingController::initBanks()
{
	Bank *sber = new Bank("��������", 7520000023900.0, 8);
	Bank *vtb = new Bank("���", 8952100000101, 15);
	Bank *gaz = new Bank("�����������", 4200094214000, 34);

	Client *trust = new LegalPerson("�����", "123456789325", "���");
	Client *privatePerson = new PrivatePerson("����", "�������", "�����������", "21.06.1962", "1985 186725");

	Client *vtbClient = new PrivatePerson("�������", "�������", "���������", "21.01.1982", "1982 936157");


	sber->addClient(trust);
	sber->addClient(privatePerson);
	vtb->addClient(vtbClient);

	banksList.push_back(sber);
	banksList.push_back(vtb);
	banksList.push_back(gaz);
}

void BankingController::showAllBanks()
{
	cout << "\n\n������ ������ : ";
	for (int i = 0; i < banksList.size(); i++)
	{
		cout << "\n" << i + 1 << ". " << banksList[i]->getName();
	}
}

void BankingController::showBanksList()
{
	int command = 1;
	while (command)
	{
		showAllBanks();
		cout << "\n";

		cout << "\n��������� �������� :"
			<< "\n1. ������� ���� \n2. �������� ���� \n3. ������� ���� \n4. �������� ������� ������� \n0. �����\n"
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
		case 4:
			bankTrasfer();
			break;
		default:
			break;
		}
	}

}

void BankingController::chooseBank()
{
	cout << "������� ������ ����� : ";
	int bankNumber = getBankIndex();

	if (bankNumber >= 0)
	{
		banksList[bankNumber]->showInfo();
		banksList[bankNumber]->openMenu();
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

	banksList.push_back(bank);

}

void BankingController::deleteBank()
{
	cout << "������� ������ ����� : ";
	int bankNumber = getBankIndex();

	if (bankNumber >= 0)
	{
		delete banksList[bankNumber];
		banksList.erase(banksList.begin() + bankNumber);
	}
}					

void BankingController::bankTrasfer()
{
	cout << "������� ������ �����, ������ ���������� �������� : ";
	BankTransfer out = requestBankTrasfer();

	if (out.status)
	{
		cout << "������� ����� : ";
		double money = UI::getDouble();

		if (out.bank->canTrasfer(out.clientIndex, out.accountIndex, money))
		{
			showAllBanks();
			cout << "\n\n������� ������ �����, ���� ���������� �������� : ";
			BankTransfer in = requestBankTrasfer();
			if (in.status)
			{
				double persentMoney = out.bank->takeMoney(out.clientIndex, out.accountIndex, money);
				in.bank->giveMoney(in.clientIndex, in.accountIndex, persentMoney);
			}
		}
		else
		{
			cout << "������������ �������";
		}
	}
}

BankTransfer BankingController::requestBankTrasfer()
{
	BankTransfer bankTransfer;
	bankTransfer.status = false;
	int bankIndex = getBankIndex();
	if (bankIndex != -1)
	{
		Bank *bank = banksList[bankIndex];
		bank->showInfo();
		cout << "\n";
		int clientIndex = bank->getClientIndex();
		if (clientIndex != -1)
		{
			bank->showFullClientInfo(clientIndex);
			cout << "������� ������ ����� : ";
			int accountIndex = bank->getClientAccountIndex(clientIndex);
			if (accountIndex != -1)
			{
				bankTransfer.accountIndex = accountIndex;
				bankTransfer.bank = bank;
				bankTransfer.clientIndex = clientIndex;
				bankTransfer.status = true;
				return bankTransfer;
			}
		}								
	}
		
	return {};
}

int BankingController::getBankIndex()
{
	int bankNumber = UI::getInt() - 1;

	if (bankNumber >= 0 && banksList.size() > bankNumber)
	{
		return bankNumber;
	}

	cout << "���� � ����� �������� �� ����������";
	return -1;
}
