#pragma once
#include <string>

using namespace std;

namespace BankingComponents {
	class Client
	{
	public:
		Client();
		virtual ~Client();
		virtual string getName();
	};
}