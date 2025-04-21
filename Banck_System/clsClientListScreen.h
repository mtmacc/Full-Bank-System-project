#pragma once
#include <iostream>
#include<iomanip>
#include "clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
protected:
    static void TableData(clsBankClient Clients)
    {

        cout << "| " << left << setw(15) << Clients.AccountNumber();
        cout << "| " << left << setw(10) << Clients.PinCode;
        cout << "| " << left << setw(30) << Clients.FullName();
        cout << "| " << left << setw(15) << Clients.Phone;
        cout << "| " << left << setw(25) << Clients.Email;
        cout << "| " << left << setw(15) << Clients.AccountBalance;
        cout << endl;

    }
public:
    static void ShowClientsList()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector<clsBankClient> Clients = clsBankClient::GetClientsList();
        string Title = "\t    Client list\n"; 
        string subtitle = "\t    (" + to_string(Clients.size()) + ") Client(s).";
		_DrawScreenHeader(Title,subtitle);
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
        cout << "| " << left << setw(15) << "Account Number ";
        cout << "| " << left << setw(10) << "pin code ";
        cout << "| " << left << setw(30) << "Client Name ";
        cout << "| " << left << setw(15) << "Phone ";
        cout << "| " << left << setw(25) << "Email ";
        cout << "| " << left << setw(15) << "Balance ";
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
        if (Clients.size() == 0)
        {
            cout << "\t\t\t\t\tNo Conntent in this File" << endl;
        }
        else
        {
            for (clsBankClient Client : Clients)
            {
                TableData(Client);
            }
        }
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
    }
};

