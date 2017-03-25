#pragma once

namespace BankingComponents {
	class LegalPerson : public Client
	{
		string name;
		string iin;
		string type;
	public:
		LegalPerson(string name, string iin, string type);
		~LegalPerson();
		string getName();
		bool canTrasferToClient(ClientType clientType);

	};
}



