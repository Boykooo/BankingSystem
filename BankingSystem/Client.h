#pragma once
#include "vector"


namespace BankingComponents {
	class Bank;
	class Account;

	class Client
	{
		std::vector<Account*> *accounts;
	public:
		Client();
		virtual ~Client();
		virtual std::string getName();


		bool canTransfer(int accountIndex, double money);
		int accountCount();
		void replenishAccount(int accountIndex, double money);
		void addNewAccount(Account *account);
		std::vector<Account*>* getAccounts();
	};
}

	