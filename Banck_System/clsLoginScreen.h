#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"
#include"clsMainScreen.h"
#include "global.h"
#include"clsLoginRegister.h"
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFiled = false;
		short loginTries = 3;
		string username , password;
		do {
			if (loginTries == 0)
			{
				cout << "\nYou have no more login tries";
				return false;
			}
			if (LoginFiled)
			{
				cout << "\nUsername or Password is wrong!";
				cout << "\nYou have " << loginTries << " tries left";
			}
			cout << "\nUsername: "; cin >> username;
			cout << "\nPassword: "; cin >> password;
			CurrentUser = clsUser::Find(username, password);
			LoginFiled = CurrentUser.IsEmpty();
			loginTries--;
		} while (LoginFiled);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}


};

