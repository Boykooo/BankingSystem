#pragma once

#include "Client.h"
#include <vector>

using namespace std;

namespace BankingComponents {
	class Bank
	{
		string bankName;
		double account;
		double persent;
		vector<Client> clientsList;
	public:
		Bank(string bankName, double account, double persent);
		~Bank();
		void showInfo();
		string getName();
		double getAccount();
		double getPersent();
		void setName(string newName);
		void addUser(Client newClient);
	};
}
