#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsFindCurrency.h"
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen: protected clsScreen
{
private:
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCurrency Country Name   : " << Currency.Country();
		cout << "\nCurrency Code           : " << Currency.CurrencyCode();
		cout << "\nCurrency Rate           : " << Currency.Rate();
		cout << "\n___________________\n";
	}
	static string _ReadCurrencyCode(string msg)
	{
		cout << msg << endl;
		string Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "invalid Code Enter New one :";
			Code = clsInputValidate::ReadString();
		}
		return Code;
	}

	float _ReadAmount()
	{

	}

public:
	static void CurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\t  Currency Calculator");
		//enum enTrans{enToUSD = 1, enFromUSD, enToAnother};
		string Currency1Code = _ReadCurrencyCode("Enter Currency [1] Code : ");
		string Currency2Code = _ReadCurrencyCode("Enter Currency [2] Code : ");
		float CalcResult = 0;
		while (Currency1Code == Currency2Code)
		{
			cout << "The selected currencies are the same. Please choose a different currency."<< endl;
			Currency2Code = _ReadCurrencyCode("Enter Currency [2] Code : ");
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);
		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);
		cout << "Enter Amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();
		if (Currency1.CurrencyCode() == "USD")
		{
			CalcResult = Currency2.CalcCurrencyFromUSD(Amount);
			_Print(Currency2);
		}
		else if (Currency2.CurrencyCode() == "USD")
		{
			CalcResult = Currency1.CalcCurrencyToUSD(Amount);
			_Print(Currency1);
		}
		else {
			CalcResult = Currency2.CalcCurrencyFromUSD(Currency1.CalcCurrencyToUSD(Amount));
			_Print(Currency1);
			_Print(Currency2);

		}

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << CalcResult<< " " << Currency2.CurrencyCode() << endl;
	}
};

