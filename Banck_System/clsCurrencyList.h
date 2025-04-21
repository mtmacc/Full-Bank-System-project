#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyList :protected clsScreen
{
    private:
    static void TableData(clsCurrency Currencies)
    {

        cout << "| " << left << setw(35) << Currencies.Country();
        cout << "| " << left << setw(10) << Currencies.CurrencyCode();
        cout << "| " << left << setw(40) << Currencies.CurrencyName();
        cout << "| " << left << setw(10) << Currencies.Rate();
        cout << endl;
    }
public:
	static void ShowCurrenciesList()
	{
		vector<clsCurrency> Currencies = clsCurrency::GetCurrenciesList();
		string Title = "\t    Currency List Screen";
		string SubTitle = "\t    (" + to_string(Currencies.size()) + ") Currency(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n__________________________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(35) << "Country ";
		cout << "| " << left << setw(10) << "Code ";
		cout << "| " << left << setw(40) << "Name ";
		cout << "| " << left << setw(10) << "Rate (1$) ";
		cout << "\n__________________________________________________________________________________________________________________\n";
		if (Currencies.size() == 0)
		{
			cout << "\t\t\t\t\tNo Conntent in this File" << endl;
		}
		else
		{
			for (clsCurrency Currency : Currencies)
			{
				TableData(Currency);
			}
		}
	}
};

