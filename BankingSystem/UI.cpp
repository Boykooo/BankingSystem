
#include "stdafx.h"
#include <iostream>


int UI::getInt()
{
	int command;
	cin >> command;

	while (cin.fail())
	{
		cout << "ќшибка ввода\n¬ведите команду : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> command;
	}

	return command;
}

double UI::getDouble()
{
	double var;
	cin >> var;

	while (cin.fail())
	{
		cout << "ќшибка ввода\n¬ведите команду : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> var;
	}

	return var;
}



