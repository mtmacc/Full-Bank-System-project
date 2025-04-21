#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsers.h"
using namespace std;
class clsFindUser :protected clsScreen
{
private:
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
	static void FindClientScreen()
	{
		_DrawScreenHeader("\t\tFind Client", "");

		cout << setw(37) << left << "" << "Enter Account Number: ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n\t\t\t\t\tClient Not Found!" << endl;
			cout << setw(37) << left << "" << "Enter Account Number: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);

		if (User.IsEmpty())
		{
			cout << "\n\t\t\t\t\tClient Not Found!" << endl;
		}
		else
		{
			_PrintUser(User);
			

		}
	}
};

