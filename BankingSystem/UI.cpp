
#include "stdafx.h"
#include <iostream>


int UI::getCommand()
{
	int command;
	cin >> command;

	while (cin.fail())
	{
		cout << "������ �����\n������� ������� : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> command;
	}

	return command;
}

