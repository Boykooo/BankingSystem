#pragma once
#include "vector"
#include "ClientType.h"


namespace BankingComponents {
	class Bank;
	class Account;

	class Client
	{
	private:
		std::vector<Account*> accounts;
	protected:
		ClientType clientType;
	public:
		Client();
		virtual ~Client();
		virtual std::string getName();
		virtual bool canTrasferToClient(ClientType clientType);
		bool canTransfer(int accountIndex, double money);
		int accountCount();
		void replenishAccount(int accountIndex, double money);
		void addNewAccount(Account *account);
		std::vector<Account*> getAccounts();
		void addMoney(int accIndex, double money);
		void takeMoney(int accIndex, double money);
		ClientType getClientType();
	};
}

	