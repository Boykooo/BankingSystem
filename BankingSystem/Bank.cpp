
#include "stdafx.h"
#include <iostream>
#include <cinttypes>


using namespace BankingComponents;


Bank::Bank(string bankName, double account, double persent)
{
	this->bankName = bankName;
	this->bankAccount = account;
	this->persent = persent;

	this->accountLength = 20;

	clientsList = new vector<Client*>();
}

Bank::~Bank()
{
	delete clientsList;
}

void Bank::showInfo()
{
	cout << "\n��� ����� : " << bankName << "\n";
	cout << fixed << "���� ����� : " << bankAccount << "\n";
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

void Bank::openMenu()
{
	cout << "\n1. ������� ������� \n2. �������� ������ ������� \n3. ������� ������� \n0. �����\n"
		<< "������� ������� : ";
	int command = UI::getInt();

	switch (command)
	{
	case 1:
		Bank::chooseClient();
		break;
	case 2:
		Bank::newClient();
		break;
	case 3:
		Bank::deleteClient();
		break;
	default:
		break;
	}

}

void Bank::chooseClient()
{
	int clientIndex = getClientIndex();
	if (clientIndex >= 0)
	{
		while (true)
		{
			outputFullClientInfo((*clientsList)[clientIndex]);

			cout << "\n1. ��������� ����  \n2. ��������� ����� ����� \n3. �������� ���� \n0.�����"
				<< "\n������� ������� : ";
			int command = UI::getInt();
			if (command <= 0)
			{
				break;
			}

			switch (command)
			{
			case 1:
				Bank::replenishAccount((*clientsList)[clientIndex]);
				break;
			case 2:
				Bank::transferMoney((*clientsList)[clientIndex]);
				break;
			case 3:
				Bank::addNewAccount((*clientsList)[clientIndex]);
				break;
			default:
				break;
			}
		}

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

	cout << "������� � ����� �������� �� ����������\n";
	return -1;
}

int Bank::getClientAccountIndex(Client *client)
{
	int accIndex = UI::getInt() - 1;

	if (accIndex >= 0 && client->accountCount() > accIndex)
	{
		return accIndex;
	}

	cout << "����������� ����� � ����� �������� �� ����������\n";
	return -1;
}

void Bank::replenishAccount(Client *client)
{
	cout << "������� ������ ����� : ";
	int accountIndex = UI::getInt() - 1;
	if (client->accountCount() > accountIndex)
	{
		cout << "������� ����� : ";
		double money = UI::getDouble();
		client->replenishAccount(accountIndex, money);
	}
	else
	{
		cout << "���� � ����� �������� �� ���������� ";
	}
}

void Bank::transferMoney(Client *client)
{
	cout << "������� ������ �����, ������ ����� ���������� �������� : ";
	int accOutIndex = getClientAccountIndex(client);
	if (accOutIndex >= 0)
	{
		cout << "������� ������ �������, �� ���� �������� ����� ���������� �������� : ";
		int clientIndex = getClientIndex();
		if (clientIndex != -1)
		{
			Client *inClient = (*clientsList)[clientIndex];
			cout << "������� ������ �����, ���� ����� ���������� �������� : ";
			int accInIndex = getClientAccountIndex(inClient);
			if (accInIndex >= 0)
			{
				cout << "������� ����� �������� : ";
				double money = UI::getDouble();
				if (money > 0 && client->canTransfer(accOutIndex, money))
				{
					client->takeMoney(accOutIndex, money);
					double persentMoney = money - addMoneyToBank(money);
					inClient->addMoney(accInIndex, persentMoney);
				}
				else
				{
					cout << "� ������� ������������ ������� �� �����";
				}
			}
		}
	}

}

double Bank::addMoneyToBank(double money)
{
	double persentMoney = money * persent / 100;
	bankAccount += persentMoney;
	return persentMoney;
}

void Bank::addNewAccount(Client *client)
{
	string accNumber = "";
	for (int i = 0; i < accountLength; i++)
	{
		accNumber += to_string(rand() % 10);
	}

	client->addNewAccount(new Account(this, accNumber));
}

void Bank::outputFullClientInfo(Client* client)
{
	cout << "\n" << client->getName();

	if (client->accountCount() > 0)
	{
		cout << "\n����� : \n";
		vector<Account*> *accounts = client->getAccounts();
		for (int i = 0; i < accounts->size(); i++)
		{
			cout << i + 1 << ". ����� ����� : " << (*accounts)[i]->getNumberAccount()
				<< "\n ������� ������� : " << fixed << (*accounts)[i]->getMoney() << "\n";
		}
	}
	else
	{
		cout << "\n����� �����������\n";
	}

	//delete accounts;
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
	return bankAccount;
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