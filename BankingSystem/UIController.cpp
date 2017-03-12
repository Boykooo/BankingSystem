// Файл реализации класса UIController.cpp

#include "stdafx.h"
#include <iostream>

using namespace UI;
using namespace std;


UIController::UIController()
{
	menu = "\n1. Вывести список банков \n0. Выход";
}

UIController::~UIController()
{

}

void UIController::startUI()
{
	cout << menu;
		
	while (true)
	{
		cout << "\nВведите команду : ";
		int command = getCommand();
		if (command == 0)
		{
			break;
		}
	}
}

int UI::UIController::getCommand()
{
	int command;
	cin >> command;

	while (cin.fail())
	{
		cout << "Ошибка ввода\nВведите команду : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> command;
	}

	return command;
}



