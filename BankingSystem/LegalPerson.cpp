#include "stdafx.h"
#include <iostream>


using namespace BankingComponents;

LegalPerson::LegalPerson(string name, string iin, string type)
{
	this->name = name;
	this->iin = iin;
	this->type = type;
	this->clientType = ClientType::legalClient;
}

LegalPerson::~LegalPerson()
{
}

string LegalPerson::getName()
{
	string fullName = "��� ����������� : " + name
		+ "\n��� : " + iin
		+ "\n��� ����������� : " + type;

	return fullName;
}

bool LegalPerson::canTrasferToClient(ClientType clientType)
{
	return true;
}
