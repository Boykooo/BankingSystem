#pragma once
using namespace BankingSystem;

namespace UI {

	class UIController
	{
	public:
		UIController();
		~UIController();
		void startUI();
	private:
		char* menu;
		int getCommand();
		BankingController bankingController;
	};
}

