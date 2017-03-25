#include "stdafx.h"
#include <iostream>

using namespace BankingComponents;

PrivatePerson::PrivatePerson(string name, string surname, string lastName, 
								string birthDate, string passport_id)
{
	this->name = name;
	this->surname = surname;
	this->lastName = lastName;
	this->birthDate = birthDate;
	this->passport_id = passport_id;
	this->clientType = ClientType::privateClient;
}

PrivatePerson::~PrivatePerson()
{

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

bool PrivatePerson::canTrasferToClient(ClientType clientType)
{
	if (clientType == ClientType::legalClient)
	{
		cout << "\nЧастное лицо не может оформить перевод юридическому лицу\n";
		return false;
	}

	return true;
}
