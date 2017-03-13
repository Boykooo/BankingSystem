


#include "stdafx.h"
#include <iostream>


using namespace BankingComponents;

Bank::Bank(string bankName, double account, double persent)
{
	this->bankName = bankName;
	this->account = account;
	this->persent = persent;
}

Bank::~Bank()
{
}

void Bank::showInfo()
{
	cout << "Bank info";
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


void Bank::addUser(Client newUser)
{
	clientsList.push_back(newUser);
}


