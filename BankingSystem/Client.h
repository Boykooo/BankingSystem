#pragma once

namespace BankingComponents {
	class Client
	{
	public:
		Client();
		~Client();
		void setName(char* newName);
		char* getName();
	private:
		char* userName;
	};
}