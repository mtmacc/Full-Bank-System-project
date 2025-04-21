#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsCurrencyList.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMainScreenOptions
	{
		enListCurrencyExchange = 1,
		enFindCurrencyExchange = 2,
		enUpdateCurrencyRate = 3,
		enCurrencyCalculator = 4,
		enBackToMainMenue = 5
	};
	static short _ReadCurrencyExchangeMainScreenOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _GoBackToCurrencyExchangeMainScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";

		system("pause>0");
		ShowCurrencyExchangeMainScreen();
	}
	static void ShowCurrencyExchangeListScreen() 
	{
		//cout << "Currency Exchange List Screen will be here...";
		clsCurrencyList::ShowCurrenciesList();
	}

	static void FindCurrencyExchangeScreen()
	{
		//cout << "Find Currency Exchange Screen will be here...";
		clsFindCurrency::FindCurrencyScreen();
	}
	static void UpdateCurrencyRateScreen()
	{
		//cout << "Update Currency Rate Screen will be here...";
		clsUpdateCurrencyRate::UpdateCurrencyScreen();
	}
	static void CurrencyCalculatorScreen()
	{
		//cout << "Currency Calculator Screen will be here...";
		clsCurrencyCalculatorScreen::CurrencyCalculatorScreen();
	}
	static void BackToMainMenueScreen()
	{

	}
	static void _PerformCurrencyExchangeMainScreenOption(enCurrencyExchangeMainScreenOptions Option)
	{
		switch (Option)
		{
		case enListCurrencyExchange:
			system("cls");
			ShowCurrencyExchangeListScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case enFindCurrencyExchange:
			system("cls");
			FindCurrencyExchangeScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case enUpdateCurrencyRate:
			system("cls");
			UpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case enCurrencyCalculator:
			system("cls");
			CurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case enBackToMainMenue:
			BackToMainMenueScreen();
			break;
		default:
			break;
		}
	}
	public:
		static void ShowCurrencyExchangeMainScreen()
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Exchange Main Screen", "");
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\tCurrency Exchange Main Screen\n\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Show Currency Exchange List.\n";
			cout << setw(37) << left << "" << "\t[2] Find Currency Exchange.\n";
			cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
			cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
			cout << setw(37) << left << "" << "\t[5] Back to Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";
			_PerformCurrencyExchangeMainScreenOption((enCurrencyExchangeMainScreenOptions)_ReadCurrencyExchangeMainScreenOption());


		}



};

