#pragma once

namespace BankingComponents {
	class PrivatePerson : public Client
	{
		string name;
		string surname;
		string lastName;
		string passport_id;
		string birthDate;
	public:
		PrivatePerson(string name, string surname, string lastName,
			string birthDate, string passport_id);
		~PrivatePerson();
		string getName();
		bool canTrasferToClient(ClientType clientType);
	};
}

