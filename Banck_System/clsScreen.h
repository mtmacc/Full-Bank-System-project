#pragma once
#include <iostream>
#include<iomanip>
#include <string>
#include "clsUsers.h"
#include"global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\t  User : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\t  Date : " << clsDate::DateToString(clsDate::GetSystemDate()) << "\n\n";

	}
   static bool CheckAccessRight(clsUser::enPermissions Permission)
    {
       if (!CurrentUser.CheckAccessPermission(Permission))
       {
           cout << "\t\t\t\t\t--------------------------------------------";
           cout << "\n\n\t\t\t\t\tYou Dont Have Access Right For This Task";
           cout << "\n\n\t\t\t\t\t--------------------------------------------";
           return false;
       }
       else
       {
           return true;
       }
    }
};

