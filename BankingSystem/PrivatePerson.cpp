#include "stdafx.h"

using namespace BankingComponents;

PrivatePerson::PrivatePerson(string name, string surname, string lastName, 
								string birthDate, string passport_id)
{
	this->name = name;
	this->surname = surname;
	this->lastName = lastName;
	this->birthDate = birthDate;
	this->passport_id = passport_id;
}

PrivatePerson::~PrivatePerson()
{
}

string PrivatePerson::getName()
{
	string fullName = "��� : " + name
					+ "\n������� : " + surname
					+ "\n�������� : " + lastName
					+ "\n���� �������� : " + birthDate
					+ "\n����� �������� : " + passport_id;
		
	return fullName;
}
