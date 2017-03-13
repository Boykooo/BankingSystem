#include "stdafx.h"

using namespace BankingComponents;

Client::Client()
{
}

Client::~Client()
{
}

#pragma region GettersAndSetters

void Client::setName(char * newName)
{
	userName = newName;
}

char* Client::getName()
{
	return userName;
}

#pragma endregion
									
