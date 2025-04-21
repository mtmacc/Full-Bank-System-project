#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsUpdateCurrencyRate : protected clsScreen
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




public:
	static void UpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Rate Screen");
		cout << "Enter Currency Code :";
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Enter a Valid Code \n";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_Print(Currency);
		cout << "Are you sure you wante to update rate  y/n";
		char ans = 'n';
		cin >> ans;
		if (tolower(ans) != 'y') return;
		cout << "Enter New Rate ";
		float NewRate = clsInputValidate::ReadFloatNumber();
		Currency.UpdateRate(NewRate);
		cout << "\nCurrency Rate Updated Successfully :-)\n";
		_Print(Currency);
	}
};

