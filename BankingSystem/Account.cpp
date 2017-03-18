
#include "stdafx.h"

using namespace BankingComponents;

Account::Account(Bank* bank, string number) {
	this->bank = bank;
	this->numberAccount = number;
}

Account::~Account() {
	delete bank;
}

void Account::addMoney(double money)
{
	this->money += money;
}

void Account::takeMoney(double money)
{
	this->money -= money;
}

double Account::getMoney()
{
	return money;
}

string Account::getNumberAccount()
{
	return numberAccount;
}
