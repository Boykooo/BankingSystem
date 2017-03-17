
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
	cout << "\nИмя банка : " << bankName << "\n";
	cout << fixed << "Счет банка : " << account << "\n";
	cout << "Процентная ставка : " << persent << "%\n";
	cout << "Количество клиентов : " << clientsList->size() << "\n";

	if (clientsList->size() > 0)
	{
		cout << "\nСписок клиентов :\n";
		for (int i = 0; i < clientsList->size(); i++)
		{
			cout << i + 1 << ". " << (*clientsList)[i]->getName() << "\n";
		}
	}

	openMenu();
}

void BankingComponents::Bank::openMenu()
{
	cout << "\n1. Добавить нового клиента \n2. Удалить клиента \n0. Выход\n"
		<< "Введите команду : ";
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
		cout << "\nВведите тип клиента. \n1. Частное лицо. \n2. Юридичесткое лицо\n"
			<< "Введите команду : ";
		clientType = UI::getInt();
	}

	if (clientType == 1)
	{
		string name;
		cout << "Введите имя : ";
		getline(cin >> ws, name);
		string surname;
		cout << "Введите фамилию : ";
		getline(cin >> ws, surname);
		string lastName;
		cout << "Введите отчество : ";
		getline(cin >> ws, lastName);
		string passport_id;
		cout << "Введите номер и серию паспорта : ";
		getline(cin >> ws, passport_id);
		string birthDate;
		cout << "Введите дату рождения : ";
		getline(cin >> ws, birthDate);

		Bank::addUser(new PrivatePerson(name, surname, lastName, birthDate, passport_id));
	}
	else {
		string name;
		cout << "Введите имя :\n";
		getline(cin >> ws, name);
		string iin;
		cout << "Введите ИИН :\n";
		getline(cin >> ws, iin);
		string type;
		cout << "Введите тип организации :\n";
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
	cout << "Введите индекс клиента : ";
	int clientNumber = UI::getInt() - 1;

	if (clientNumber >= 0 && clientsList->size() > clientNumber)
	{
		return clientNumber;
	}
	else
	{
		cout << "Клиента с таким индексом не существует";
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