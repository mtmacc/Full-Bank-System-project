#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsAddNewClient :protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
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
    static void AddNewClient()
    {
        if (!CheckAccessRight(clsUser::pAddNewClient))
        {
            return;
        }
		_DrawScreenHeader("\t\tAdd New Client", "");
        cout << "Enter New AccountNumber :";
        string AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client Number is Exist, enter a new Number\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::GetNewClient(AccountNumber);
        _ReadClientInfo(Client);
        char choise = 'n';
        cout << "wante to confirm update ?";
        cin >> choise;
        if (tolower(choise) != 'y')
        {
            return;
        }
        clsBankClient::enSaveResults SaveResult = Client.Save();
        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
            break;
        case clsBankClient::svSucceeded:
            cout << "Client Added Succesfly" << endl;
            _Print(Client);
            break;
        case clsBankClient::svFaildAccountNumberExists:
            break;
        default:
            break;
        }
    }

};

