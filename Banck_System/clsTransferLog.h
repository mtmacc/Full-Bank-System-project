#pragma once
#include <iostream>
#include"global.h"
#include"clsBankClient.h"
#include"clsScreen.h"
class clsTransferLog :protected clsScreen
{
private:
   static string PerepertTransferRecord(clsBankClient& FromClient, clsBankClient& ToClient, float Amount, string Separator = "#//#")
    {
        string record = "";
        record = clsDate::GetSystemDateTime() + Separator;
        record += FromClient.AccountNumber() + Separator;
        record += ToClient.AccountNumber() + Separator;
        record += to_string(Amount) + Separator;
        record += to_string(FromClient.AccountBalance) + Separator;
        record += to_string(ToClient.AccountBalance) + Separator;
        record += CurrentUser.UserName;
        return record;
    }
  static clsBankClient::stTrasLogData DataLine(string line)
   {
       clsBankClient::stTrasLogData DataLine;
       vector<string> vLine = clsString::Split(line, "#//#");

	   DataLine.DateTime = vLine[0];
	   DataLine.SenderAccountNumber = vLine[1];
	   DataLine.ReceiverAccountNumber = vLine[2];
	   DataLine.Amount = stod(vLine[3]);
	   DataLine.SenderBalance = stod(vLine[4]);
	   DataLine.ReceiverBalance = stod(vLine[5]);
	   DataLine.UserName = vLine[6];
	   return DataLine;
   }
   static vector<clsBankClient::stTrasLogData> LoadTransferRecords()
   {
	   vector<clsBankClient::stTrasLogData> TransferRecords;
	   fstream MyFile;
	   MyFile.open("TransferRecords.txt", ios::in);
	   if (MyFile.is_open())
	   {
		   string Line = "";
		   while (getline(MyFile, Line))
		   {
			   TransferRecords.push_back(DataLine(Line));
		   }
		   MyFile.close();
	   }
	   return TransferRecords;
   }
   static void TableData(clsBankClient::stTrasLogData TransferRecords)
   {

       cout << "| " << left << setw(25) << TransferRecords.DateTime;
	   cout << "| " << left << setw(10) << TransferRecords.SenderAccountNumber;
	   cout << "| " << left << setw(10) << TransferRecords.ReceiverAccountNumber;
	   cout << "| " << left << setw(10) << TransferRecords.Amount;
	   cout << "| " << left << setw(15) << TransferRecords.SenderBalance;
	   cout << "| " << left << setw(15) << TransferRecords.ReceiverBalance;
	   cout << "| " << left << setw(10) << TransferRecords.UserName;

       cout << endl;
   }
public:
    static void RegisterLogIn(clsBankClient& FromClient, clsBankClient& ToClient, float Amount)
    {

        string DataLine = PerepertTransferRecord(FromClient,ToClient,Amount);

        fstream MyFile;
        MyFile.open("TransferRecords.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }
    }
    static void ShowTransferRecords()
	{
        vector<clsBankClient::stTrasLogData> TransferRecords = LoadTransferRecords();
        string Title = "\t    TransfreLogs Screen";
        string Subtitle ="\t    (" + to_string(TransferRecords.size()) + ") Transfer(s).";
        _DrawScreenHeader(Title, Subtitle);
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
        cout << "| " << left << setw(25) << "Date / Time ";
        cout << "| " << left << setw(10) << "Sender ";
        cout << "| " << left << setw(10) << "Receiver ";
        cout << "| " << left << setw(10) << "Amount ";
        cout << "| " << left << setw(15) << "Sender Balance ";
        cout << "| " << left << setw(15) << "Receiver Balance ";
		cout << "| " << left << setw(10) << "User Name ";
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
        if (TransferRecords.size() == 0)
        {
            cout << "\t\t\t\t\tNo Conntent in this File" << endl;
        }
        else
        {
            for (clsBankClient::stTrasLogData stData : TransferRecords)
            {
                TableData(stData);
            }
        }
        cout << "\n__________________________________________________________";
        cout << "____________________________________________________________\n" << endl;
    
	}
};

