#pragma once

namespace BankingSystem {
	class Bank
	{
	public:
		Bank();
		~Bank();
		void showInfo();
		char* getName();
	private:
		char* bankName;
	};
}
