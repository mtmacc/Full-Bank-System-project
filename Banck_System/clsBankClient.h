#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsInputValidate.h"
#include"clsUtility.h"

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode ;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDeleted = false;


    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4],clsUtility::EncryptText(vClientData[5],1), stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        //stClientRecord += Client.PinCode + Seperator;
        stClientRecord += clsUtility::DecryptText(Client.PinCode,1) + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkForDeleted() == false)
                {
                    DataLine = _ConverClientObjectToLine(C);

                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
     void _Update()
    {
        vector <clsBankClient> Clients = _LoadClientsDataFromFile();
        for (clsBankClient &C : Clients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(Clients);
    }
     void _AddNewClient()
     {
         _AddDataLineToFile(_ConverClientObjectToLine(*this));
     }
public:
    struct stTrasLogData
    {
        string DateTime;
		string SenderAccountNumber;
		string ReceiverAccountNumber;
		double Amount;
        double SenderBalance;
		double ReceiverBalance;
        string UserName;
    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkForDeleted()
    {
        return _MarkForDeleted;
    }
    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                clsBankClient C = _ConvertLinetoClientObject(line);
                if (C.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return C;
                }
            }
        }
        return _GetEmptyClientObject();
    }
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return !Client.IsEmpty();
    }
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
            break;
        case clsBankClient::UpdateMode:
            _Update();
            return svSucceeded;
            break;
        case clsBankClient::AddNewMode:
            _AddNewClient();
            _Mode = enMode::UpdateMode;
            return svSucceeded;
            break;
        default:
            break;
        }
    }
    bool Delete()
    {
        vector<clsBankClient> Clients = _LoadClientsDataFromFile();
        for (clsBankClient& C : Clients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C._MarkForDeleted = true;
                break;
            }
        }
        _SaveCleintsDataToFile(Clients);
        *this = _GetEmptyClientObject();
        return true;
    }
    static clsBankClient GetNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
   }
    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }
    static float GetTotalBlance()
    {
        vector<clsBankClient> Clients = GetClientsList();
        float TotalBalance = 0;
        for (clsBankClient C : Clients)
        {
            TotalBalance += C.AccountBalance;
        }
        return TotalBalance;
    }
    bool Withdraw(float Amount)
    {
        vector<clsBankClient> Clients = _LoadClientsDataFromFile();
        for (clsBankClient& C : Clients)
        {
            if(C.AccountNumber() == AccountNumber())
			{
				if (C.AccountBalance >= Amount)
				{
					C._AccountBalance -= Amount;
                    *this = C;
                    _SaveCleintsDataToFile(Clients);
                    return true;
				}
			}
        }
        return false;
    }
    bool Deposit(double Amount)
	{
		vector<clsBankClient> Clients = _LoadClientsDataFromFile();
		for (clsBankClient& C : Clients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._AccountBalance += Amount;
                *this = C;
                _SaveCleintsDataToFile(Clients);
                return true;
            }
		}
        return false;
	}
     bool Transfer( clsBankClient & ToClient, float Amount)
	{
         if (Amount > AccountBalance)
		 {
			 return false;
		 }
         Withdraw(Amount);

         ToClient.Deposit(Amount);

		
        return true;
	}
     string PerepertTransferRecord(clsBankClient& FromClient, clsBankClient& ToClient, float Amount,string Separator = "#//#")
     {
         string record = "";
         record = clsDate::GetSystemDateTime() + Separator;
         record += FromClient.AccountNumber() + Separator;
		 record += ToClient.AccountNumber() + Separator;
		 record += to_string(Amount);
         record += to_string(FromClient.AccountBalance) + Separator;
         record += to_string(ToClient.AccountBalance) + Separator;
         record += CurrentUser.UserName;
		 return record;
     }
     static void TransferRecord(clsBankClient & FromClient, clsBankClient & ToClient, float Amount)
     {

    }
};

