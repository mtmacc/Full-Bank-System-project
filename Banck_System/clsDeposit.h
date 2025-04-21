#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDeposit : protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");
		cout <<"Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Enter Valid Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		cout << "Enter Deposit Amount: ";
		double Amount = clsInputValidate::ReadDblNumber();
		cout << "For Confirmation Enter Your Password : ";
		string Password = clsInputValidate::ReadString();
		while (Password != Client.PinCode)
		{
			cout << "Invalid Password Enter A Valid one\n";
			Password = clsInputValidate::ReadString();
		}
		if (Client.Deposit(Amount))
		{
			cout<<"Deposit Successfly \n";
			_Print(Client);
		}
		else
		{
			cout << "Deposit Failed \n";
		}
		
		
	}

};

