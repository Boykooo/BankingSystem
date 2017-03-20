
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
	cout << "\nИмя банка : " << bankName << "\n";
	cout << fixed << "Счет банка : " << bankAccount << "\n";
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

void Bank::openMenu()
{
	cout << "\n1. Выбрать клиента \n2. Добавить нового клиента \n3. Удалить клиента \n0. Выход\n"
		<< "Введите команду : ";
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

			cout << "\n1. Пополнить счет  \n2. Перевести сумму денег \n3. Добавить счет \n0.Выход"
				<< "\nВведите команду : ";
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

	cout << "Клиента с таким индексом не существует\n";
	return -1;
}

int Bank::getClientAccountIndex(Client *client)
{
	int accIndex = UI::getInt() - 1;

	if (accIndex >= 0 && client->accountCount() > accIndex)
	{
		return accIndex;
	}

	cout << "Банковского счета с таким индексом не существует\n";
	return -1;
}

void Bank::replenishAccount(Client *client)
{
	cout << "Введите индекс счета : ";
	int accountIndex = UI::getInt() - 1;
	if (client->accountCount() > accountIndex)
	{
		cout << "Введите сумму : ";
		double money = UI::getDouble();
		client->replenishAccount(accountIndex, money);
	}
	else
	{
		cout << "Счет с таким индексом не существует ";
	}
}

void Bank::transferMoney(Client *client)
{
	cout << "Введите индекс счета, откуда будут переведены средства : ";
	int accOutIndex = getClientAccountIndex(client);
	if (accOutIndex >= 0)
	{
		cout << "Введите индекс клиента, на счет которого будут переведены средства : ";
		int clientIndex = getClientIndex();
		if (clientIndex != -1)
		{
			Client *inClient = (*clientsList)[clientIndex];
			cout << "Введите индекс счета, куда будут переведены средства : ";
			int accInIndex = getClientAccountIndex(inClient);
			if (accInIndex >= 0)
			{
				cout << "Введите сумму перевода : ";
				double money = UI::getDouble();
				if (money > 0 && client->canTransfer(accOutIndex, money))
				{
					client->takeMoney(accOutIndex, money);
					double persentMoney = money - addMoneyToBank(money);
					inClient->addMoney(accInIndex, persentMoney);
				}
				else
				{
					cout << "У клиента недостаточно средств на счете";
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
		cout << "\nСчета : \n";
		vector<Account*> *accounts = client->getAccounts();
		for (int i = 0; i < accounts->size(); i++)
		{
			cout << i + 1 << ". Номер счета : " << (*accounts)[i]->getNumberAccount()
				<< "\n Остаток средств : " << fixed << (*accounts)[i]->getMoney() << "\n";
		}
	}
	else
	{
		cout << "\nСчета отсутствуют\n";
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