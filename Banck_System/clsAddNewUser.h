#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include"clsUsers.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewUser :protected clsScreen 
{
	static int _ReadPermission()
	{
		int permission = 0;
		cout << "you Wante to give all access to this user? (y/n) : ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission = clsUser::eAll;
		}
		else
		{
			cout << "Do you want to access to: \n";
			cout << "1-Show All Clients. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pListClients;
			}
			cout << "2-Add New Client. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pAddNewClient;
			}
			cout << "3-Update Client. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pUpdateClients;
			}
			cout << "4-Delete Client. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pDeleteClient;
			}
			cout << "5-Find Client. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pFindClient;
			}
			cout <<"6-Transactions. y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pTranactions;
			}
			cout << "7-Manage Users. y/n?";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pManageUsers;
			}
			cout << "8-Login History. y/n?";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += clsUser::pLoginRegister;
			}
		}
		return permission;
	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermission();
	}


	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void AddNewUserScreen()
	{

		_DrawScreenHeader("\t    Add New User");
		cout << "Enter Username: ";
		string username = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(username))
		{
			cout << "Enter Valid Username: ";
			username = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(username);
		_ReadUserInfo(User);
		clsUser::enSaveResults Save = User.Save();
		if (Save == clsUser::svSucceeded)
		{
			cout << "User Saved Successfully" << endl;
			_PrintUser(User);
		}
		else
		{
			cout << "Error Saving User" << endl;
		}
	}

};

