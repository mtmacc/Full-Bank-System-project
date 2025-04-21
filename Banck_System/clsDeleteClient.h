#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDeleteClient :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void DeleteClient()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\t\tDelete Client", "");
		cout << "Enter Account Number :";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalid AccountNumber Enter A Valid one\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		char choise = 'n';
		cout << "wante to confirm Delete [Y/N]?";
		cin >> choise;
		if (tolower(choise) != 'y')
		{
			return;
		}
		if (Client.Delete())
		{
			cout << "Client Deleted Successfly \n";
			_Print(Client);
		}
		else
		{
			cout << "Client Not Deleted \n";
		}
	}
};

