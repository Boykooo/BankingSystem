#pragma once

#include "Bank.h"

namespace BankingComponents {

	class Account
	{
	private:
		double money;
		string numberAccount;
		Bank* bank;
	public:
		Account(Bank* bank, string number);
		~Account();
		void addMoney(double money);
		void takeMoney(double money);
		double getMoney();
		string getNumberAccount();
	};
}
