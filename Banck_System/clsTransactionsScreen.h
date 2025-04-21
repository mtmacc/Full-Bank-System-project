#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include"clsWithdraw.h"
#include"clsDeposit.h"
#include"clsTransfer.h"
#include"clsBalanceScreen.h"

using namespace std;
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enEnterType { enDeposit = 1, enWithdraw = 2, enTransfer = 3, enBalance = 4,enTansferLog = 5, enMain = 6 };


	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static  void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _DepositScreen()
	{
		clsDeposit::ShowDepositScreen();
		//cout << setw(37) << left << "" << "\n\tDeposit Screen will be here...\n";
	}
	static void _WithdrawScreen()
	{
		clsWithdraw::ShowWithdrawScreen();
		//cout << setw(37) << left << "" << "\n\tWithdraw Screen will be here...\n";
		
	}
	static void _TransferScreen()
	{
		//cout << setw(37) << left << "" << "\n\tTransfer Screen will be here...\n";
		clsTransfer::ShowTransferScreen();
	}
	static void _BalanceScreen()
	{
		clsBalanceScreen::ShowBalanceScreen();
		//cout << setw(37) << left << "" << "\n\tShow Balance Screen will be here...\n";
	}
	static void _BackToMainMenu()
	{
		
	}
	static void _TransferLogScreen()
	{
		clsTransferLog::ShowTransferRecords();
	}
	static void _PerformTransactionsOption(enEnterType option)
	{
		switch (option)
		{
		case enEnterType::enDeposit:
			system("cls");
			_DepositScreen();
			_GoBackToTransactionsMenue();

			break;
		case enEnterType::enWithdraw:
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case enEnterType::enTransfer:
			system("cls");
			_TransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case enEnterType::enBalance:
			system("cls");
			_BalanceScreen();
			_GoBackToTransactionsMenue();
			break;
			case enEnterType::enTansferLog:
			system("cls");
			_TransferLogScreen();
			_GoBackToTransactionsMenue();
		case enEnterType::enMain:
			_BackToMainMenu();
			
			break;
		default:
			break;
		}
	}

public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tTransactions Menue");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Transfer.\n";
		cout << setw(37) << left << "" << "\t[4] Show Balance.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Records.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		
		_PerformTransactionsOption((enEnterType)_ReadTransactionsMenueOption());
	}
	
};

