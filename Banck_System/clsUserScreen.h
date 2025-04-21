#pragma once
#include <iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUsers.h"
#include"clsFindUser.h"
#include"clsAddNewUser.h"
#include"clsUserListScreen.h"
#include"clsDeleteUser.h"
#include"clsUpdateUsers.h"
using namespace std;

class clsUserScreen : protected clsScreen
{
public:
    enum enUsersMenuOptions { eListUsers = 1, eAddNewUser , eDeleteUser ,eEditUser, eFindUser, eMainMenue };

    // Static methods
    static short _ReadMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        return clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6?");
    }

    static void _BackToUserMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
		ShowUserScreen();
    }

    static void _AddNewUser()
    {
        //cout << "Add New user will be here...";
        clsAddNewUser::AddNewUserScreen();
    }

    static void _EditUser()
    {
        //cout << "Edit user will be here...";
        clsUpdateUsers::UpdateUsersScreen();
    }

    static void _DeleteUser()
    {
        //cout << "Delete user will be here...";
        clsDeleteUser::DeleteUserScreen();
    }

    static void _FindUser()
    {
        //cout << "Find user will be here...";
        clsFindUser::FindClientScreen();
    }

    static void _ListUsers()
    {
        //cout << "List users will be here...";
        clsListUsersScreen::ShowUsersList();
    }

    static void _BackToMainMenue()
    {

    }

    static void _PerformUserOption(enUsersMenuOptions UserOption)
    {
        switch (UserOption)
        {
        case clsUserScreen::eAddNewUser:
            system("cls");
            _AddNewUser();
            _BackToUserMenue();
            break;
        case clsUserScreen::eEditUser:
			system("cls");
            _EditUser();
            _BackToUserMenue();
            break;
        case clsUserScreen::eDeleteUser:
			system("cls");
            _DeleteUser();
            _BackToUserMenue();
            break;
        case clsUserScreen::eFindUser:
			system("cls");

            _FindUser();
            _BackToUserMenue();
            break;
        case clsUserScreen::eListUsers:
			system("cls");
            _ListUsers();
            _BackToUserMenue();
            break;
        case clsUserScreen::eMainMenue:
            break;
        default:
            break;
        }
    }
public:
    static void ShowUserScreen()
    {
        
        if (!CheckAccessRight(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t     Users Menue");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tUser Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show User List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Back to Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformUserOption((enUsersMenuOptions)_ReadMenuOption());
    }
};