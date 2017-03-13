#include "stdafx.h"


using namespace BankingComponents;

LegalPerson::LegalPerson(string name, string iin, string type)
{
	this->name = name;
	this->iin = iin;
	this->type = type;
}

LegalPerson::~LegalPerson()
{
	delete &name;
	delete &iin;
	delete &type;
}

string LegalPerson::getName()
{
	string fullName = "��� ����������� : " + name
		+ "\n��� : " + iin
		+ "\n��� ����������� : " + type;

	return fullName;
}
