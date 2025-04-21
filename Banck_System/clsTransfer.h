#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include"clsTransferLog.h"
using namespace std;
class clsTransfer :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
	//static void _PrintReceiver(clsBankClient Client)
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFull Name   : " << Client.FullName();
	//	cout << "\nAcc. Number : " << Client.AccountNumber();
	//	cout << "\n___________________\n";
	//}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");
		cout << "Enter Your Account Number: ";
		string FromClientAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(FromClientAccountNumber))
		{
			cout << "Enter Valid Account Number: ";
			FromClientAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient FromClient = clsBankClient::Find(FromClientAccountNumber);
		_Print(FromClient);
		cout << " To Who You Want To Transfer : ";
		string ToClientAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(ToClientAccountNumber) || ToClientAccountNumber == FromClientAccountNumber)
		{
			cout << "Enter Valid Account Number: ";
			ToClientAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient ToClient = clsBankClient::Find(ToClientAccountNumber);
		_Print(ToClient);
		cout << "Enter Transfer Amount: ";
		double Amount = clsInputValidate::ReadDblNumber();
		while(Amount > FromClient.AccountBalance)
		{
			cout << "Invalid Amount Enter A Valid one\n";
			Amount = clsInputValidate::ReadDblNumber();
		}
		cout << "For Confirmation Enter Your Password : ";
		string Password = clsInputValidate::ReadString();
		while (Password != FromClient.PinCode)
		{
			cout << "Invalid Password Enter A Valid one\n";
			Password = clsInputValidate::ReadString();
		}
		if(FromClient.Transfer(ToClient, Amount))
		{
			cout << "Transfer Successfly \n";
			_Print(FromClient);
			_Print(ToClient);
			clsTransferLog::RegisterLogIn(FromClient, ToClient, Amount);
		}
		else
		{
			cout << "Transfer Failed \n";
		}
	}



};

