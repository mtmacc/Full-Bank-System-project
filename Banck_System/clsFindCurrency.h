#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsCurrency.h"
class clsFindCurrency :protected clsScreen
{
private:
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCurrency Country Name   : " << Currency.Country();
		cout << "\nCurrency Code           : " << Currency.CurrencyCode();
		cout << "\nCurrency Name           : " << Currency.CurrencyName();
		cout << "\nCurrency Rate           : " << Currency.Rate();
		cout << "\n___________________\n";
	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency Found\n";
			_Print(Currency);
		}
		else
		{
			cout << "Currency Not Found\n";
		}
	}
public:
	static void FindCurrencyScreen()
	{
		_DrawScreenHeader("\t    Find Currency Screen");
		cout << "Find by [1] Code or [2] Counter ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2?");
		if (Choice == 1)
		{
			cout << "Enter Currency Code : ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else {
			cout << "Enter Country Name : ";
			string CountryName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			_ShowResult(Currency);
		}
		
		
	}
};

