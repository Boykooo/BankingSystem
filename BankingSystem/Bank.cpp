
#include "stdafx.h"
#include <iostream>

using namespace BankingComponents;

Bank::Bank(string bankName, double account, double persent)
{
	this->bankName = bankName;
	this->bankAccount = account;
	this->persent = persent;

	this->accountLength = 20;

	//clientsList = new vector<Client*>();
}

Bank::~Bank()
{
	vector<Client*>::iterator it = clientsList.begin();
	while (it != clientsList.end())
	{
		delete *it;
		it = clientsList.erase(it);
	}
}

void Bank::showInfo()
{
	cout << "\n��� ����� : " << bankName << "\n";
	cout << fixed << "���� ����� : " << bankAccount << "\n";
	cout << "���������� ������ : " << persent << "%\n";
	cout << "���������� �������� : " << clientsList.size() << "\n";

	if (clientsList.size() > 0)
	{
		cout << "\n������ �������� :\n";
		for (int i = 0; i < clientsList.size(); i++)
		{
			cout << i + 1 << ". " << clientsList[i]->getName() << "\n";
		}
	}

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
			showFullClientInfo(clientIndex);

			cout << "\n1. ��������� ���� \n2. �������� ���� \n0.�����"
				<< "\n������� ������� : ";
			int command = UI::getInt();
			if (command <= 0)
			{
				break;
			}

			switch (command)
			{
			case 1:
				Bank::replenishAccount(clientsList[clientIndex]);
				break;
			case 2:
				Bank::addNewAccount(clientsList[clientIndex]);
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

		Bank::addClient(new PrivatePerson(name, surname, lastName, birthDate, passport_id));
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

		Bank::addClient(new LegalPerson(name, iin, type));
	}
}

void Bank::deleteClient()
{
	int clientIndex = getClientIndex();

	if (clientIndex >= 0)
	{
		vector<Client*>::iterator it = clientsList.begin() + clientIndex;
		delete *it;
		it = clientsList.erase(it);

		/*delete clientsList[clientIndex];
		 *
		clientsList.erase(clientsList.begin() + clientIndex);*/
	}
}

int Bank::getClientIndex()
{
	cout << "������� ������ ������� : ";
	int clientNumber = UI::getInt() - 1;

	if (clientNumber >= 0 && clientsList.size() > clientNumber)
	{
		return clientNumber;
	}

	cout << "������� � ����� �������� �� ����������\n";
	return -1;
}

ClientType Bank::getClientType(int clientIndex)
{
	return clientsList[clientIndex]->getClientType();
}

bool Bank::canTrasfer(int clientIndex, int accNumber, double money)
{
	return clientsList[clientIndex]->canTransfer(accNumber, money);
}

bool Bank::canTransferToClient(int clientIndex, ClientType clientType)
{
	return clientsList[clientIndex]->canTrasferToClient(clientType);
}

double Bank::takeMoney(int clientIndex, int accNumber, double money)
{
	clientsList[clientIndex]->takeMoney(accNumber, money);
	return money - addMoneyToBank(money);
}

void Bank::giveMoney(int clientIndex, int accNumber, double money)
{
	clientsList[clientIndex]->addMoney(accNumber, money);
}

int Bank::getClientAccountIndex(int clientIndex)
{
	int accIndex = UI::getInt() - 1;

	if (accIndex >= 0 && clientsList[clientIndex]->accountCount() > accIndex)
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

void Bank::showFullClientInfo(int clientIndex)
{
	Client *client = (clientsList)[clientIndex];
	cout << "\n" << client->getName();

	if (client->accountCount() > 0)
	{
		cout << "\n����� : \n";
		vector<Account*> accounts = client->getAccounts();
		for (int i = 0; i < accounts.size(); i++)
		{
			cout << i + 1 << ". ����� ����� : " << accounts[i]->getNumberAccount()
				<< "\n ������� ������� : " << fixed << accounts[i]->getMoney() << "\n";
		}
	}
	else
	{
		cout << "\n����� �����������\n";
	}

	//delete accounts;
}

void Bank::addClient(Client *newClient)
{
	Bank::addNewAccount(newClient);
	clientsList.push_back(newClient);
}

string Bank::getName()
{
	return bankName;
}