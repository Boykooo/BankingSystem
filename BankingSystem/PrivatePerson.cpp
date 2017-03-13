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
	delete &name;
	delete &surname;
	delete &lastName;
	delete &passport_id;
	delete &birthDate;
}

string PrivatePerson::getName()
{
	string fullName = "Имя : " + name
					+ "\nФамилия : " + surname
					+ "\nОтчество : " + lastName
					+ "\nДата рождения : " + birthDate
					+ "\nНомер паспорта : " + passport_id;
		
	return fullName;
}
