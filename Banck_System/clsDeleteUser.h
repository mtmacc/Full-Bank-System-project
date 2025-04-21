#pragma once
#include<iostream>
#include "clsUsers.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteUser :protected clsScreen
{
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
	static void DeleteUserScreen()
	{
		_DrawScreenHeader("\t    Delete User Screen");
		cout << "Enter User Name : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "Enter Valid User Name : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		cout << "Are You Sure You Want To Delete This User (Y/N) : ";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) != 'y')
		{
			return;
		}
		if (User.Delete())
		{
			cout << "User Deleted Successfully \n";
			_PrintUser(User);
		}
		else
		{
			cout<<"Error Deleting User \n";
		}
		
	}
};

