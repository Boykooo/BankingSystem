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
		void addClient(Client *newClient);
		int getClientAccountIndex(int clientIndex);
		int getClientIndex();
		bool canTrasfer(int clientIndex, int accNumber, double money);
		double takeMoney(int clientIndex, int accNumber, double money);
		void giveMoney(int clientIndex, int accNumber, double money);
		void showFullClientInfo(int clientIndex);
		void openMenu();


	private:
		void chooseClient();
		void newClient();
		void deleteClient();
		void replenishAccount(Client *client);
		double addMoneyToBank(double money);
		void addNewAccount(Client *client);

		std::string bankName;
		double bankAccount;
		double persent;
		std::vector<Client*> clientsList;
		int accountLength;
	};
}
