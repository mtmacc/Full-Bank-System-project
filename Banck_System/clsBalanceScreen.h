#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include<iomanip>
using namespace std;

class clsBalanceScreen : protected clsScreen
{
private:
	static void _TableData(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(30) << Client.FullName();
		cout << "| " << left << setw(15) << Client.AccountBalance;
		cout << endl;
	}

public:
	static void ShowBalanceScreen()
	{
		vector<clsBankClient> Clients = clsBankClient::GetClientsList();
		string Tiltle = "\t    Balance Screen";
		string SubTiltle = "\t    (" + to_string(Clients.size()) + ") Client(s).";
		_DrawScreenHeader(Tiltle, SubTiltle);
		cout << "______________________________________________________________\n";
		
		cout << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(30) << "Client Name ";
		cout << "| " << left << setw(15) << "Balance ";
		cout << "\n______________________________________________________________\n";
		if (Clients.size() == 0)
		{
			cout << "\t\t\t\t\tNo Conntent in this File" << endl;
		}
		else
		{
			for (clsBankClient Client : Clients)
			{
				_TableData(Client);
			}
		}
		cout << "______________________________________________________________\n";
		cout <<   "\t\t\t Total Balance: " << clsBankClient::GetTotalBlance() << "\n\n";
		cout << "\t\t      ( " << clsInputValidate::NumToStr(clsBankClient::GetTotalBlance())<< " )" << endl;
	}
		
};

