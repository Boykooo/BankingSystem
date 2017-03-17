
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
	cout << "\n1. �������� ������ ������� \n2. ������� ������� \n0. �����\n"
		<< "������� ������� : ";
	int command = UI::getInt();

	switch (command)
	{
	case 1:
		Bank::newClient();
		break;
	case 2:
		Bank::deleteClient();
		break;
	default:
		break;
	}

}

void Bank::newClient()
{
	int clientType = 0;
	while (clientType != 1 && clientType != 2) {
		cout << "\n������� ��� �������. \n1. ������� ����. \n2. ������������ ����\n"
			<< "������� ������� : ";
		clientType = UI::getInt();
	}

	if (clientType == 1)
	{
		string name;
		cout << "������� ��� : ";
		getline(cin >> ws, name);
		string surname;
		cout << "������� ������� : ";
		getline(cin >> ws, surname);
		string lastName;
		cout << "������� �������� : ";
		getline(cin >> ws, lastName);
		string passport_id;
		cout << "������� ����� � ����� �������� : ";
		getline(cin >> ws, passport_id);
		string birthDate;
		cout << "������� ���� �������� : ";
		getline(cin >> ws, birthDate);

		Bank::addUser(new PrivatePerson(name, surname, lastName, birthDate, passport_id));
	}
	else {
		string name;
		cout << "������� ��� :\n";
		getline(cin >> ws, name);
		string iin;
		cout << "������� ��� :\n";
		getline(cin >> ws, iin);
		string type;
		cout << "������� ��� ����������� :\n";
		getline(cin >> ws, type);

		Bank::addUser(new LegalPerson(name, iin, type));
	}
}

void Bank::deleteClient()
{
	int bankNumber = getClientIndex();

	if (bankNumber >= 0)
	{
		delete (*clientsList)[bankNumber];
		clientsList->erase(clientsList->begin() + bankNumber);
	}
}

int Bank::getClientIndex()
{
	cout << "������� ������ ������� : ";
	int clientNumber = UI::getInt() - 1;

	if (clientNumber >= 0 && clientsList->size() > clientNumber)
	{
		return clientNumber;
	}
	else
	{
		cout << "������� � ����� �������� �� ����������";
		return -1;
	}
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