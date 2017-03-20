#pragma once

#include "Bank.h"
#include <vector>

using namespace std;
using namespace BankingComponents;

namespace BankingSystem {

	struct BankTransfer
	{
		Bank * bank;
		int clientIndex;
		int accountIndex;
		bool status;
	};

	class BankingController
	{
	public:
		BankingController();
		~BankingController();
		void showBanksList();
	private:
		vector<Bank*> banksList;
		void initBanks();
		void showAllBanks();
		void chooseBank();
		void newBank();
		void deleteBank();
		void bankTrasfer();
		BankTransfer requestBankTrasfer();

		int getBankIndex();
	};
}
																												   