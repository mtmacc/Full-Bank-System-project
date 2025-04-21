#pragma once
#include <iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;
class clsFindClient : protected clsScreen
{
private:

	static void _TableData(clsBankClient Clients)
	{
		cout << "| " << left << setw(15) << Clients.AccountNumber();
		cout << "| " << left << setw(10) << Clients.PinCode;
		cout << "| " << left << setw(30) << Clients.FullName();
		cout << "| " << left << setw(15) << Clients.Phone;
		cout << "| " << left << setw(25) << Clients.Email;
		cout << "| " << left << setw(15) << Clients.AccountBalance;
		cout << endl;
	}
	static void _Print1(clsBankClient Client)
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
	static void _Print2(clsBankClient Client)
	{
		system("cls");
		cout << "\n\t\t\t\t\tClient Found!" << endl;
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(10) << "pin code ";
		cout << "| " << left << setw(30) << "Client Name ";
		cout << "| " << left << setw(15) << "Phone ";
		cout << "| " << left << setw(25) << "Email ";
		cout << "| " << left << setw(15) << "Balance ";
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;
		_TableData(Client);
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;
	}
public:
	static void FindClient()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\t\tFind Client", "");
		 
		cout << setw(37) << left << "" << "Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\tClient Not Found!" << endl;
			cout << setw(37) << left << "" << "Enter Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (Client.IsEmpty())
		{
			cout << "\n\t\t\t\t\tClient Not Found!" << endl;
		}
		else
		{
			_Print2(Client);
			_Print1(Client);
			
		}
	}


};

