#include "stdafx.h"

using namespace BankingComponents;

Client::Client()
{
	accounts = new vector<Account*>();
}

Client::~Client()
{
	for (int i = 0; i < accounts->size(); i++)
	{
		delete (*accounts)[i];
	}

	delete accounts;
}

string Client::getName()
{
	//virtual
	return "";
}

bool Client::canTransfer(int accountIndex, double money)
{
	return (*accounts)[accountIndex]->getMoney() - money >= 0;
}

int Client::accountCount()
{
	return accounts->size();
}

void Client::replenishAccount(int accountIndex, double money)
{
	(*accounts)[accountIndex]->addMoney(money);
}

void Client::addNewAccount(Account* account)
{
	accounts->push_back(account);
}

std::vector<Account*>* Client::getAccounts()
{
	return accounts;
}

void Client::addMoney(int accIndex, double money)
{
	(*accounts)[accIndex]->addMoney(money);
}

void Client::takeMoney(int accIndex, double money)
{
	(*accounts)[accIndex]->takeMoney(money);
}


									
