#pragma once

#include <vector>
#include "Bank.h"
using namespace std;

namespace BankingSystem {
	class BankingController
	{
	public:
		BankingController();
		~BankingController();
		char* getMenu();
		void showBanksList();
	private:
		char* menu;
		vector<Bank> banksList;
		void openMenu();
		void chooseBank();
	};
}
																												   