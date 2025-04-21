#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsWithdraw :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWithdraw Screen");
		cout << "Enter Account Number :";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalid AccountNumber Enter A Valid one\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		cout << "Enter Withdraw Amount : ";
		double Amount = clsInputValidate::ReadDblNumber();
		while (Amount > Client.AccountBalance)
		{
			cout << "Invalid Amount Enter A Valid one\n";
			Amount = clsInputValidate::ReadDblNumber();
		}
		cout << "For Confirmation Enter Your Password : ";
		string Password = clsInputValidate::ReadString();
		while (Password != Client.PinCode)
		{
			cout << "Invalid Password Enter A Valid one\n";
			Password = clsInputValidate::ReadString();
		}
		if (Client.Withdraw(Amount))
		{
			cout << "Withdraw Successfly \n";
			_Print(Client);
		}
		else
		{
			cout << "Withdraw Failed \n";
		}
		

	}
};

