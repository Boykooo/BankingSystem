#pragma once

#include "Client.h"
#include <vector>


namespace BankingComponents {
	class Bank
	{
	public:
		Bank(std::string bankName, double account, double persent);
		~Bank();
		void showInfo();
		std::string getName();
		double getAccount();
		double getPersent();
		void setName(std::string newName);
		void addUser(Client *newClient);

	private:
		void openMenu();
		void chooseClient();
		void newClient();
		void deleteClient();
		int getClientIndex();
		int getClientAccountIndex(Client *client);
		void replenishAccount(Client *client);
		void transferMoney(Client *client);
		double addMoneyToBank(double money);
		void addNewAccount(Client *client);
	    void outputFullClientInfo(Client *client);

		std::string bankName;
		double bankAccount;
		double persent;
		std::vector<Client*> *clientsList;
		int accountLength;
	};
}
