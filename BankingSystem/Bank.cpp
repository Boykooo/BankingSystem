#include "stdafx.h"
#include <iostream>

using namespace BankingSystem;

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::showInfo()
{
	cout << "Bank info";
}

char * Bank::getName()
{
	return bankName;
}
