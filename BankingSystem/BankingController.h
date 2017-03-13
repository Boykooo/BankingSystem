#pragma once

#include "Bank.h"
#include <vector>

using namespace std;
using namespace BankingComponents;

namespace BankingSystem {
	class BankingController
	{
	public:
		BankingController();
		~BankingController();
		void showBanksList();
	private:
		vector<Bank*> *banksList;
		void initBanks();
		void openMenu();
		void chooseBank();
		void newBank();
		void deleteBank();

		int getBankIndex();
	};
}
																												   