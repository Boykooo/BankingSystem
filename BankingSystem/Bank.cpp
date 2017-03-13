


#include "stdafx.h"
#include <iostream>


using namespace BankingComponents;

Bank::Bank(string bankName, double account, double persent)
{
	this->bankName = bankName;
	this->account = account;
	this->persent = persent;

	clientsList = new vector<Client*>();
}

Bank::~Bank()
{
	delete clientsList;
}

void Bank::showInfo()
{
	cout << "\n��� ����� : " << bankName << "\n";
	cout << fixed << "���� ����� : " << account << "\n";
	cout << "���������� ������ : " << persent << "%\n";
	cout << "���������� �������� : " << clientsList->size() << "\n";

	if (clientsList->size() > 0)
	{
		cout << "\n������ �������� :\n";
		for (int i = 0; i < clientsList->size(); i++)
		{
			cout << i + 1 << ". " << (*clientsList)[i]->getName() << "\n";
		}
	}

	openMenu();
}

void BankingComponents::Bank::openMenu()
{
	cout << "\n1. ������� ������ ���� ��������";
}


void Bank::addUser(Client *newUser)
{
	clientsList->push_back(newUser);
}




#pragma region GettersAndSetters

string Bank::getName()
{
	return bankName;
}

double Bank::getAccount()
{
	return account;
}

double Bank::getPersent()
{
	return persent;
}

void Bank::setName(string newName)
{
	bankName = newName;
}

#pragma endregion