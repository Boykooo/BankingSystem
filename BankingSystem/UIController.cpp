// ���� ���������� ������ UIController.cpp

#include "stdafx.h"
#include <iostream>

using namespace UI;
using namespace std;


UIController::UIController()
{
	menu = "\n1. ������� ������ ������ \n0. �����";
}

UIController::~UIController()
{

}

void UIController::startUI()
{
	cout << menu;
		
	while (true)
	{
		cout << "\n������� ������� : ";
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
		cout << "������ �����\n������� ������� : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> command;
	}

	return command;
}



